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
	#include <napc-log/_private/_napc-log.h>
	#include <napc-serial/napc-serial.h> // napc_printf()
	#include <string.h> // strlen(), strcasecmp()

	void HAL_napc_determineColorOutput(void) {
		const char *colorful_output= getenv("NAPC_COLORFUL_OUTPUT");

		if (!colorful_output) return;

		PV_napc_log_colorful_output = strcasecmp(colorful_output, "yes") == 0;

		if (PV_napc_log_colorful_output) {
			napc_printf("HAL_napc_determineColorOutput (linux) using colorful output.");
		}
	}
#endif
