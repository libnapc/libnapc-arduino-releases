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
	#include <Ethernet.h>

	extern "C" {
		#include <hw.module/eth/_private/_eth.h>

		static napc_u8 _dummy_mac_address[6] = {
			0x11, 0x22, 0x33, 0x44, 0x55, 0x66
		};

		// use an ip from the self assigned ip range to suppress the dhcp client
		static napc_u8 _self_assigned_ip[4] = {169, 254, 99, 99};

		void HAL_napc_initEthernet(void) {
			Ethernet.begin(_dummy_mac_address, _self_assigned_ip);

			if (Ethernet.hardwareStatus() == EthernetNoHardware) {
				PV_NAPC_ETH_WARNING("Ethernet shield was not found.");
			} else if (Ethernet.hardwareStatus() == EthernetW5100) {
				PV_NAPC_ETH_INFO("W5100 Ethernet controller detected.");

				PV_napc_eth_initialized = true;
			} else if (Ethernet.hardwareStatus() == EthernetW5200) {
				PV_NAPC_ETH_INFO("W5200 Ethernet controller detected.");

				PV_napc_eth_initialized = true;
			} else if (Ethernet.hardwareStatus() == EthernetW5500) {
				PV_NAPC_ETH_INFO("W5500 Ethernet controller detected.");

				PV_napc_eth_initialized = true;
			}
		}
	}
#endif
