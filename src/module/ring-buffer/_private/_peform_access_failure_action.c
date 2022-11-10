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

void PV_napc_RingBuffer_performAccessFailureAction(
	const napc__RingBuffer *ctx, int cause
) {
	if (cause == 0) {

		if (ctx->_fail_mode == NAPC_ACCESS_FAILURE_MODE_LOG) {
			PV_NAPC_RINGBUFFER_ERROR(
				"Refusing to read byte from empty buffer"
				" (write_position=%" NAPC_SIZE_PRINTF ",read_position=%" NAPC_SIZE_PRINTF ",size=%" NAPC_SIZE_PRINTF ")",
				ctx->write_position,
				ctx->read_position,
				ctx->buffer_size
			);
		} else if (NAPC_UNLIKELY(ctx->_fail_mode == NAPC_ACCESS_FAILURE_MODE_PANIC)) {
			NAPC_PANIC(
				"Read operation failed and fail mode is set to NAPC_ACCESS_FAILURE_MODE_PANIC."
			);
		}

	} else if (cause == 1) {

		if (ctx->_fail_mode == NAPC_ACCESS_FAILURE_MODE_LOG) {
			PV_NAPC_RINGBUFFER_ERROR(
				"Refusing to insert byte into full buffer"
				" (write_position=%" NAPC_SIZE_PRINTF ",read_position=%" NAPC_SIZE_PRINTF ",size=%" NAPC_SIZE_PRINTF ")",
				ctx->write_position,
				ctx->read_position,
				ctx->buffer_size
			);
		} else if (NAPC_UNLIKELY(ctx->_fail_mode == NAPC_ACCESS_FAILURE_MODE_PANIC)) {
			NAPC_PANIC(
				"Insert operation failed and fail mode is set to NAPC_ACCESS_FAILURE_MODE_PANIC."
			);
		}

	}
}
