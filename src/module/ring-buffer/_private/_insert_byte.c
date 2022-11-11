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

bool PV_napc_RingBuffer_insertByte(
	napc__RingBuffer *ctx, napc_u8 byte, bool force
) {
	napc_size n_free_spots = PV_napc_RingBuffer_numFreeSpots(ctx);

	if (!force) {
		// no space available
		if (n_free_spots == 0) {
			return false;
		}

		// buffer will be full if only one element is free
		ctx->buffer_full = (n_free_spots == 1);
	} else {
		// buffer will be full if only one element is free, or no elements are available
		ctx->buffer_full = (n_free_spots == 1 || n_free_spots == 0);
	}

	napc_size new_write_position = (ctx->write_position + 1) % ctx->buffer_size;

	ctx->buffer[ctx->write_position] = byte;

	ctx->write_position = new_write_position;

	return true;
}
