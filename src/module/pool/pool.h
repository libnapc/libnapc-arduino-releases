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
 * @name Pool:intro
 * @brief Static memory allocation
 */
#if !defined(NAPC_MODULE_POOL_h)
	#define NAPC_MODULE_POOL_h

	#include <libnapc.h>
	#include <napc-magic/napc-magic.h>

	#define NAPC_POOL_MAX   32

	/*!
	 * @name napc__Pool
	 * @module Pool
	 * @brief Represenation of a fixed memory pool.
	 * @version 1.0.0
	 * @opaque
	 * @changelog 1.0.0 17.02.2022 initial version
	 */
	typedef struct napc__Pool {
		NAPC_MAGIC_MEMBER;

		const char *label;

		unsigned char *array_start;
		bool elements_used[NAPC_POOL_MAX];

		napc_size num_elements;
		napc_size element_size;
	} napc__Pool;

	/*!
	 * @name napc_Pool_init
	 * @brief Initialize a static pool.
	 * @version 1.0.0
	 * @description
	 * Initializes a static (fixed sized) pool.
	 * @param pool Pointer to the instance.
	 * @param pool_label Label for pool. (must be a constant)
	 * @param array_start Start address of array (to be used by the pool)
	 * @param num_elements Number of elements in array.
	 * @param element_size Size (in bytes) of a single element in the array.
	 * @changelog 1.0.0 17.02.2022 initial version
	 * @example
	 * int buffer[5];
	 * napc_Pool pool;
	 * 
	 * napc_Pool_init(&pool, "int pool", buffer, 5, sizeof(int));
	 * 
	 * napc_ssize id = napc_Pool_allocate(&pool);
	 * 
	 * int *first_element = napc_Pool_getAddress(&pool, id);
	 */
	void napc_Pool_init(
		napc__Pool *pool,
		const char *pool_label,
		void *array_start,
		napc_size num_elements,
		napc_size element_size
	);

	/*!
	 * @name napc_Pool_claimElement
	 * @brief Claim an element of a pool.
	 * @version 1.0.1
	 * @description
	 * Allocates an element from the pool `pool`.
	 * @param pool Pointer to napc__Pool instance.
	 * @warning
	 * If the pool is exhausted program execution is halted.
	 * @changelog 1.0.1 17.03.2022 initial version
	 */
	napc_ssize napc_Pool_claimElement(
		napc__Pool *pool
	);

	/*!
	 * @name napc_Pool_allocate
	 * @deprecated napc_Pool_claimElement
	 * @brief Allocate an element of a pool.
	 * @version 1.0.1
	 * @description
	 * Allocates an element from the pool `pool`.
	 * @param pool Pointer to napc__Pool instance.
	 * @warning
	 * If the pool is exhausted program execution is halted.
	 * @changelog 1.0.0 17.02.2022 initial version
	 * @changelog 1.0.1 17.03.2022 added deprecation warning
	 */
	napc_ssize napc_Pool_allocate(
		napc__Pool *pool
	) NAPC_DEPRECATED();

	/*!
	 * @name napc_Pool_isClaimed
	 * @brief Check if element is claimed.
	 * @version 1.0.1
	 * @description
	 * Checks if a particular element is allocated (in use) or not.
	 * @param pool Pointer to napc__Pool instance.
	 * @param element_index Index of element to check.
	 * @changelog 1.0.1 17.03.2022 initial version
	 */
	bool napc_Pool_isClaimed(
		const napc__Pool *pool,
		napc_size element_index
	) NAPC_FN_WARNUNUSED_RET();

	/*!
	 * @name napc_Pool_isAllocated
	 * @deprecated napc_Pool_isClaimed
	 * @brief Check if element is allocated.
	 * @version 1.0.1
	 * @description
	 * Checks if a particular element is allocated (in use) or not.
	 * @param pool Pointer to napc__Pool instance.
	 * @param element_index Index of element to check.
	 * @changelog 1.0.0 17.02.2022 initial version
	 * @changelog 1.0.1 17.03.2022 added deprecation warning
	 */
	bool napc_Pool_isAllocated(
		const napc__Pool *pool,
		napc_size element_index
	) NAPC_FN_WARNUNUSED_RET() NAPC_DEPRECATED();

	/*!
	 * @name napc_Pool_getAvailable
	 * @brief Get available elements.
	 * @version 1.0.0
	 * @description
	 * Get the number of available elements in the pool.
	 * @param pool Pointer to napc__Pool instance.
	 * @return Returns the number of available elements in the pool.
	 * @changelog 1.0.0 17.02.2022 initial version
	 */
	napc_size napc_Pool_getAvailable(
		const napc__Pool *pool
	);

	/*!
	 * @name napc_Pool_getAddress
	 * @brief Get address of an element.
	 * @version 1.0.0
	 * @description
	 * Gets the address of an allocated element in the pool.
	 * @param pool Pointer to napc__Pool instance.
	 * @param element_index Index of element.
	 * @return The element's address.
	 * @warning
	 * This function can only be used to get the address of allocated elements in the pool.
	 * @changelog 1.0.0 17.02.2022 initial version
	 * @example
	 * int buffer[5];
	 * napc_Pool pool;
	 * 
	 * napc_Pool_init(&pool, "int pool", buffer, 5, sizeof(int));
	 * 
	 * napc_ssize id = napc_Pool_allocate(&pool);
	 * 
	 * int *first_element = napc_Pool_getAddress(&pool, id);
	 */
	void *napc_Pool_getAddress(
		const napc__Pool *pool,
		napc_size element_index
	);

	/*!
	 * @name napc_Pool_releaseElement
	 * @brief Release an element.
	 * @version 1.0.0
	 * @description
	 * Releases an element from the pool.
	 * @param pool Pointer to napc__Pool instance.
	 * @param element_index Index of element.
	 * @changelog 1.0.1 17.03.2022 initial version
	 */
	void napc_Pool_releaseElement(
		napc__Pool *pool,
		napc_size element_index
	);

	/*!
	 * @name napc_Pool_release
	 * @deprecated napc_Pool_releaseElement
	 * @brief Release an element.
	 * @version 1.0.1
	 * @description
	 * Releases an element from the pool.
	 * @param pool Pointer to napc__Pool instance.
	 * @param element_index Index of element.
	 * @changelog 1.0.0 17.02.2022 initial version
	 * @changelog 1.0.1 17.03.2022 added deprecation warning
	 */
	void napc_Pool_release(
		napc__Pool *pool,
		napc_size element_index
	) NAPC_DEPRECATED();
#endif

// maybe release -> releaseElement (release is ambig)
// 
