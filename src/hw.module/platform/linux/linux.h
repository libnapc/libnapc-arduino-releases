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
#if !defined(NAPC_PLATFORM_LINUX_h)
	#define NAPC_PLATFORM_LINUX_h

	#if !defined(ARDUINO)
		#include <libnapc.h>

		#include <module/buffer/buffer.h>
		#include <module/ipv4participant/ipv4participant.h>

		#include <napc-utils/napc-utils.h> // napc_mzero()
		#include <sys/socket.h> // socket(), AF_INET, SOCK_DGRAM
		#include <netinet/in.h> // struct sockaddr_in
		#include <arpa/inet.h> // inet_ntoa()
		#include <unistd.h> // close()
		#include <fcntl.h> // fcntl()
		#include <signal.h> // signal(), SIGPIPE, SIG_IGN

		int napc_linux__createUDPSocket(void);
		struct sockaddr_in napc_linux__createAddressStruct(int port);
		bool napc_linux__bindSocket(int sockfd, int port);

		bool napc_linux__writeToUDPSocket(
			int sockfd,
			const void *buffer, napc_size buffer_size,
			napc__IPv4Participant destination
		);

		bool napc_linux__readFromUDPSocket(
			int sockfd,
			napc__Buffer *buffer,
			napc__IPv4Participant *source
		);
	#endif
#endif
