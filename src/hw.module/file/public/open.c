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
#include <hw.module/file/_private/_file.h>

napc__File napc_File_open(const char *path, const char *mode) {
	if (!PV_napc_fs_initialized) {
		NAPC_PANIC(
			"Attempted to open file without the file system being initialized."
		);
	}

	PV_NAPC_FILE_DEBUG("Opening file '%s' (mode=%s)", path, mode);

	if (!napc_streql(mode, "w") && !napc_streql(mode, "r")) {
		NAPC_PANIC("Invalid mode '%s'", mode);
	}

	napc_ssize fd = napc_Pool_claimElement(&PV_napc_fs_handles_pool);

	if (0 > fd) {
		return -1;
	}

	void *element = napc_Pool_getAddress(&PV_napc_fs_handles_pool, fd);

	if (!HAL_napc_File_open(element, path, mode)) {
		PV_NAPC_FILE_ERROR("Failed to open file '%s' (mode=%s)", path, mode);

		napc_Pool_releaseElement(&PV_napc_fs_handles_pool, fd);

		return -1;
	}

	PV_NAPC_FILE_DEBUG("Successfully opened file '%s'", path);

	return fd;
}
