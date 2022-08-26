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
/*!
 * @name hmac:intro
 * @brief Sign & verify messages
 */
#if !defined(NAPC_MODULE_HMAC_h)
	#define NAPC_MODULE_HMAC_h

	#include <libnapc.h>

	/*!
	 * @name napc_hmac_calculate
	 * @brief Calculate HMAC of a message.
	 * @version 1.0.0
	 * @description
	 * Calculate the SHA-256 HMAC signature of a message.
	 * @param out Pointer to store resulting HMAC (32 bytes)
	 * @param key Key to be used.
	 * @param buffer Buffer containing the message.
	 * @param buffer_size Size of buffer.
	 * @changelog 1.0.0 17.02.2022 initial version
	 */
	void napc_hmac_calculate(
		napc_u8 *out,
		const char *key,
		const void *buffer, napc_size buffer_size
	);

	/*!
	 * @name napc_hmac_verify
	 * @brief Verify a message with HMAC.
	 * @version 1.0.0
	 * @description
	 * Verify a message.
	 * @param key Key to be used.
	 * @param hmac Pointer to HMAC (32 bytes)
	 * @param buffer Buffer containing the message.
	 * @param buffer_size Size of buffer.
	 * @return Returns `true` if the message matches the `hmac` signature.
	 * @changelog 1.0.0 17.02.2022 initial version
	 */
	bool napc_hmac_verify(
		const char *key, const napc_u8 *hmac,
		const void *buffer, napc_size buffer_size
	) NAPC_FN_WARNUNUSED_RET();
#endif
