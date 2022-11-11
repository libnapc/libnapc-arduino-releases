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
#if !defined(NAPC_SERIAL_h)
	#define NAPC_SERIAL_h

	#include <libnapc.h>

	/*!
	 * @name napc_puts
	 * @brief Print a string to console/serial.
	 * @version 1.0.0
	 * @description Output a string via console or serial.
	 * @flags hw
	 * @param str The string to be printed.
	 * @changelog 1.0.0 17.02.2022 initial version
	 * @example
	 * napc_puts("Hello World!");
	 */
	void napc_puts(const char *str);

	/*!
	 * @name napc_putc
	 * @brief Print a character to console/serial.
	 * @version 1.0.0
	 * @description Output a single character via console or serial.
	 * @flags hw
	 * @param ch The character to be printed.
	 * @changelog 1.0.0 17.02.2022 initial version
	 * @example
	 * napc_putc('H');
	 * napc_putc('e');
	 * napc_putc('l');
	 * napc_putc('l');
	 * napc_putc('o');
	 * napc_putc('!');
	 */
	void napc_putc(char ch);

	/*!
	 * @name napc_printf
	 * @brief Print a printf()-like formatted string.
	 * @version 1.0.0
	 * @description
	 * Print out information without having to call `snprintf()` first.
	 * @flags smem
	 * @changelog 1.0.0 17.02.2022 initial version
	 * @example
	 * int my_var = 13;
	 * 
	 * napc_printf("Value of my_var is %d", my_var);
	 * @param fmt printf()-like format string.
	 * @param ... Values to incorporate into string.
	 */
	void napc_printf(const char *fmt, ...) NAPC_FN_PRINTFLIKE(1, 2);

	/*!
	 * @name napc_mute
	 * @brief Disable console/serial output.
	 * @version 1.0.0
	 * @description
	 * Temporarily disable output of `napc_puts`, `napc_putc` and `napc_printf`.
	 * @notes
	 * This functionality is used in the unit test suite of libnapc.
	 * @changelog 1.0.0 17.02.2022 initial version
	 * @example
	 * napc_printf("Hello"); // prints Hello
	 * 
	 * napc_mute();
	 * 
	 * napc_printf(" World!"); // this will not be printed
	 * 
	 * napc_unmute();
	 * 
	 * napc_printf(" Earth!"); // prints Earth!
	 */
	void napc_mute(void);

	/*!
	 * @name napc_unmute
	 * @brief Enable console/serial output.
	 * @version 1.0.0
	 * @description
	 * Re-enable output of `napc_puts`, `napc_putc` and `napc_printf` after a call to `napc_mute`.
	 * @notes
	 * This functionality is used in the unit test suite of libnapc.
	 * @changelog 1.0.0 17.02.2022 initial version
	 * @example
	 * napc_printf("Hello"); // prints Hello
	 * 
	 * napc_mute();
	 * 
	 * napc_printf(" World!"); // this will not be printed
	 * 
	 * napc_unmute();
	 * 
	 * napc_printf(" Earth!"); // prints Earth!
	 */
	void napc_unmute(void);
#endif
