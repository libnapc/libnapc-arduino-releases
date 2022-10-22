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
#include <module/sha/_private/_sha.h>

bool napc_sha_calculate(
	const void *buffer, napc_size buffer_size,
	char *out, napc_size out_size
) {
	if (!out || 64 >= out_size) {
		return false;
	}

	H5P9SL_SHA256_HASH digest;

	H5P9SL_Sha256Calculate(
		// buffer
		buffer, buffer_size,
		// output digest
		&digest
	);

	napc__Writer writer = napc_Writer_create(
		out, out_size
	);

	for (napc_size i = 0; i < 32; ++i) {
		napc_u8 byte = digest.bytes[i];

		bool result = napc_Writer_writeStringFormat(
			&writer, "%2.2x", byte
		);

		if (!result) return false;
	}

	// terminate output string
	if (!napc_Writer_writeChar(&writer, 0)) return false;

	return true;
}
