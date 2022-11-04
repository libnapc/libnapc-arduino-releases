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
#if !defined(NAPC_MODULE_SHA_h)
	#define NAPC_MODULE_SHA_h

	#include <libnapc.h>

	/*!
	 * @name napc_sha_calculate
	 * @brief Calculate SHA256 hash.
	 * @version 1.5.0
	 * @description
	 * Calculates the SHA-256 hash of a message.
	 * @param buffer Buffer to calculate hash of.
	 * @param buffer_size Size of buffer.
	 * @param out Array to store output in HEX format (32 bytes).
	 * @param out_size Size of output array.
	 * @warning The output array must have at least 65 elements.
	 * @changelog 1.5.0 25.03.2022 initial version
	 * @example
	 * char out[65];
	 * const char *str = "secret";
	 * 
	 * napc_sha_calculate(str, napc_strlen(str), out, sizeof(out));
	 * 
	 * napc_printf("SHA256-hash of '%s' is '%s'\n");
	 */
	bool napc_sha_calculate(
		const void *buffer, napc_size buffer_size,
		char *out, napc_size out_size
	) NAPC_FN_WARNUNUSED_RET();
#endif
