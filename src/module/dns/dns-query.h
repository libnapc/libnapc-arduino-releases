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
#if !defined(NAPC_MODULE_DNS_QUERY_h)
	#define NAPC_MODULE_DNS_QUERY_h

	#include <libnapc.h>
	#include <module/dns/dns-qtype.h>

	#define NAPC_MODULE_DNS_MAX_NAME 64 // was 254 before

	/*!
	 * @name napc__DNSQuery
	 * @module DNS
	 * @brief Representation of a DNS query.
	 * @version 1.0.0
	 * @field name Name to lookup.
	 * @field qtype Query type, see `napc__DNSQType`.
	 * @changelog 1.0.0 17.02.2022 initial version
	 */
	typedef struct napc__DNSQuery {
		char name[NAPC_MODULE_DNS_MAX_NAME];
		napc__DNSQType qtype;
	} napc__DNSQuery;
#endif
