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
 * @name RingBuffer:intro
 * @brief Circular byte buffer
 */
#if !defined(NAPC_MODULE_RINGBUFFER_h)
	#define NAPC_MODULE_RINGBUFFER_h

	#include <libnapc.h>
	#include <napc-magic/napc-magic.h>
	#include <napc-core/napc-core.h> // napc__AccessFailureMode

	/*!
	 * @name napc__RingBuffer
	 * @module RingBuffer
	 * @brief Representation of a RingBuffer.
	 * @version 2.0.0
	 * @opaque
	 * @changelog 2.0.0 21.10.2022 initial version
	 */
	typedef struct napc__RingBuffer {
		NAPC_MAGIC_MEMBER;

		napc__AccessFailureMode _fail_mode;

		napc_u8 *buffer;
		napc_size buffer_size;

		napc_size read_position;
		napc_size write_position;

		bool buffer_full;
	} napc__RingBuffer;

	/*!
	 * @name napc_RingBuffer_init
	 * @brief Initialize a RingBuffer.
	 * @version 2.0.0
	 * @description
	 * Initializes a circular buffer object.
	 * @param ctx Pointer to `napc__RingBuffer` instance.
	 * @param buffer Pointer to the buffer to be used.
	 * @param buffer_size Size of the buffer `buffer`.
	 * @changelog 2.0.0 21.10.2022 initial version
	 * @example
	 * napc__RingBuffer rbuffer;
	 * napc_u8 buffer[512];
	 * 
	 * napc_RingBuffer_init(&rbuffer, buffer, sizeof(buffer));
	 */
	void napc_RingBuffer_init(
		napc__RingBuffer *ctx, napc_u8 *buffer, napc_size buffer_size
	);

	/*!
	 * @name napc_RingBuffer_create
	 * @brief Create a RingBuffer object.
	 * @version 2.0.0
	 * @param buffer Pointer to the buffer to be used.
	 * @param buffer_size Size of the buffer `buffer`.
	 * @changelog 2.0.0 21.10.2022 initial version
	 * @example
	 * napc_u8 buffer[512];
	 * 
	 * napc__RingBuffer rbuffer = napc_RingBuffer_create(buffer, sizeof(buffer));
	 */
	napc__RingBuffer napc_RingBuffer_create(napc_u8 *buffer, napc_size buffer_size);

	/*!
	 * @name napc_RingBuffer_setAccessFailureMode
	 * @brief Set action to be taken on access failure.
	 * @version 2.0.0.
	 * @description
	 * Sets the action to be taken when `insertByte`, `insertBytes`, `peekByte`, `removeByte` or `removeBytes` fail (i.e. return `false`).
	 * 
	 * The default is to log an error message but can be overwritten by `napc_setDefaultAccessFailureMode`.
	 * @param ctx Pointer to `napc__RingBuffer` instance.
	 * @param mode The fail mode to set.
	 * @changelog 2.0.0 21.10.2022 initial version
	 * @notes
	 * For more information refer to the `napc__AccessFailureMode` type.
	 */
	void napc_RingBuffer_setAccessFailureMode(
		napc__RingBuffer *ctx, napc__AccessFailureMode mode
	);

	/*!
	 * @name napc_RingBuffer_getBufferSize
	 * @brief Get buffer size.
	 * @description
	 * Gets the size of the underlying buffer used to store the data.
	 * @version 2.0.0
	 * @param ctx Pointer to `napc__RingBuffer` instance.
	 * @changelog 2.0.0 21.10.2022 initial version
	 * @example
	 * napc_u8 buffer[512];
	 * 
	 * napc__RingBuffer rbuffer = napc_RingBuffer_create(buffer, sizeof(buffer));
	 * 
	 * napc_size size = napc_RingBuffer_getBufferSize(&rbuffer); // size will be 512
	 */
	napc_size napc_RingBuffer_getBufferSize(const napc__RingBuffer *ctx);

	/*!
	 * @name napc_RingBuffer_getAvailableBytes
	 * @brief Get number of bytes available for reading.
	 * @version 2.0.0
	 * @param ctx Pointer to `napc__RingBuffer` instance.
	 * @changelog 2.0.0 21.10.2022 initial version
	 * @return
	 * Returns the number of bytes that can be read immediately.
	 */
	napc_size napc_RingBuffer_getAvailableBytes(const napc__RingBuffer *ctx);

	/*!
	 * @name napc_RingBuffer_peekByte
	 * @brief Attempt to read a byte without removing it.
	 * @version 2.0.0
	 * @param ctx Pointer to `napc__RingBuffer` instance.
	 * @param out Variable to store read byte.
	 * @changelog 2.0.0 21.10.2022 initial version
	 * @return
	 * Returns `true` if the byte at the current read position could be read.
	 * @warning
	 * `out` remains UNMODIFIED if function returned false.
	 */
	bool napc_RingBuffer_peekByte(const napc__RingBuffer *ctx, napc_u8 *out);

	/*!
	 * @name napc_RingBuffer_removeByte
	 * @brief Attempt to read a byte.
	 * @version 2.0.0
	 * @param ctx Pointer to `napc__RingBuffer` instance.
	 * @param out Variable to store read byte.
	 * @changelog 2.0.0 21.10.2022 initial version
	 * @return
	 * Returns `true` if the byte at the current read position could be read.
	 * @warning
	 * `out` remains UNMODIFIED if function returned false.
	 */
	bool napc_RingBuffer_removeByte(napc__RingBuffer *ctx, napc_u8 *out);

	/*!
	 * @name napc_RingBuffer_removeBytes
	 * @brief Attempt to read an array of bytes.
	 * @description
	 * Attempts to read `out_size` number of bytes from buffer.
	 * @version 2.0.0
	 * @param ctx Pointer to `napc__RingBuffer` instance.
	 * @param out Array to store read bytes from buffer.
	 * @param out_size Size of `out` array.
	 * @changelog 2.0.0 21.10.2022 initial version
	 * @return
	 * Returns `true` if number of bytes `out_size` were successfully read from the buffer.
	 * @notes
	 * If the buffer has less than `out_size` bytes available to read
	 * then no action is performed and the function returns `false`.
	 */
	bool napc_RingBuffer_removeBytes(napc__RingBuffer *ctx, napc_u8 *out, napc_size out_size);

	/*!
	 * @name napc_RingBuffer_insertByte
	 * @brief Attempt to insert a byte.
	 * @version 2.0.0
	 * @param ctx Pointer to `napc__RingBuffer` instance.
	 * @param byte Byte to store in circular buffer.
	 * @changelog 2.0.0 21.10.2022 initial version
	 * @return
	 * Returns `true` if the byte at the current write position could be written.
	 * @warning
	 * If the buffer is full the byte `byte` will not be inserted and `false` is returned.
	 */
	bool napc_RingBuffer_insertByte(napc__RingBuffer *ctx, napc_u8 byte);

	/*!
	 * @name napc_RingBuffer_insertBytes
	 * @brief Attempt to insert an array of bytes.
	 * @version 2.0.0
	 * @param ctx Pointer to `napc__RingBuffer` instance.
	 * @param bytes Bytes to store in circular buffer.
	 * @param bytes_size Size of `bytes` array.
	 * @changelog 2.0.0 21.10.2022 initial version
	 * @return
	 * Returns `true` if the bytes were successfully written to the buffer.
	 * @notes
	 * If the array `bytes` does not fit in the buffer, no action is performed.
	 */
	bool napc_RingBuffer_insertBytes(napc__RingBuffer *ctx, const napc_u8 *bytes, napc_size bytes_size);

	/*!
	 * @name napc_RingBuffer_forceInsertByte
	 * @brief Insert a byte.
	 * @version 2.0.0
	 * @param ctx Pointer to `napc__RingBuffer` instance.
	 * @param byte Byte to store in circular buffer.
	 * @changelog 2.0.0 21.10.2022 initial version
	 * @warning
	 * If the buffer is full the byte `byte` will be forcefully inserted.
	 */
	void napc_RingBuffer_forceInsertByte(napc__RingBuffer *ctx, napc_u8 byte);

	/*!
	 * @name napc_RingBuffer_reset
	 * @brief Reset buffer.
	 * @version 2.0.0
	 * @description
	 * Resets the write and read position of a buffer.
	 * @param ctx Pointer to `napc__RingBuffer` instance.
	 * @changelog 2.0.0 21.10.2022 initial version
	 * @notes
	 * This does not clear the data in the underlying buffer.
	 * 
	 * Only the write and read positions are reset.
	 */
	void napc_RingBuffer_reset(napc__RingBuffer *ctx);

	/*!
	 * @name napc_RingBuffer_discardByte
	 * @brief Discard a single byte.
	 * @version 2.0.0
	 * @description
	 * Discards a single byte from the buffer.
	 * @param ctx Pointer to `napc__RingBuffer` instance.
	 * @changelog 2.0.0 21.10.2022 initial version
	 */
	void napc_RingBuffer_discardByte(napc__RingBuffer *ctx);

	/*!
	 * @name napc_RingBuffer_discardBytes
	 * @brief Discard a number of bytes.
	 * @version 2.0.0
	 * @description
	 * Discards `amount` of bytes from the buffer.
	 * @param ctx Pointer to `napc__RingBuffer` instance.
	 * @param amount Amount of bytes to discard.
	 * @changelog 2.0.0 21.10.2022 initial version
	 * @notes
	 * No error checking is done, if buffer is smaller than `amount` the maximum amount
	 * of bytes (i.e. all bytes in the buffer) are discarded.
	 */
	void napc_RingBuffer_discardBytes(napc__RingBuffer *ctx, napc_size amount);
#endif
