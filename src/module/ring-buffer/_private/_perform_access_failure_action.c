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
	const napc__RingBuffer *ctx, int performed_action
) {
	// do nothing
	if (ctx->_fail_mode == NAPC_ACCESS_FAILURE_MODE_NONE) {
		return;
	}

	bool do_panic = ctx->_fail_mode == NAPC_ACCESS_FAILURE_MODE_PANIC;

	switch (performed_action) {
		case PV_NAPC_MODULE_RINGBUFFER_ACTION_READ_BYTE: {
			if (do_panic) {
				NAPC_PANIC(
					"Read operation failed (READ_BYTE) and fail mode is set to NAPC_ACCESS_FAILURE_MODE_PANIC."
				);
			} else {
				PV_NAPC_RINGBUFFER_ERROR(
					"Refusing to read byte from empty buffer. " PV_NAPC_MODULE_RINGBUFFER_DEBUG_PRINT_STATEMENT,
					PV_NAPC_MODULE_RINGBUFFER_DEBUG_PRINT_VARIABLES
				);
			}
		} break;

		case PV_NAPC_MODULE_RINGBUFFER_ACTION_READ_BYTES: {
			if (do_panic) {
				NAPC_PANIC(
					"Read operation failed (READ_BYTES) and fail mode is set to NAPC_ACCESS_FAILURE_MODE_PANIC."
				);
			} else {
				PV_NAPC_RINGBUFFER_ERROR(
					"Refusing to read bytes from buffer, not enough bytes readable in buffer." PV_NAPC_MODULE_RINGBUFFER_DEBUG_PRINT_STATEMENT,
					PV_NAPC_MODULE_RINGBUFFER_DEBUG_PRINT_VARIABLES
				);
			}
		} break;

		case PV_NAPC_MODULE_RINGBUFFER_ACTION_WRITE_BYTE: {
			if (do_panic) {
				NAPC_PANIC(
					"Insert operation (WRITE_BYTE) failed and fail mode is set to NAPC_ACCESS_FAILURE_MODE_PANIC."
				);
			} else {
				PV_NAPC_RINGBUFFER_ERROR(
					"Refusing to insert byte into full buffer. " PV_NAPC_MODULE_RINGBUFFER_DEBUG_PRINT_STATEMENT,
					PV_NAPC_MODULE_RINGBUFFER_DEBUG_PRINT_VARIABLES
				);
			}
		} break;

		case PV_NAPC_MODULE_RINGBUFFER_ACTION_WRITE_BYTES: {
			if (do_panic) {
				NAPC_PANIC(
					"Insert operation (WRITE_BYTES) failed and fail mode is set to NAPC_ACCESS_FAILURE_MODE_PANIC."
				);
			} else {
				PV_NAPC_RINGBUFFER_ERROR(
					"Refusing to place bytes into buffer, not enough free space. " PV_NAPC_MODULE_RINGBUFFER_DEBUG_PRINT_STATEMENT,
					PV_NAPC_MODULE_RINGBUFFER_DEBUG_PRINT_VARIABLES
				);
			}
		} break;
	}
}
