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
#include <hw.module/udp/_private/_udp.h>

napc__UDPSocket napc_UDP_createSocket(napc_u16 port) {
	if (!napc_env_isEthernetAvailable()) {
		NAPC_PANIC(
			"Attempted to create UDP socket without the system supporting ethernet."
		);
	}

	napc_ssize udp_socket = napc_Pool_claimElement(&PV_napc_udp_sockets_pool);

	if (0 > udp_socket) {
		return -1;
	}

	void *element = napc_Pool_getAddress(&PV_napc_udp_sockets_pool, udp_socket);

	if (!HAL_napc_UDP_createSocket(element, port)) {
		napc_Pool_releaseElement(&PV_napc_udp_sockets_pool, udp_socket);

		return -1;
	}

	return udp_socket;
}
