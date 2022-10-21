/*
* MIT License
* 
* Copyright (c) 2022 nap.software
* 
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
* 
* The above copyright notice and this permission notice shall be included in all
* copies or substantial portions of the Software.
* 
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
*/
#include <module/dns/_private/_dns.h>

bool napc_DNS_parseResponse(
	napc__DNSResponse *out,
	const void *buffer, napc_size buffer_size
) {
	napc__DNSHeader header;

	if (!napc_DNS_parseHeader(&header, buffer, buffer_size)) {
		return false;
	}

	napc__Reader reader;
	napc_Reader_init(&reader, buffer, buffer_size);

	// skip DNS header we just read
	if (!napc_Reader_readU8Array(&reader, 12, NULL)) return false;

	if (!header.answer_count) {
		PV_NAPC_DNS_ERROR("Response contains no answer.");

		return false;
	} else if (header.question_count != 1) {
		PV_NAPC_DNS_WARNING(
			"Response contains other than 1 question (%d questions).",
			header.question_count
		);

		return false;
	}

	// Skip question/query section
	if (!PV_napc_DNS_parseQuerySection(NULL, &reader)) return false;

	napc_size n_answers = header.answer_count;

	// cap max. answers
	if (n_answers > NAPC_MODULE_DNS_MAX_ANSWERS) {
		PV_NAPC_DNS_INFO(
			"Response contains more than "
			"%d answers (%" NAPC_SIZE_PRINTF " answers).",
			NAPC_MODULE_DNS_MAX_ANSWERS,
			n_answers
		);

		n_answers = NAPC_MODULE_DNS_MAX_ANSWERS;
	}

	for (napc_size i = 0; i < n_answers; ++i) {
		napc__DNSAnswer *a = out ? &out->answers[i] : NULL;

		if (!PV_napc_DNS_parseAnswerSection(a, &reader)) {
			return false;
		}
	}

	if (out) {
		out->num_answers = n_answers;

		memcpy(&out->header, &header, sizeof(header));
	}

	return true;
}
