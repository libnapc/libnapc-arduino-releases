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

static int _parseDigit(char ch, bool allowHexDigits) {
	int digit = ch - '0';

	// 'ch' is between 0 and 9
	if (9 >= digit && digit >= 0) return digit;

	// done here
	if (!allowHexDigits) return -1;

	if (ch == 'a' || ch == 'A') return 10;
	if (ch == 'b' || ch == 'B') return 11;
	if (ch == 'c' || ch == 'C') return 12;
	if (ch == 'd' || ch == 'D') return 13;
	if (ch == 'e' || ch == 'E') return 14;
	if (ch == 'f' || ch == 'F') return 15;

	return -1;
}

bool PV_napc_parser_parseIntegerString(
	const char *string,
	napc_u32 *out,
	bool isHex
) {
	napc_size length = napc_strlen(string);

	if (!length) return false;

	napc_u32 value = 0;
	napc_u32 multiplier = 1;

	for (int i = length - 1; i >= 0; --i) {
		int digit = _parseDigit(string[i], isHex);

		if (0 > digit) return false;

		value += (digit * multiplier);
		multiplier *= (isHex ? 16 : 10);
	}

	if (out) {
		*out = value;
	}

	return true;
}
