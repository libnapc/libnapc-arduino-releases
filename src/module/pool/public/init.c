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

void napc_Pool_init(
	napc__Pool *pool,
	const char *pool_label,
	void *array_start,
	napc_size num_elements,
	napc_size element_size
) {
	if (num_elements > NAPC_POOL_MAX) {
		NAPC_PANIC("Too many entries for pool.");
	}

	pool->label        = !pool_label ? "(null)" : pool_label;
	pool->num_elements = num_elements;
	pool->element_size = element_size;
	pool->array_start  = array_start;

	for (napc_size i = 0; i < NAPC_POOL_MAX; ++i) {
		pool->elements_used[i] = false;
	}

	NAPC_MAGIC_INIT(napc__Pool, pool);
}
