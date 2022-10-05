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
#if !defined(PV_NAPC_MODULE_RANDOM_h)
	#define PV_NAPC_MODULE_RANDOM_h

	#include <module/random/random.h>

	#include <napc-rand-source/napc-rand-source.h> // napc_getRandomByte()
	#include <napc-delay/napc-delay.h> // napc_delayUs()

	#define PV_NAPC_RAND_POOL_SIZE 1024u

	void PV_napc_random_initPool(void);

	bool PV_napc_random_getByteUsed(napc_size byte_index);
	void PV_napc_random_setByteUsed(napc_size byte_index, bool used);

	napc_u8 PV_napc_random_consumeByte(void);

	extern napc_u8 PV_napc_used_random_bytes[PV_NAPC_RAND_POOL_SIZE / 8]; // @global
	extern napc_u8 PV_napc_random_bytes_pool[PV_NAPC_RAND_POOL_SIZE]; // @global
#endif
