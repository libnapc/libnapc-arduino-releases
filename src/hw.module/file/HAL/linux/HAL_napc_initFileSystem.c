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
	#include <napc-serial/napc-serial.h> // napc_printf()
	#include <napc-utils/napc-utils.h> // napc_strncpy()

	#include <stdlib.h> // getenv(), realpath()
	#include <limits.h> // PATH_MAX

	char PV_napc_fs_linuxRootPath[512]; // @global

	static void setRootPath(const char *path) {
		napc_printf("HAL_napc_initFileSystem (linux) root path = '%s'\n", path);

		napc_strncpy(
			PV_napc_fs_linuxRootPath,
			path,
			sizeof(PV_napc_fs_linuxRootPath)
		);
	}

	void HAL_napc_initFileSystem(void) {
		napc_mzero(PV_napc_fs_linuxRootPath, sizeof(PV_napc_fs_linuxRootPath));

		const char *root_path = getenv("NAPC_FILE_ROOT_PATH");

		if (!root_path) {
			root_path = ".";
		}

		// only resolve NAPC_FILE_ROOT_PATH if this environment variable
		// was not set
		if (!getenv("NAPC_FILE_NO_RESOLVE_ROOT_PATH")) {
			char resolved_root_path[PATH_MAX];

			if (realpath(root_path, resolved_root_path)) {
				setRootPath(resolved_root_path);
			} else {
				napc_printf("!!! ERROR failed to resolve '%s' !!!\n", root_path);

				setRootPath("");
			}
		} else {
			setRootPath(root_path);
		}

		PV_napc_fs_initialized = true;
	}
#endif
