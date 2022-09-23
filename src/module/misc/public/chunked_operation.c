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
#include <module/misc/_private/_misc.h>

bool napc_misc_chunkedOperation(
	const void *data, napc_size data_size, napc_size chunk_size,
	napc_misc_ChunkedOperationCallback fn, void *fn_context
) {
	const unsigned char *ptr = data;
	napc_size bytes_left_to_process = data_size;
	napc_size current_chunk_size = chunk_size;

	while (bytes_left_to_process > 0) {
		if (current_chunk_size > bytes_left_to_process) {
			PV_NAPC_MISC_VERBOSE(
				"Halving chunk_size=%" NAPC_SIZE_PRINTF,
				current_chunk_size
			);

			current_chunk_size /= 2;

			// Make sure chunk size never is zero
			if (!current_chunk_size) current_chunk_size = 1;

			continue;
		}

		napc_ssize result = fn(ptr, current_chunk_size, fn_context);

		// Impartial operation
		if (result != (napc_ssize)current_chunk_size) {
			PV_NAPC_MISC_ERROR(
				"Impartial chunk operation (current_chunk_size=%" NAPC_SIZE_PRINTF ",result=%" NAPC_SSIZE_PRINTF ")",
				current_chunk_size, result
			);

			return false;
		}

		ptr += current_chunk_size;

		bytes_left_to_process -= current_chunk_size;
	}

	return true;
}
