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
#if !defined(PV_NAPC_MODULE_RINGBUFFER_h)
	#define PV_NAPC_MODULE_RINGBUFFER_h

	#include <module/ring-buffer/ring-buffer.h>
	#include <module/ring-buffer/_private/_log.h>

	#define PV_NAPC_MODULE_RINGBUFFER_ACTION_READ_BYTE   0
	#define PV_NAPC_MODULE_RINGBUFFER_ACTION_READ_BYTES  1
	#define PV_NAPC_MODULE_RINGBUFFER_ACTION_WRITE_BYTE  2
	#define PV_NAPC_MODULE_RINGBUFFER_ACTION_WRITE_BYTES 3

	#define PV_NAPC_MODULE_RINGBUFFER_DEBUG_PRINT_STATEMENT \
		"(write_position=%" NAPC_SIZE_PRINTF ",read_position=%" NAPC_SIZE_PRINTF ",size=%" NAPC_SIZE_PRINTF ")"

	#define PV_NAPC_MODULE_RINGBUFFER_DEBUG_PRINT_VARIABLES \
		ctx->write_position, ctx->read_position, ctx->buffer_size

	napc_size PV_napc_RingBuffer_numFreeSpots(
		const napc__RingBuffer *ctx
	);

	bool PV_napc_RingBuffer_insertByte(
		napc__RingBuffer *ctx, napc_u8 byte, bool force
	);

	void PV_napc_RingBuffer_performAccessFailureAction(
		const napc__RingBuffer *ctx, int performed_action
	);
#endif
