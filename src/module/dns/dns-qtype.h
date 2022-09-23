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
#if !defined(NAPC_MODULE_DNS_QTYPE_h)
	#define NAPC_MODULE_DNS_QTYPE_h

	#include <libnapc.h>

	/*!
	 * @name napc__DNSQType
	 * @module DNS
	 * @brief Representation of DNS query type.
	 * @version 1.0.0
	 * @enum NAPC_DNS_QTYPE_A A-Record query
	 * @enum NAPC_DNS_QTYPE_CNAME CNAME-Record query
	 * @enum NAPC_DNS_QTYPE_MX MX-Record query
	 * @enum NAPC_DNS_QTYPE_TXT TXT-Record query
	 * @enum NAPC_DNS_QTYPE_AAAA AAAA-Record query
	 * @changelog 1.0.0 17.02.2022 initial version
	 * @changelog 2.0.0 14.04.2022 added CNAME,MX and TXT types
	 */
	typedef enum napc__DNSQType {
		NAPC_DNS_QTYPE_A     = 1,
		NAPC_DNS_QTYPE_CNAME = 5,
		NAPC_DNS_QTYPE_MX    = 15,
		NAPC_DNS_QTYPE_TXT   = 16,
		NAPC_DNS_QTYPE_AAAA  = 28
	} napc__DNSQType;
#endif
