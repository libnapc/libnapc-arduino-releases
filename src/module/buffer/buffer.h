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
/*!
 * @name Buffer:intro
 * @description
 * To reduce parameter count this module is used to pass a buffer with its size to a function:
 * 
 * ```c
 * char data[512];
 * napc__Buffer buffer;
 * 
 * napc_Buffer_init(&buffer, data, sizeof(data));
 * ```
 */
#if !defined(NAPC_MODULE_BUFFER_h)
	#define NAPC_MODULE_BUFFER_h

	#include <libnapc.h>

	#include <napc-magic/napc-magic.h>

	/*!
	 * @name napc__Buffer
	 * @brief Representation of a memory buffer.
	 * @version 1.0.0
	 * @field size Size of data.
	 * @field data Pointer to data.
	 * @changelog 1.0.0 17.02.2022 initial version
	 */
	typedef struct {
		NAPC_MAGIC_MEMBER; // used to detect uninitialized buffers

		napc_size size;
		void *data;
	} napc__Buffer;

	/*!
	 * @name napc_Buffer_init
	 * @brief Initialize a buffer.
	 * @version 1.0.0
	 * @description
	 * Initialize a buffer.
	 * @param buffer Pointer to napc__Buffer instance to be initialized.
	 * @param data Pointer to data.
	 * @param data_size Size of data.
	 * @changelog 1.0.0 17.02.2022 initial version
	 * @example
	 * char message[512];
	 * napc__Buffer buffer;
	 * 
	 * napc_Buffer_init(&buffer, message, sizeof(message));
	 */
	void napc_Buffer_init(
		napc__Buffer *buffer, void *data, napc_size data_size
	);

	/*!
	 * @name napc_Buffer_create
	 * @brief Create a buffer.
	 * @version 1.0.0
	 * @description
	 * Create a buffer.
	 * @param data Pointer to data.
	 * @param data_size Size of data.
	 * @return Returns an initialized buffer.
	 * @changelog 1.0.0 17.02.2022 initial version
	 * @example
	 * char message[512];
	 * 
	 * napc__Buffer buffer = napc_Buffer_create(message, sizeof(message));
	 */
	napc__Buffer napc_Buffer_create(void *data, napc_size data_size);
#endif
