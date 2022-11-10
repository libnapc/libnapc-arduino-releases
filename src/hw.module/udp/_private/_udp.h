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
#if !defined(PV_NAPC_HW_MODULE_UDP_h)
	#define PV_NAPC_HW_MODULE_UDP_h

	#include <hw.module/udp/udp.h>
	#include <hw.module/udp/HAL/HAL.h>
	#include <hw.module/udp/_private/_log.h>

	#include <hw.module/env/env.h>
	#include <module/pool/pool.h>
	#include <napc-utils/napc-utils.h>

	extern napc__Pool PV_napc_udp_sockets_pool; // @global

	void PV_napc_UDP_logMessage(
		bool sending,
		const char *ip,
		napc_u16 port,
		napc_size packet_size
	);
#endif
