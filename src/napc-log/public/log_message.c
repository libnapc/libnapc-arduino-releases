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
#include <napc-log/_private/_napc-log.h>

static char _message_buffer[256]; // @static
static char _fn[64]; // @static

static void _shortenFunctionName(const char *fn, char *buf) {
	napc_size fn_len = napc_strlen(fn);
	const napc_size max = 40;

	if (max >= fn_len) {
		napc_strncpy(buf, fn, 64);
		return;
	}

	napc_size start = fn_len - (max - 1);

	for (napc_size i = 0; i < max; ++i) {
		buf[i] = fn[start + i];
	}

	buf[0] = '.';
	buf[1] = '.';
	buf[2] = '.';

	buf[max - 1] = 0;
}

static void _callLogHandlers(
	const char *subsys,
	int level,
	const char *function,
	const char *message
) {
	// call log handler
	for (napc_size i = 0; i < NAPC_ARRAY_ELEMENTS(PV_napc_log_handler_array); ++i) {
		napc_logHandlerFunction handler = PV_napc_log_handler_array[i];
		void *handler_context = PV_napc_log_handler_context_array[i];

		if (handler) {
			handler(
				handler_context,
				subsys,
				level,
				function,
				message
			);
		}
	}
}

void napc_logMessage(
	const char *subsys,
	int level,
	const char *function,
	const char *fmt, ...
) {
	napc_time time = napc_getTimeSinceBoot();

	if (PV_napc_log_colorful_output) {
		if (level == NAPC_LEVEL_INFO) {
			napc_puts("\033[0;34m");
		} else if (level == NAPC_LEVEL_WARNING) {
			napc_puts("\033[0;33m");
		} else if (level == NAPC_LEVEL_ERROR) {
			napc_puts("\033[0;31m");
		}
	}

	{
		const char *label = napc_logLevelToString(level);

		napc_mzero(_fn, sizeof(_fn));
		_shortenFunctionName(function, _fn);

		napc_snprintf(
			_message_buffer, sizeof(_message_buffer),
			"(%-5s +%010" NAPC_TIME_PRINTF " / %8" NAPC_SIZE_PRINTF ") subsys=%-23s [%40s] ",
			label, time, napc_getFreeMemory(), subsys, _fn
		);

		napc_puts(_message_buffer);
	}

	{
		va_list args;

		va_start(args, fmt);
		napc_vsnprintf(_message_buffer, sizeof(_message_buffer), fmt, args);
		va_end(args);
	}

	_callLogHandlers(
		subsys, level, function, _message_buffer
	);

	for (napc_size i = 0; i < napc_strlen(_message_buffer); ++i) {
		const char ch = _message_buffer[i];

		napc_putc(ch);

		if (ch == '\n') {
			for (napc_size i = 0; i < 105; ++i) {
				napc_putc(' ');
			}
		}
	}

	if (PV_napc_log_colorful_output) {
		napc_puts("\033[0;0m");
	}

	napc_puts("\n");
}
