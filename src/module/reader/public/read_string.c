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
#include <module/reader/_private/_reader.h>

bool napc_Reader_readString(
	napc__Reader *ctx,
	napc_size str_len,
	char *out,
	napc_size out_size
) {
	if (out && !out_size) {
		NAPC_PANIC(
			"out_size cannot be zero inside napc_Reader_readString()."
		);
	}

	if (!PV_napc_Reader_checkAccess(ctx, str_len, "string")) {
		return false;
	} else if (((str_len + 1) > out_size) && out) {
		PV_NAPC_READER_ERROR("Reading string would overflow buffer.");

		return false;
	}

	if (out) {
		const char *data = ctx->data;

		for (napc_size i = 0; i < str_len; ++i) {
			out[i] = data[ctx->_offset + i];
		}
		// Terminate string
		out[str_len] = 0;
		// Always make sure string is terminated
		out[out_size - 1] = 0;
	}

	ctx->_offset += str_len;

	return true;
}
