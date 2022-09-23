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
#include <module/misc/_private/_misc.h>

void napc_misc_shiftArrayRight(void *array, napc_size n_elements, napc_size element_size) {
	for (napc_ssize i = n_elements - 1; i >= 0 ; --i) {
		// cannot move last element, it gets discarded
		if ((napc_size)i == (n_elements - 1)) continue;

		// get pointer to the current element (i)
		unsigned char *current_element = ((unsigned char *)array) + (element_size * i);
		// get pointer to the next element
		unsigned char *next_element = ((unsigned char *)array) + (element_size * (i + 1));

		memcpy(next_element, current_element, element_size);
	}
}
