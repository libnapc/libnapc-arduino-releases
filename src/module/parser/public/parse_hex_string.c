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
#include <module/parser/_private/_parser.h>

bool napc_parser_parseHexString(
	const char *string,
	napc_size n_bytes,
	napc_u8 *out
) {
	if (napc_strlen(string) != (n_bytes * 2)) {
		return false;
	}

	napc_size out_index = 0;

	for (napc_size i = 0; i < n_bytes; ++i) {
		char tmp_str[3] = {0,0,0};

		napc_size first_index = i * 2;
		napc_size second_index = first_index + 1;

		tmp_str[0] = string[first_index];
		tmp_str[1] = string[second_index];

		napc_u8 value = 0;

		bool result = napc_parser_parseHexadecimalNumberU8(tmp_str, &value);

		// wipe memory
		tmp_str[0] = 0;
		tmp_str[1] = 0;

		if (!result) return false;

		if (out) {
			out[out_index] = value;
			++out_index;
			// wipe memory
			value = 0;
		}
	}

	return true;
}
