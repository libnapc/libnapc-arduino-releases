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
#if !defined(NAPC_TIME_h)
	#define NAPC_TIME_h

	#include <libnapc.h>

	/*!
	 * @name napc_getTimeSinceBoot
	 * @brief Get time since boot.
	 * @version 1.0.0
	 * @description
	 * Return number of milliseconds that have passed since boot.
	 * @warning
	 * The value returned by this function will overflow at some point in time.
	 * @flags hw
	 * @changelog 1.0.0 17.02.2022 initial version
	 */
	napc_time napc_getTimeSinceBoot(void) NAPC_FN_WARNUNUSED_RET();

	/*!
	 * @name napc_getTimeSinceBootHR
	 * @brief Get time since boot in microseconds.
	 * @version 2.0.0
	 * @description
	 * Return number of microseconds that have passed since boot.
	 * @warning
	 * The value returned by this function will overflow at some point in time.
	 * @flags hw
	 * @changelog 2.0.0 21.10.2022 initial version
	 */
	napc_time napc_getTimeSinceBootHR(void) NAPC_FN_WARNUNUSED_RET();
#endif
