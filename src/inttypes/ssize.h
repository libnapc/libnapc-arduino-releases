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
#if !defined(NAPC_INTTYPES_SSIZE_h)
	#define NAPC_INTTYPES_SSIZE_h

	/*!
	 * @name napc_ssize
	 * @brief Signed memory size type.
	 * @version 1.0.0
	 * @description
	 * Signed integer type for holding object sizes.
	 * @rationale
	 * Used because Arduino lacks `ssize_t` in `<stddef.h>`.
	 * For some reason it is defined in `<stdio.h>` but
	 * I don't want to pollute my headers with unnecessary
	 * includes. Also this way, I'm sure what printf specifiers
	 * to use when printing `size_t` resp. `ssize_t`.
	 * (`%zu` is not supported in arduino's libc)
	 * @changelog 1.0.0 17.02.2022 initial version
	 */
	typedef signed long napc_ssize;

	// For napc_ssize literals
	#define NAPC_SSIZE_LITERAL(_v) _v ## l

	/*!
	 * @name NAPC_SSIZE_PRINTF
	 * @version 1.0.0
	 * @description
	 * Format specifier for printing `napc_ssize` variables.
	 * @changelog 1.0.0 17.02.2022 initial version
	 * @example
	 * napc_ssize var = -1;
	 * 
	 * napc_printf("var is = %" NAPC_SSIZE_PRINTF, var);
	 */
	#define NAPC_SSIZE_PRINTF "ld"
#endif
