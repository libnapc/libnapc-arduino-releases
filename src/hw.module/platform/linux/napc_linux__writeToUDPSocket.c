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
	#include <hw.module/platform/linux/linux.h>

	bool napc_linux__writeToUDPSocket(
		int sockfd,
		const void *buffer, napc_size buffer_size,
		napc__IPv4Participant destination
	) {
		struct sockaddr_in addr = napc_linux__createAddressStruct(destination.port);
		addr.sin_addr.s_addr = inet_addr(destination.addr);

		(void)sendto(
			sockfd,
			// buffer, buffer size
			buffer, buffer_size,
			// flags
			0,
			(const struct sockaddr *)&addr, sizeof(addr)
		);

		return true;
	}
#endif
