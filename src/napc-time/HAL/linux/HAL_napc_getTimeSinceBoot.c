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
	#include <napc-time/_private/_napc_time.h>
	#include <time.h> // struct timespec, clock_gettime()

	extern struct timespec PV_napc_program_start_linux; // @global

	napc_time HAL_napc_getTimeSinceBoot(void) {
		struct timespec now;

		clock_gettime(CLOCK_MONOTONIC_RAW, &now);

		long delta_seconds = (now.tv_sec - PV_napc_program_start_linux.tv_sec);
		long delta_nseconds = (now.tv_nsec - PV_napc_program_start_linux.tv_nsec);

		long delta = 0;

		delta += (delta_seconds * 1000); // 1sec = 1000ms
		delta += (delta_nseconds / 1000000); // 1000000ns = 1ms

		return (napc_time)delta;
	}
#endif
