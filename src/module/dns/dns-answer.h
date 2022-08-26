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
#if !defined(NAPC_MODULE_DNS_ANSWER_h)
	#define NAPC_MODULE_DNS_ANSWER_h

	#include <libnapc.h>

	#define NAPC_MODULE_DNS_MAX_RD_DATA_LENGTH 16u

	/*!
	 * @name napc__DNSAnswer
	 * @brief Representation of a DNS answer.
	 * @version 1.0.0
	 * @field ttl Time to live (in seconds).
	 * @field rd_length Response data size in bytes.
	 * @field rd_data Response data.
	 * @changelog 1.0.0 17.02.2022 initial version
	 */
	typedef struct {
		napc_u32 ttl;

		napc_u16 rd_length;
		napc_u8 rd_data[NAPC_MODULE_DNS_MAX_RD_DATA_LENGTH];
	} napc__DNSAnswer;
#endif
