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
	extern "C" {
		#include <napc-core/_private/_napc-core.h>

		#ifdef __arm__
			// should use uinstd.h to define sbrk but Due causes a conflict
			extern "C" char* sbrk(int incr);
		#else  // __ARM__
			extern char *__brkval;
		#endif  // __arm__

		napc_size HAL_napc_getFreeMemory(void) {
			char top;
			#ifdef __arm__
				return &top - reinterpret_cast<char*>(sbrk(0));
			#elif defined(CORE_TEENSY) || (ARDUINO > 103 && ARDUINO != 151)
				return &top - __brkval;
			#else  // __arm__
				return __brkval ? &top - __brkval : &top - __malloc_heap_start;
			#endif  // __arm__
		}
	}
#endif
