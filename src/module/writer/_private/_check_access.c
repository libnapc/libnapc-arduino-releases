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

bool PV_napc_Writer_checkAccess(
	napc__Writer *ctx, napc_size type_size, const char *type
) {
	NAPC_MAGIC_ASSERT(napc__Writer, ctx);

	napc_size new_offset = ctx->_offset + type_size;

	if (new_offset > ctx->size) {
		PV_NAPC_WRITER_ERROR(
			"Refusing to write type '%s' (size=%" NAPC_SIZE_PRINTF ") to buffer"
			" (offset=%" NAPC_SIZE_PRINTF ",size=%" NAPC_SIZE_PRINTF ")",
			type,
			type_size,
			ctx->_offset,
			ctx->size
		);

		if (ctx->no_fail_mode) {
			NAPC_PANIC(
				"Write operation failed and no_fail_mode is set to true."
			);
		}

		return false;
	}

	return true;
}
