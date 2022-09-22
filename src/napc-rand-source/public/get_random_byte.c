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
#include <napc-rand-source/_private/_napc-rand-source.h>

static napc_u8 _random_byte = 0; // @static
static int _random_byte_pos = 0; // @static

bool napc_getRandomByte(napc_u8 *out) {
	// iterate through the various random bit sources
	const int *random_bit_sources = napc_getRandomBitSources();
	napc_size i = 0;

	while (true) {
		int random_bit_source = random_bit_sources[i];

		// reached end of array (of sources)
		if (random_bit_source == -1) break;

		// check if we need to get another bit
		if (_random_byte_pos == 8) break;

		// try to get a random bit
		bool random_bit;

		if (napc_getRandomBit(&random_bit, random_bit_source)) {
			// save random_bit in the byte
			_random_byte |= (random_bit << _random_byte_pos);

			++_random_byte_pos;
		}

		++i;
	}

	// did we collect an entire byte?
	if (_random_byte_pos == 8) {
		*out = _random_byte;

		_random_byte = 0;
		_random_byte_pos = 0;

		return true;
	}

	return false;
}
