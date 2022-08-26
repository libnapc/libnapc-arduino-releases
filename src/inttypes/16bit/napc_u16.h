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
#if !defined(NAPC_INTTYPES_U16_h)
	#define NAPC_INTTYPES_U16_h

	#include <stdint.h> // uint16_t
	#include <inttypes.h> // PRIu16

	/*!
	 * @name napc_u16
	 * @brief 16 bit wide unsigned integer 
	 * @version 1.0.0
	 * @description
	 * Type for unsigned integers with 16 bits width.
	 * @changelog 1.0.0 17.02.2022 initial version
	 */
	typedef uint16_t napc_u16;

	/*!
	 * @name NAPC_U16_LITERAL
	 * @version 1.0.0
	 * @description
	 * Used for literal unsigned integers with 16 bits width.
	 * @param n/a value Value
	 * @rationale
	 * This macro is only included for consistency's sake.
	 * @changelog 1.0.0 17.02.2022 initial version
	 * @example
	 * napc_u16 var = NAPC_U16_LITERAL(1234);
	 */
	#define NAPC_U16_LITERAL(value) UINT16_C(value)

	/*!
	 * @name NAPC_U16_PRINTF
	 * @version 1.0.0
	 * @description
	 * Format specifier for printing `napc_u16` variables.
	 * @rationale
	 * This macro is only included for consistency's sake.
	 * @changelog 1.0.0 17.02.2022 initial version
	 * @example
	 * napc_u16 var = 1;
	 * 
	 * napc_printf("var is = %" NAPC_U16_PRINTF, var);
	 */
	#define NAPC_U16_PRINTF      PRIu16
#endif
