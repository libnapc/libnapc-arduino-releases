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
#include <module/pool/_private/_pool.h>

void *napc_Pool_getAddress(
	const napc__Pool *pool,
	napc_size element_index
) {
	NAPC_MAGIC_ASSERT(napc__Pool, pool);

	if (element_index > pool->num_elements) {
		NAPC_PANIC("Element index is out of range. (pool=%s)", pool->label);
	} else if (!pool->elements_used[element_index]) {
		NAPC_PANIC(
			"Cannot get address of element (index=%" NAPC_SIZE_PRINTF ")"
			" that is not allocated (pool=%s).",
			element_index, pool->label
		);
	}

	unsigned char *base = pool->array_start;

	base += (pool->element_size * element_index);

	return (void *)base;
}
