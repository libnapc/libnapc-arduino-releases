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
#if !defined(NAPC_MAGIC_h)
	#define NAPC_MAGIC_h

	#include <libnapc.h>

	#include <napc-panic/napc-panic.h>

	typedef uint32_t napc_init_magic;

	#define NAPC_MAGIC_MEMBER napc_init_magic _init_magic

	#define NAPC_MAGIC_DESTROYED NAPC_U32_LITERAL(0xFFFFFFFF)

	#define NAPC_MAGIC_INIT(type, obj) (obj)->_init_magic = (NAPC_MAGIC_ ## type)
	#define NAPC_MAGIC_DESTROY(obj) (obj)->_init_magic = NAPC_MAGIC_DESTROYED

	// Used to silence -Waddress warnings
	#define PV_NAPC_MAGIC_GET_VALUE(obj) \
		((void *)(obj) != NULL ? (obj)->_init_magic : 0)

	#define NAPC_MAGIC_ASSERT(type, obj)                                   \
		do {                                                               \
			const napc_init_magic actual   = PV_NAPC_MAGIC_GET_VALUE(obj); \
			const napc_init_magic expected = (NAPC_MAGIC_ ## type);        \
			if (actual == NAPC_MAGIC_DESTROYED) {                          \
				NAPC_PANIC("Attempt to use destroyed " # type);            \
			} else if (actual != expected) {                               \
				NAPC_PANIC("Detected uninitialized " # type);              \
			}                                                              \
		} while (false)

	/*
	 * Is used for structs that are allocated on the stack and have an
	 * _init() function.
	 */
	#define NAPC_MAGIC_napc__HRTimer                         NAPC_U32_LITERAL(0x56d3a4f1)
	#define NAPC_MAGIC_napc__Timer                           NAPC_U32_LITERAL(0x2f1fa628)
	#define NAPC_MAGIC_napc__Pool                            NAPC_U32_LITERAL(0xd3d0df2a)

	#define NAPC_MAGIC_napc__Buffer                          NAPC_U32_LITERAL(0x7beccbe2)
	#define NAPC_MAGIC_napc__Reader                          NAPC_U32_LITERAL(0xf0de7965)

	#define NAPC_MAGIC_napc__Writer                          NAPC_U32_LITERAL(0x1b81b5d1)

	#define NAPC_MAGIC_napc__IPv4Participant                 NAPC_U32_LITERAL(0x97d59a3d)
#endif
