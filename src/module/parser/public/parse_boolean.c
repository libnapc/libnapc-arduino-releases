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

bool napc_parser_parseBoolean(
	const char *string,
	bool *out
) {
	napc_size length = napc_strlen(string);

	if (!length) return false;

	bool value = false;

	if (napc_streqli("yes", string)) {
		value = true;
	} else if (napc_streqli("true", string)) {
		value = true;
	} else if (napc_streqli("1", string)) {
		value = true;
	} else if (napc_streqli("no", string)) {
	} else if (napc_streqli("false", string)) {
	} else if (napc_streqli("0", string)) {
	} else {
		return false;
	}

	if (out) {
		*out = value;
	}

	return true;
}
