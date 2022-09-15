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
#if defined(ARDUINO)
	#include <hw.module/platform/arduino/arduino.hpp>

	extern "C" {
		#include <hw.module/udp/_private/_udp.h>

		bool HAL_napc_UDP_receive(
			void *ptr,
			napc__IPv4Participant *source,
			napc__Buffer *out
		) {
			EthernetUDP *udp = (EthernetUDP *)ptr;

			napc_ssize available = (napc_ssize)udp->parsePacket();

			if (0 >= available) return false;

			PV_NAPC_UDP_DEBUG(
				"udp->parsePacket() says %" NAPC_SSIZE_PRINTF " bytes are available to read.",
				available
			);

			napc_ssize result = udp->read(
				(char *)out->data, out->size
			);

			if (0 > result) {
				return false;
			}

			// Update buffer size
			out->size = result;

			const char *remote_ip = napc_arduino__IPAddressToString(udp->remoteIP());
			napc_u16 remote_port = udp->remotePort();

			PV_napc_UDP_logMessage(
				false, remote_ip, remote_port, out->size
			);

			if (source) {
				napc_IPv4Participant_init(
					source,
					// IP-Address as string
					remote_ip,
					// Port
					remote_port
				);
			}

			return true;
		}
	}
#endif
