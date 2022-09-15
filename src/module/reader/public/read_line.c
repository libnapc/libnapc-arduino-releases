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

const char *napc_Reader_readLine(
	napc__Reader *ctx, char *line_buffer, napc_size line_buffer_size
) {
	NAPC_MAGIC_ASSERT(napc__Reader, ctx);

	if (!line_buffer_size) {
		NAPC_PANIC(
			"line_buffer_size cannot be zero inside napc_reader__readLine()."
		);
	}

	char ch = 0;
	napc_size pos = 0;

	napc_mzero(line_buffer, line_buffer_size);

	while (napc_Reader_readChar(ctx, &ch)) {
		bool shouldWrite = (line_buffer_size > pos);

		if (ch == '\n') {
			// Terminate line
			if (shouldWrite) line_buffer[pos] = 0;
			++pos;
			break;
		}

		if (shouldWrite) line_buffer[pos] = ch;
		++pos;
	}

	// Nothing has been read
	if (pos == 0) return NULL;

	// Attempt to terminate line
	if (line_buffer_size > pos) line_buffer[pos] = 0;

	// Always terminate line
	line_buffer[line_buffer_size - 1] = 0;

	return line_buffer;
}
