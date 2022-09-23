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
#include <napc-panic/_private/_napc-panic.h>

static char _message_buffer[256]; // @static

void napc_halt(
	const char *file,
	int file_line,
	const char *fn,
	const char *fmt,
	...
) {
	// make sure serial is not muted
	napc_unmute();

	napc_time time = napc_getTimeSinceBoot();

	{
		napc_snprintf(
			_message_buffer, sizeof(_message_buffer),
			"\n\n(panic +%010" NAPC_TIME_PRINTF ") Originated by function %s in file %s (line %u)", time, fn, file, file_line
		);

		napc_puts(_message_buffer);
	}

	{
		napc_snprintf(
			_message_buffer, sizeof(_message_buffer),
			"\n\n(panic +%010" NAPC_TIME_PRINTF ") ", time
		);

		napc_puts(_message_buffer);
	}

	{
		va_list args;

		va_start(args, fmt);
		napc_vsnprintf(_message_buffer, sizeof(_message_buffer), fmt, args);
		va_end(args);

		napc_puts(_message_buffer);
	}

	napc_puts("\n\n");

	napc_printf(
		"(panic +%010" NAPC_TIME_PRINTF ") The application has experienced a fatal error.\n",
		time
	);

	napc_printf(
		"(panic +%010" NAPC_TIME_PRINTF ") There's likely log output above.\n",
		time
	);

	napc_printf(
		"(panic +%010" NAPC_TIME_PRINTF ") Application will be terminated.\n",
		time
	);

	// flush serial buffer
	napc_puts("\n\n");

	HAL_napc_abort();
}
