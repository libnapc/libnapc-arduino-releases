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

bool napc_parser_parseIPv4Address(
	const char *string,
	napc_u8 *out
) {
	// Check occurrences of .
	if (PV_napc_parser_countOccurrences(string, '.') != 3) {
		return false;
	}

	// Max-length of a valid IPv4-Address is 15:
	// napc_strlen("255.255.255.255") == 15
	if (napc_strlen(string) > 32) return false;

	char copy[32];
	napc_strncpy(copy, string, sizeof(copy));

	char *saveptr;
	char *octet = strtok_r(copy, ".", &saveptr);
	int i = 0;

	while (octet) {
		// Octet is too long (max. 3 characters)
		if (napc_strlen(octet) > 3) {
			return false;
		}

		// Parse octet
		napc_u32 value;

		if (!PV_napc_parser_parseIntegerString(octet, &value, false)) {
			return false;
		}

		// Out of range
		if (value > 255) return false;

		if (out) {
			out[i] = value;
			++i;
		}

		octet = strtok_r(NULL, ".", &saveptr);
	}

	return true;
}
