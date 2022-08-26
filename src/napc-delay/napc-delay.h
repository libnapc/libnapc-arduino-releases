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
#if !defined(NAPC_DELAY_h)
	#define NAPC_DELAY_h

	#include <libnapc.h>

	/*!
	 * @name napc_delay
	 * @brief Delay program execution.
	 * @version 1.0.0
	 * @description Delay program execution.
	 * @param amount The amount in milliseconds.
	 * @flags hw
	 * @changelog 1.0.0 17.02.2022 initial version
	 * @example
	 * napc_printf("Hello ");
	 * 
	 * napc_delay(1000); // wait for 1 second
	 * 
	 * napc_printf("World!");
	 */
	void napc_delay(napc_time amount);

	/*!
	 * @name napc_delayUs
	 * @brief Delay program execution.
	 * @version 1.0.0
	 * @description Delay program execution.
	 * @param amount The amount in microseconds.
	 * @flags hw
	 * @changelog 1.0.0 17.02.2022 initial version
	 * @example
	 * napc_printf("Hello ");
	 * 
	 * napc_delayUs(250000); // wait for 250 milliseconds
	 * 
	 * napc_printf("World!");
	 */
	void napc_delayUs(napc_time amount);
#endif
