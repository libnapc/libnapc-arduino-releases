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
#include <module/reader/_private/_reader.h>

bool napc_Reader_readU32BE(
	napc__Reader *ctx, napc_u32 *out
) {
	if (!PV_napc_Reader_checkAccess(ctx, 4, "u32")) {
		return false;
	}

	const unsigned char *data = ctx->data;
	napc_u8 byte_3 = data[ctx->_offset + 0];
	napc_u8 byte_2 = data[ctx->_offset + 1];
	napc_u8 byte_1 = data[ctx->_offset + 2];
	napc_u8 byte_0 = data[ctx->_offset + 3];

	napc_u32 result = 0;
	result |= (byte_0 <<  0u);
	result |= (byte_1 <<  8u);
	result |= (byte_2 << 16u);
	result |= (byte_3 << 24u);
	ctx->_offset += 4;

	if (out) {
		*out = result;
	}

	return true;
}
