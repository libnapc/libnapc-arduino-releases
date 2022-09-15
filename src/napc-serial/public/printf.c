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
#include <napc-serial/_private/_napc-serial.h>
#include <string.h> // memset()
#include <stdio.h> // vsnprintf()

static char _printf_buffer[256]; // @static

void napc_printf(const char *fmt, ...) {
	if (PV_napc_serial_muted) return;

	va_list args;

	memset(_printf_buffer, 0, sizeof(_printf_buffer));

	va_start(args, fmt);
	vsnprintf(_printf_buffer, sizeof(_printf_buffer), fmt, args);
	va_end(args);

	_printf_buffer[sizeof(_printf_buffer) - 1] = 0;

	napc_puts(_printf_buffer);
}
