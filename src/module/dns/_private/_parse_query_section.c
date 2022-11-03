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

bool PV_napc_DNS_parseQuerySection(
	napc__DNSQuery *out,
	napc__Reader *reader
) {
	NAPC_MAGIC_ASSERT(napc__Reader, reader);

	// Read question name (QNAME)
	int name_length = PV_napc_DNS_dn_expand(
		// start of buffer
		reader->data,
		// end of buffer
		napc_Reader_getEndAddress(reader),
		// pointer to ''compressed'' domain name
		napc_Reader_getCurrentAddress(reader),
		PV_napc_DNS_tmp_name,
		sizeof(PV_napc_DNS_tmp_name)
	);

	if (0 >= name_length) {
		PV_NAPC_DNS_ERROR("Invalid name_length %d.", name_length);

		return false;
	}

	// Advance reader by name_length bytes
	if (!napc_Reader_readU8Array(reader, name_length, NULL)) {
		return false;
	}

	napc_u16 qtype = 0;
	napc_u16 qclass = 0;

	// Read QType
	if (!napc_Reader_readU16BE(reader, &qtype)) {
		return false;
	}
	// Read QClass
	if (!napc_Reader_readU16BE(reader, &qclass)) {
		return false;
	}

	if (qclass != 1) {
		PV_NAPC_DNS_WARNING("Invalid QClass %d. (expected 1)", qclass);

		return false;
	}

	if (out) {
		out->qtype = qtype;
		napc_strncpy(out->name, PV_napc_DNS_tmp_name, sizeof(out->name));
	}

	return true;
}
