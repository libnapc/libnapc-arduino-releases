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
#if defined(ARDUINO)
	#include <Arduino.h> // Ax, pinMode(), micros()

	extern "C" {
		#include <napc-rand-source/_private/_napc-rand-source.h>
		#include <napc-panic/napc-panic.h> // NAPC_PANIC()

		static unsigned long _timestamp[7]; // @static
		static napc_u32 _state[7]; // @static
		static bool _first_bit[7]; // @static
		static int _pin_mapping[7] = {A0, A1, A2, A3, A4, A5, A6}; // @static

		bool PVHAL_arduino_napc_initRandom(void) {
			for (napc_size i = 0; i < NAPC_ARRAY_ELEMENTS(_pin_mapping); ++i) {
				_timestamp[i] = 0;
				_state[i] = 0;
				_first_bit[i] = false;

				pinMode(_pin_mapping[i], INPUT);
			}
		}

		static bool _readBitFromPin(int source) {
			if (source > 7 || 0 > source) {
				NAPC_PANIC("Invalid source identifier.");
			}

			return !!(analogRead(_pin_mapping[source]) & 0x01u);
		}

		/*
		while (have less than 8 bits stored)  
			bit1 := LSB of analogRead()
			wait for an arbitrary amount of time

			bit2 := LSB of analogRead()

			if bit1 != bit2
				store bit1

			wait for an arbitrary amount of time
		*/
		bool HAL_napc_getRandomBit(bool *out, int source) {
			switch (_state[source]) {
				// Initial state, first call
				case 0: {
					_timestamp[source] = micros();
					_first_bit[source] = _readBitFromPin(source);
					_state[source] = 1;
				} break;

				case 1: {
					unsigned long delta = micros() - _timestamp[source];

					// did 256us pass?
					if (delta >= 256) {
						_timestamp[source] = micros();
						_state[source] = 2;

						if (_first_bit[source] != _readBitFromPin(source)) {
							*out = _first_bit[source];
							return true;
						}
					}
				} break;

				// pause state
				case 2: {
					unsigned long delta = micros() - _timestamp[source];

					// did 64us pass?
					if (delta >= 64) {
						_state[source] = 0;
					}
				} break;
			}

			return false;
		}
	}
#endif
