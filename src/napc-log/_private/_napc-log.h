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
#if !defined(PV_NAPC_LOG_h)
	#define PV_NAPC_LOG_h

	#include <napc-log/napc-log.h>
	#include <napc-log/HAL/HAL.h>

	#include <napc-core/napc-core.h> // napc_getFreeMemory()
	#include <napc-time/napc-time.h> // napc_getTimeSinceBoot()
	#include <napc-utils/napc-utils.h> // napc_snprintf()
	#include <napc-serial/napc-serial.h> // napc_printf()

	extern napc_logHandlerFunction PV_napc_log_handler_array[5]; // @global
	extern void *PV_napc_log_handler_context_array[5]; // @global
	extern bool PV_napc_log_colorful_output; // @global
#endif
