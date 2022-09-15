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
#if !defined(TINYAES_H)
	#define TINYAES_H

	#include <stdint.h>
	#include <stddef.h>

	struct TinyAES_ctx {
		uint8_t RoundKey[240];
		uint8_t Iv[16];
	};

	void TinyAES_init_ctx(struct TinyAES_ctx* ctx, const uint8_t* key);

	void TinyAES_init_ctx_iv(struct TinyAES_ctx* ctx, const uint8_t* key, const uint8_t* iv);
	void TinyAES_ctx_set_iv(struct TinyAES_ctx* ctx, const uint8_t* iv);

	void TinyAES_CBC_encrypt_buffer(struct TinyAES_ctx* ctx, uint8_t* buf, size_t length);
	void TinyAES_CBC_decrypt_buffer(struct TinyAES_ctx* ctx, uint8_t* buf, size_t length);
#endif
