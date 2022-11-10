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
#include <module/writer/_private/_writer.h>

bool napc_Writer_writeU32BE(
	napc__Writer *ctx, napc_u32 value
) {
	if (!PV_napc_Writer_checkAccess(ctx, 4, "u32")) {
		return false;
	}

	napc_u8 byte_3 = (value >> 24u) & 0xFFu;
	napc_u8 byte_2 = (value >> 16u) & 0xFFu;
	napc_u8 byte_1 = (value >>  8u) & 0xFFu;
	napc_u8 byte_0 = (value >>  0u) & 0xFFu;

	unsigned char *data = ctx->data;
	data[ctx->_offset + 0] = byte_3;
	data[ctx->_offset + 1] = byte_2;
	data[ctx->_offset + 2] = byte_1;
	data[ctx->_offset + 3] = byte_0;

	ctx->_offset += 4;

	return true;
}
