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
#if !defined(PV_NAPC_MODULE_DNS_h)
	#define PV_NAPC_MODULE_DNS_h

	#include <module/dns/dns.h>
	#include <module/dns/_private/_log.h>

	#include <module/reader/reader.h>
	#include <module/writer/writer.h>
	#include <napc-utils/napc-utils.h> // napc_strncpy()
	#include <string.h> // memcpy()

	/**
	 * This code was taken from https://elixir.bootlin.com/musl/v1.2.2/source/src/network/dn_expand.c
	 * It's responsible for expanding compressed dns names.
	 */
	int PV_napc_DNS_dn_expand(
		// pointer to start of message
		const unsigned char *base,
		// pointer to end of message
		const unsigned char *end,
		// pointer to compressed name
		const unsigned char *src,
		// buffer for name
		char *dest,
		int space
	) NAPC_FN_WARNUNUSED_RET();

	bool PV_napc_DNS_parseQuerySection(
		napc__DNSQuery *out,
		napc__Reader *reader
	) NAPC_FN_WARNUNUSED_RET();

	bool PV_napc_DNS_parseAnswerSection(
		napc__DNSAnswer *out,
		napc__Reader *reader
	) NAPC_FN_WARNUNUSED_RET();

	/**
	 * Used as a temporary buffer when expanding
	 * compressed dns names.
	 */
	extern char PV_napc_DNS_tmp_name[NAPC_MODULE_DNS_MAX_NAME]; // @global


#endif
