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
#if !defined(NAPC_MODULE_PARSER_HEXADECIMAL_NUMBER_h)
	#define NAPC_MODULE_PARSER_HEXADECIMAL_NUMBER_h

	#include <libnapc.h>

	/*!
	 * @name napc_parser_parseHexadecimalNumberU8
	 * @brief Parse a decimal number from string.
	 * @version 1.0.0
	 * @description
	 * Parse a string containing a hexadecimal number.
	 * @param string String to be parsed.
	 * @param out Pointer to store the parsed number. (optional)
	 * @return Returns `true` on success, `false` otherwise.
	 * @changelog 1.0.0 17.02.2022 initial version
	 * @example
	 * napc_u8 out;
	 * 
	 * if (napc_parser_parseHexadecimalNumberU8("ef", &out)) {
	 *     napc_printf("Value is %ld", out); // "Value is 239"
	 * }
	 */
	bool napc_parser_parseHexadecimalNumberU8(
		const char *string,
		napc_u8 *out
	) NAPC_FN_WARNUNUSED_RET();

	/*!
	 * @name napc_parser_parseHexadecimalNumberU16
	 * @brief Parse a decimal number from string.
	 * @version 1.0.0
	 * @description
	 * Parse a string containing a hexadecimal number.
	 * @param string String to be parsed.
	 * @param out Pointer to store the parsed number. (optional)
	 * @return Returns `true` on success, `false` otherwise.
	 * @changelog 1.0.0 17.02.2022 initial version
	 * @example
	 * napc_u16 out;
	 * 
	 * if (napc_parser_parseHexadecimalNumberU16("beef", &out)) {
	 *     napc_printf("Value is %ld", out); // "Value is 48879"
	 * }
	 */
	bool napc_parser_parseHexadecimalNumberU16(
		const char *string,
		napc_u16 *out
	) NAPC_FN_WARNUNUSED_RET();

	/*!
	 * @name napc_parser_parseHexadecimalNumberU32
	 * @brief Parse a decimal number from string.
	 * @version 1.0.0
	 * @description
	 * Parse a string containing a hexadecimal number.
	 * @param string String to be parsed.
	 * @param out Pointer to store the parsed number. (optional)
	 * @return Returns `true` on success, `false` otherwise.
	 * @changelog 1.0.0 17.02.2022 initial version
	 * @example
	 * napc_u32 out;
	 * 
	 * if (napc_parser_parseHexadecimalNumberU32("deadbeef", &out)) {
	 *     napc_printf("Value is %ld", out); // "Value is 3735928559"
	 * }
	 */
	bool napc_parser_parseHexadecimalNumberU32(
		const char *string,
		napc_u32 *out
	) NAPC_FN_WARNUNUSED_RET();
#endif
