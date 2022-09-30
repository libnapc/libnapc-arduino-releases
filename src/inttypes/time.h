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
#if !defined(NAPC_INTTYPES_TIME_h)
	#define NAPC_INTTYPES_TIME_h

	#include <inttypes/32bit/napc_u32.h>

	/*!
	 * @name napc_time
	 * @brief Unsigned timestamp int type.
	 * @version 1.0.0
	 * @description
	 * Unsigned integer type for holding timestamps.
	 * @changelog 1.0.0 17.02.2022 initial version
	 */
	typedef napc_u32 napc_time;

	// For napc_time literals
	#define NAPC_TIME_LITERAL(_v) NAPC_U32_LITERAL(_v)

	/*!
	 * @name NAPC_TIME_PRINTF
	 * @module Core
	 * @version 1.0.0
	 * @description
	 * Format specifier for printing `napc_time` variables.
	 * @changelog 1.0.0 17.02.2022 initial version
	 * @example
	 * napc_time var = 1;
	 * 
	 * napc_printf("var is = %" NAPC_TIME_PRINTF, var);
	 */
	#define NAPC_TIME_PRINTF PRIu32
#endif
