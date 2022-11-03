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
#include <hw.module/fs/_private/_fs.h>

bool napc_fs_readFile(
	const char *path, napc__Buffer *buffer
) {
	NAPC_MAGIC_ASSERT(napc__Buffer, buffer);

	PV_NAPC_FS_DEBUG("Reading file '%s'.", path);

	napc__File file = napc_File_open(path, "r");

	if (0 > file) return false;

	napc_size size_to_read = napc_File_getSize(file);

	if (size_to_read > buffer->size) {
		napc_File_close(file);

		PV_NAPC_FS_ERROR(
			"Cannot possibly fit file into buffer (buffer's too small)."
			"Buffer size: %" NAPC_SIZE_PRINTF " File size: %" NAPC_SIZE_PRINTF,
			buffer->size, size_to_read
		);

		return false;
	}

	bool result = napc_misc_chunkedOperation(
		buffer->data, size_to_read, 512, PV_nap_fs_readFileChunk, (void *)file
	);

	buffer->size = size_to_read;

	napc_File_close(file);

	return result;
}
