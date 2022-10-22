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
#include <module/aes/_private/_aes.h>

bool napc_aes_decrypt(
	const napc_u8 *iv,
	const char *key,
	void *buffer, napc_size buffer_size
) {
	struct TinyAES_ctx ctx;
	napc_u8 key_bytes[32];

	if ((buffer_size % 16) != 0) {
		NAPC_PANIC("buffer size must be a multiple of 16 bytes.");
	}

	if (
		!napc_parser_parseHexString(key, sizeof(key_bytes), key_bytes)
	) {
		napc_mzero(key_bytes, sizeof(key_bytes));

		return false;
	}

	TinyAES_init_ctx_iv(&ctx, key_bytes, iv);

	TinyAES_CBC_decrypt_buffer(&ctx, buffer, buffer_size);
	napc_mzero(key_bytes, sizeof(key_bytes));
	napc_mzero(&ctx, sizeof(ctx));

	return true;
}
