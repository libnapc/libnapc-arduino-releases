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
#if !defined(PV_NAPC_MODULE_APP_LOG_h)
	#define PV_NAPC_MODULE_APP_LOG_h

	#include <napc-log/napc-log.h>
	#include <napc-panic/napc-panic.h>

	#define PV_NAPC_APP_VERBOSE(...)  NAPC_LOG_VERBOSE("libnapc_app", ##__VA_ARGS__)
	#define PV_NAPC_APP_TRACE(...)    NAPC_LOG_TRACE("libnapc_app", ##__VA_ARGS__)
	#define PV_NAPC_APP_DEBUG(...)    NAPC_LOG_DEBUG("libnapc_app", ##__VA_ARGS__)
	#define PV_NAPC_APP_INFO(...)     NAPC_LOG_INFO("libnapc_app", ##__VA_ARGS__)
	#define PV_NAPC_APP_WARNING(...)  NAPC_LOG_WARNING("libnapc_app", ##__VA_ARGS__)
	#define PV_NAPC_APP_ERROR(...)    NAPC_LOG_ERROR("libnapc_app", ##__VA_ARGS__)
#endif
