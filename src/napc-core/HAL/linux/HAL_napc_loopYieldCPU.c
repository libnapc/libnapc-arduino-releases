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
#if !defined(ARDUINO)
	#include <napc-core/_private/_napc-core.h>
	#include <napc-serial/napc-serial.h> // napc_printf()

	#include <stdio.h> // sscanf()
	#include <string.h> // strlen()

	static napc_time current_delay = 0;

	static napc_time getLoopDelay(void) {
		// it's likely that the current_delay has already been calculated
		if (NAPC_LIKELY(current_delay > 0)) {
			return current_delay;
		}

		napc_time delay_value_in_us = 5000; // 5000us is 5ms
		napc_time delay_multiplier = 1;
		unsigned mult = 1;

		const char *delay_value = getenv("NAPC_LOOP_DELAY");

		if (delay_value && strlen(delay_value) >= 1) {
			const char suffix = delay_value[strlen(delay_value) - 1];

			// m = milliseconds
			if (suffix == 'm') {
				mult = 1000;
			}
			// u = microseconds
			else if (suffix == 'u') {
				mult = 1;
			}
			// warn on suffix that is not 0-9
			else if (suffix > '9' || '0' > suffix) {
				napc_printf("HAL_napc_loopYieldCPU (linux) invalid suffix '%c'\n", suffix);
			}

			unsigned val = 0;

			if (sscanf(delay_value, "%u", &val) == 1) {
				// only take multiplier when val is correct
				if (val != 0) {
					delay_value_in_us = (napc_time)val;
					delay_multiplier = (napc_time)mult;
				} else {
					napc_printf(
						"HAL_napc_loopYieldCPU (linux) delay cannot be zero.\n"
					);
				}
			} else {
				napc_printf(
					"HAL_napc_loopYieldCPU (linux) failed to parse 'NAPC_LOOP_DELAY'='%s'\n",
					delay_value
				);
			}
		}

		current_delay = delay_value_in_us * delay_multiplier;

		napc_printf("HAL_napc_loopYieldCPU (linux) using delay = %u microseconds\n", current_delay);

		return current_delay;
	}

	void HAL_napc_loopYieldCPU(bool dry_run) {
		napc_time delay_value_in_us = getLoopDelay();

		// it's likely that the function wasn't called as a dry run
		if (NAPC_LIKELY(!dry_run)) {
			napc_delayUs(delay_value_in_us);
		}
	}
#endif
