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

bool napc_parser_parseKeyValue(
	const char *string,
	char *key, napc_size key_len,
	char *value, napc_size value_len
) {
	napc_size length = napc_strlen(string);

	if (!length) return false;

	// Flag (whether we are reading the key string or value string)
	bool readingKey = true;
	// Write position for key,value
	napc_size pos = 0;

	// Initialie key/value with zeros (safety precaution)
	if (key) napc_mzero(key, key_len);
	if (value) napc_mzero(value, value_len);

	for (napc_size i = 0; i < length; ++i) {
		char ch = string[i];

		// Check position index
		bool shouldWrite = false;

		// Position check for key
		if (readingKey) {
			shouldWrite = (key && key_len > pos);
		}
		// Position check for value
		else {
			shouldWrite = (value && value_len > pos);
		}

		// Reading key first
		if (readingKey) {
			// End of key
			if (ch == ',') {
				// Terminate key
				if (shouldWrite) key[pos] = 0;
				readingKey = false;
				// reset pos for value
				pos = 0;
			} else {
				// Only write to key if it is in the bounds
				if (shouldWrite) key[pos] = ch;
				++pos;
			}
		} else {
			// Only write to value if it is in the bounds
			if (shouldWrite) value[pos] = ch;
			++pos;
		}
	}

	// Handle strings without comma-separator
	// After the loop we shouldn't be in the reading key phase anymore
	if (readingKey) return false;

	// Make sure key and value are *always* terminated
	if (key) key[key_len - 1] = 0;
	if (value) value[value_len - 1] = 0;

	return true;
}
