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
#include <napc-core/_private/_napc-core.h>

const char *napc_getFullVersion(void);

napc_time PV_napc_uptime = 0; // @global

void napc_main(const char *platform) {
	napc_time reference = napc_getTimeSinceBoot();

	napc_printf("(c) by nap.software (platform=%s)\n", platform);
	napc_printf("Using libnapc version %s\n", napc_getFullVersion());

	napc_setup(platform);

	while (true) {
		napc_time delta = napc_getTimeSinceBoot() - reference;

		if (!napc_loop(PV_napc_uptime)) break;

		// 1000ms is 1s
		if (delta >= NAPC_TIME_LITERAL(1000)) {
			napc_time n_seconds = (delta / NAPC_TIME_LITERAL(1000));
			PV_napc_uptime += n_seconds;

			reference = napc_getTimeSinceBoot();
		}

		// prevent high cpu usage on linux systems
		HAL_napc_loopYieldCPU();
	}
}
