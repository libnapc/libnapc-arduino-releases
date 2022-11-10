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
#if !defined(ARDUINO)
	#include <hw.module/file/_private/_file.h>
	#include <stdio.h> // FILE, fopen(), fileno()
	#include <napc-utils/napc-utils.h> // napc_strlen(), napc_snprintf(), napc_strncpy()

	extern char PV_napc_fs_linuxRootPath[512]; // @global

	bool HAL_napc_File_open(void *ptr, const char *path, const char *mode) {
		char realpath[1024];

		if (napc_strlen(PV_napc_fs_linuxRootPath)) {
			napc_snprintf(realpath, sizeof(realpath), "%s/%s", PV_napc_fs_linuxRootPath, path);
		} else {
			napc_strncpy(realpath, path, sizeof(realpath));
		}

		FILE *fp = fopen(realpath, mode);

		if (!fp) {
			return false;
		}

		FILE **tmp = ptr;
		*tmp = fp;

		return true;
	}
#endif
