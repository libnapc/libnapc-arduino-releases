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
#if !defined(NAPC_INTTYPES_h)
	#define NAPC_INTTYPES_h

	#include <inttypes/8bit/napc_u8.h> // napc_u8
	#include <inttypes/8bit/napc_i8.h> // napc_i8

	#include <inttypes/16bit/napc_u16.h> // napc_u16
	#include <inttypes/16bit/napc_i16.h> // napc_i16

	#include <inttypes/32bit/napc_u32.h> // napc_u32
	#include <inttypes/32bit/napc_i32.h> // napc_i32

	#include <inttypes/size.h> // napc_size
	#include <inttypes/ssize.h> // napc_ssize
	#include <inttypes/time.h> // napc_time
#endif
