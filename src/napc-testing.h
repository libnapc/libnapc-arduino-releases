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
#if !defined(NAPC_TESTING_h)
	#define NAPC_TESTING_h

	#define PV_NAPC_TESTING_CONCAT(a, b) a ## b
	#define NAPC_TESTING_CONCAT(a, b) PV_NAPC_TESTING_CONCAT(a, b)

	#include <string.h>

	/*
	 * This is not the FINAL function name.
	 * It's just here to make clangd happy.
	 */
	#define TEST_CASE(description) \
		NAPC_TESTING_CONCAT(void PV_napc_unitTest, __COUNTER__) (void)

	void PV_napc_testAssert(
		const char *assertion,
		const char *file,
		int expr
	);

	#define TEST_ASSERT(expr) \
		PV_napc_testAssert(#expr, __FILE__, !!(expr))
#endif
