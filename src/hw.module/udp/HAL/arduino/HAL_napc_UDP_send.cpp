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

		bool HAL_napc_UDP_send(
			void *ptr,
			bool do_logging,
			napc__IPv4Participant destination,
			const void *buffer, napc_size buffer_size
		) {
			EthernetUDP *udp = (EthernetUDP *)ptr;

			if (do_logging) {
				PV_napc_UDP_logMessage(
					true,
					destination.addr,
					destination.port,
					buffer_size
				);
			}

			arduino::IPAddress IP;

			if (!IP.fromString(destination.addr)) {
				PV_NAPC_UDP_ERROR(
					"Failed to convert IP %s to raw IP-Address.",
					destination.addr
				);

				return false;
			}

			udp->beginPacket(
				IP, destination.port
			);
			udp->write(
				(const char *)buffer,
				buffer_size
			);

			if (udp->endPacket() != 1) {
				PV_NAPC_UDP_ERROR(
					"Failed to send UDP-Packet (size=%" NAPC_SIZE_PRINTF ") to %s:%u.",
					buffer_size, destination.addr, destination.port
				);

				return false;
			}

			return true;
		}
	}
#endif
