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
#include <module/ring-buffer/_private/_ring-buffer.h>

bool napc_RingBuffer_removeBytes(napc__RingBuffer *ctx, napc_u8 *out, napc_size out_size) {
	NAPC_MAGIC_ASSERT(napc__RingBuffer, ctx);

	napc_size elements_available = napc_RingBuffer_getAvailableBytes(ctx);

	if (out_size > elements_available) {
		PV_napc_RingBuffer_performAccessFailureAction(
			ctx,
			PV_NAPC_MODULE_RINGBUFFER_ACTION_READ_BYTES
		);

		return false;
	}

	for (napc_size i = 0; i < out_size; ++i) {
		// allow 'out' to be NULL, this discards the bytes
		napc_u8 *ptr = out ? &out[i] : NULL;

		// this will never be true, hopefully
		if (NAPC_UNLIKELY(!napc_RingBuffer_removeByte(ctx, ptr))) {
			return false;
		}
	}

	return true;
}
