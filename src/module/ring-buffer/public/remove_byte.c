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

bool napc_RingBuffer_removeByte(napc__RingBuffer *ctx, napc_u8 *out) {
	NAPC_MAGIC_ASSERT(napc__RingBuffer, ctx);

	napc_size n_free_spots = PV_napc_RingBuffer_numFreeSpots(ctx);

	if (n_free_spots == ctx->buffer_size) {
		PV_napc_RingBuffer_performAccessFailureAction(
			ctx,
			PV_NAPC_MODULE_RINGBUFFER_ACTION_READ_BYTE
		);

		return false;
	}

	if (out) {
		*out = ctx->buffer[ctx->read_position];
	}

	napc_size new_read_position = (ctx->read_position + 1) % ctx->buffer_size;

	ctx->read_position = new_read_position;

	// buffer will not be full again after a read operation
	ctx->buffer_full = false;

	return true;
}
