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
/** 
* libnapc
* (c) by nap.software
* 
* Reference at https://libnapc.nap-software/
* 
* Version    : 1.5.34
* Git commit : f2c1d55509376f412e90916891b47f273e780d92
*/
#if !defined(NAPC_h)
	#define NAPC_h

	#if defined(__cplusplus)
		extern "C" {
	#endif

	/*!
	 * @name napc_version
	 * @brief Get the version of libnapc.
	 * @version 1.2.0
	 * @description
	 * Return the version string of libnapc.
	 * @changelog 1.2.0 20.03.2022 initial version
	 * @example
	 * napc_printf("Using libnapc version: %s\n", napc_version());
	 */
	const char *napc_version(void);

	/*!
	 * @name napc_getFullVersion
	 * @brief Get the full version of libnapc.
	 * @version 1.3.0
	 * @description
	 * Return the full version string of libnapc.
	 * @changelog 1.3.0 21.03.2022 initial version
	 * @example
	 * napc_printf("Using libnapc version: %s\n", napc_getFullVersion());
	 */
	const char *napc_getFullVersion(void);


/* original: #include <napc-serial/napc-serial.h> */
    #if !defined(NAPC_SERIAL_h)
    	#define NAPC_SERIAL_h
    

/* original: #include <libnapc.h> */
        #if !defined(LIBNAPC_h)
        	#define LIBNAPC_h
        

/* original: #include <stdbool.h> // bool */
        #include <stdbool.h> // bool

/* original: #include <stdlib.h> // NULL, free() */
        #include <stdlib.h> // NULL, free()

/* original: #include <stdarg.h> // va_list */
        #include <stdarg.h> // va_list
        
        	// Source: https://stackoverflow.com/a/39618857/2005038
        	/* Normally casting an expression to void discards its value, but GCC
        	   versions 3.4 and newer have __attribute__ ((__warn_unused_result__))
        	   which may cause unwanted diagnostics in that case.  Use __typeof__
        	   and __extension__ to work around the problem, if the workaround is
        	   known to be needed.  */
        	#if 3 < __GNUC__ + (4 <= __GNUC_MINOR__)
        		#define NAPC_IGNORE_VALUE(x) \
        			(__extension__ ({ __typeof__ (x) __x = (x); (void) __x; }))
        	#else
        		#define NAPC_IGNORE_VALUE(x) ((void) (x))
        	#endif
        
        	#define NAPC_CONCAT_(a, b) a ## b
        	#define NAPC_CONCAT(a, b) NAPC_CONCAT_(a, b)
        
        	#define NAPC_FN_PRINTFLIKE(_1, _2) __attribute__((format(printf, _1, _2)))
        
        	/*!
        	 * @name NAPC_FN_WARNUNUSED_RET
        	 * @module Core
        	 * @version 1.0.0
        	 * @description
        	 * Tell the compiler to emit a warning if the return value of a function is not used.
        	 * @changelog 1.0.0 17.02.2022 initial version
        	 * @example
        	 * int my_function() NAPC_FN_WARNUNUSED_RET() {
        	 *     return 4;
        	 * }
        	 * 
        	 * void napc_setup(const char *platform) {
        	 *     my_function(); // will generate a compiler warning
        	 * }
        	 * 
        	 * bool napc_loop(napc_time uptime) {
        	 *     return false;
        	 * }
        	 */
        	#define NAPC_FN_WARNUNUSED_RET()   __attribute__((warn_unused_result))
        	#define NAPC_FN_NOINLINE()         __attribute__((noinline))
        	#define NAPC_FN_NORETURN()         __attribute__((noreturn))
        	#define NAPC_UNUSED_FN_PARAM()     __attribute__((unused))
        	#define NAPC_FN_WEAK()             __attribute__((weak))
        
        	#define NAPC_DEPRECATED_WITH_MESSAGE(_message, _replacement) \
        			__attribute__((deprecated(_message, _replacement)))
        
        	#define NAPC_DEPRECATED() \
        			__attribute__((deprecated))
        
        	#define NAPC_ARRAY_ELEMENTS(array) (sizeof(array) / sizeof(* array))
        
        	// give compiler a hint that `expr` is likely to evaluate to 'false'
        	#define NAPC_UNLIKELY(expr) \
        		__builtin_expect(!!(expr), 0)
        
        	// give compiler a hint that `expr` is likely to evaluate to 'true'
        	#define NAPC_LIKELY(expr) \
        		__builtin_expect(!!(expr), 1)
        

/* original: #include <inttypes/inttypes.h> */
            #if !defined(NAPC_INTTYPES_h)
            	#define NAPC_INTTYPES_h
            

/* original: #include <inttypes/8bit/napc_u8.h> // napc_u8 */
                #if !defined(NAPC_INTTYPES_U8_h)
                	#define NAPC_INTTYPES_U8_h
                

/* original: #include <stdint.h> // uint8_t */
                #include <stdint.h> // uint8_t

/* original: #include <inttypes.h> // PRIu8 */
                #include <inttypes.h> // PRIu8
                
                	/*!
                	 * @name napc_u8
                	 * @brief 8 bit wide unsigned integer 
                	 * @version 1.0.0
                	 * @description
                	 * Type for unsigned integers with 8 bits width.
                	 * @changelog 1.0.0 17.02.2022 initial version
                	 */
                	typedef uint8_t napc_u8;
                
                	/*!
                	 * @name NAPC_U8_LITERAL
                	 * @module Core
                	 * @version 1.0.0
                	 * @description
                	 * Used for literal unsigned integers with 8 bits width.
                	 * @param n/a value Value
                	 * @rationale
                	 * This macro is only included for consistency's sake.
                	 * @changelog 1.0.0 17.02.2022 initial version
                	 * @example
                	 * napc_u8 var = NAPC_U8_LITERAL(20);
                	 */
                	#define NAPC_U8_LITERAL(value)  UINT8_C(value)
                
                	/*!
                	 * @name NAPC_U8_PRINTF
                	 * @module Core
                	 * @version 1.0.0
                	 * @description
                	 * Format specifier for printing `napc_u8` variables.
                	 * @rationale
                	 * This macro is only included for consistency's sake.
                	 * @changelog 1.0.0 17.02.2022 initial version
                	 * @example
                	 * napc_u8 var = 1;
                	 * 
                	 * napc_printf("var is = %" NAPC_U8_PRINTF, var);
                	 */
                	#define NAPC_U8_PRINTF       PRIu8
                #endif

/* original: #include <inttypes/8bit/napc_i8.h> // napc_i8 */
                #if !defined(NAPC_INTTYPES_I8_h)
                	#define NAPC_INTTYPES_I8_h
                

/* original: #include <stdint.h> // int8_t */
                #include <stdint.h> // int8_t

/* original: #include <inttypes.h> // */
                #include <inttypes.h> //
                
                	/*!
                	 * @name napc_i8
                	 * @brief 8 bit wide signed integer 
                	 * @version 1.0.0
                	 * @description
                	 * Type for signed integers with 8 bits width.
                	 * @changelog 1.0.0 17.02.2022 initial version
                	 */
                	typedef int8_t napc_i8;
                #endif
            

/* original: #include <inttypes/16bit/napc_u16.h> // napc_u16 */
                #if !defined(NAPC_INTTYPES_U16_h)
                	#define NAPC_INTTYPES_U16_h
                

/* original: #include <stdint.h> // uint16_t */
                #include <stdint.h> // uint16_t

/* original: #include <inttypes.h> // PRIu16 */
                #include <inttypes.h> // PRIu16
                
                	/*!
                	 * @name napc_u16
                	 * @brief 16 bit wide unsigned integer 
                	 * @version 1.0.0
                	 * @description
                	 * Type for unsigned integers with 16 bits width.
                	 * @changelog 1.0.0 17.02.2022 initial version
                	 */
                	typedef uint16_t napc_u16;
                
                	/*!
                	 * @name NAPC_U16_LITERAL
                	 * @module Core
                	 * @version 1.0.0
                	 * @description
                	 * Used for literal unsigned integers with 16 bits width.
                	 * @param n/a value Value
                	 * @rationale
                	 * This macro is only included for consistency's sake.
                	 * @changelog 1.0.0 17.02.2022 initial version
                	 * @example
                	 * napc_u16 var = NAPC_U16_LITERAL(1234);
                	 */
                	#define NAPC_U16_LITERAL(value) UINT16_C(value)
                
                	/*!
                	 * @name NAPC_U16_PRINTF
                	 * @module Core
                	 * @version 1.0.0
                	 * @description
                	 * Format specifier for printing `napc_u16` variables.
                	 * @rationale
                	 * This macro is only included for consistency's sake.
                	 * @changelog 1.0.0 17.02.2022 initial version
                	 * @example
                	 * napc_u16 var = 1;
                	 * 
                	 * napc_printf("var is = %" NAPC_U16_PRINTF, var);
                	 */
                	#define NAPC_U16_PRINTF      PRIu16
                #endif

/* original: #include <inttypes/16bit/napc_i16.h> // napc_i16 */
                #if !defined(NAPC_INTTYPES_I16_h)
                	#define NAPC_INTTYPES_I16_h
                

/* original: #include <stdint.h> */
                #include <stdint.h>

/* original: #include <inttypes.h> */
                #include <inttypes.h>
                
                	/*!
                	 * @name napc_i16
                	 * @brief 16 bit wide signed integer 
                	 * @version 1.0.0
                	 * @description
                	 * Type for signed integers with 16 bits width.
                	 * @changelog 1.0.0 17.02.2022 initial version
                	 */
                	typedef int16_t napc_i16;
                #endif
            

/* original: #include <inttypes/32bit/napc_u32.h> // napc_u32 */
                #if !defined(NAPC_INTTYPES_U32_h)
                	#define NAPC_INTTYPES_U32_h
                

/* original: #include <stdint.h> // uint32_t */
                #include <stdint.h> // uint32_t

/* original: #include <inttypes.h> // PRIu32 */
                #include <inttypes.h> // PRIu32
                
                	/*!
                	 * @name napc_u32
                	 * @brief 32 bit wide unsigned integer 
                	 * @version 1.0.0
                	 * @description
                	 * Type for unsigned integers with 32 bits width.
                	 * @changelog 1.0.0 17.02.2022 initial version
                	 */
                	typedef uint32_t napc_u32;
                
                	/*!
                	 * @name NAPC_U32_LITERAL
                	 * @module Core
                	 * @version 1.0.0
                	 * @description
                	 * Used for literal unsigned integers with 32 bits width.
                	 * @param n/a value Value
                	 * @changelog 1.0.0 17.02.2022 initial version
                	 * @example
                	 * napc_u32 var = NAPC_U32_LITERAL(12345);
                	 */
                	#define NAPC_U32_LITERAL(value) UINT32_C(value)
                
                	/*!
                	 * @name NAPC_U32_PRINTF
                	 * @module Core
                	 * @version 1.0.0
                	 * @description
                	 * Format specifier for printing `napc_u32` variables.
                	 * @changelog 1.0.0 17.02.2022 initial version
                	 * @example
                	 * napc_u32 var = 1;
                	 * 
                	 * napc_printf("var is = %" NAPC_U32_PRINTF, var);
                	 */
                	#define NAPC_U32_PRINTF      PRIu32
                #endif

/* original: #include <inttypes/32bit/napc_i32.h> // napc_i32 */
                #if !defined(NAPC_INTTYPES_I32_h)
                	#define NAPC_INTTYPES_I32_h
                

/* original: #include <stdint.h> */
                #include <stdint.h>

/* original: #include <inttypes.h> */
                #include <inttypes.h>
                
                	/*!
                	 * @name napc_i32
                	 * @brief 32 bit wide signed integer 
                	 * @version 1.0.0
                	 * @description
                	 * Type for signed integers with 32 bits width.
                	 * @changelog 1.0.0 17.02.2022 initial version
                	 */
                	typedef int32_t napc_i32;
                #endif
            

/* original: #include <inttypes/size.h> // napc_size */
                #if !defined(NAPC_INTTYPES_SIZE_h)
                	#define NAPC_INTTYPES_SIZE_h
                
                	/*!
                	 * @name napc_size
                	 * @brief Memory size type.
                	 * @version 1.0.0
                	 * @description
                	 * Unsigned integer type for holding object sizes.
                	 * @rationale
                	 * Used because Arduino lacks `size_t` in `<stddef.h>`.
                	 * 
                	 * For some reason it is defined in `<stdio.h>` but
                	 * I don't want to pollute my headers with unnecessary
                	 * includes.
                	 * 
                	 * Also this way, I'm sure what printf specifiers
                	 * to use when printing `size_t` resp. `ssize_t`.
                	 * 
                	 * (`%zu` is not supported in arduino's libc)
                	 * @changelog 1.0.0 17.02.2022 initial version
                	 */
                	typedef unsigned long napc_size;
                
                	// For napc_size literals
                	#define NAPC_SIZE_LITERAL(_v) _v ## ul
                
                	/*!
                	 * @name NAPC_SIZE_PRINTF
                	 * @module Core
                	 * @version 1.0.0
                	 * @description
                	 * Format specifier for printing `napc_size` variables.
                	 * @changelog 1.0.0 17.02.2022 initial version
                	 * @example
                	 * napc_size var = 1;
                	 * 
                	 * napc_printf("var is = %" NAPC_SIZE_PRINTF, var);
                	 */
                	#define NAPC_SIZE_PRINTF "lu"
                #endif

/* original: #include <inttypes/ssize.h> // napc_ssize */
                #if !defined(NAPC_INTTYPES_SSIZE_h)
                	#define NAPC_INTTYPES_SSIZE_h
                
                	/*!
                	 * @name napc_ssize
                	 * @brief Signed memory size type.
                	 * @version 1.0.0
                	 * @description
                	 * Signed integer type for holding object sizes.
                	 * @rationale
                	 * Used because Arduino lacks `ssize_t` in `<stddef.h>`.
                	 * 
                	 * For some reason it is defined in `<stdio.h>` but
                	 * I don't want to pollute my headers with unnecessary
                	 * includes.
                	 * 
                	 * Also this way, I'm sure what printf specifiers
                	 * to use when printing `size_t` resp. `ssize_t`.
                	 * 
                	 * (`%zd` is not supported in arduino's libc)
                	 * @changelog 1.0.0 17.02.2022 initial version
                	 */
                	typedef signed long napc_ssize;
                
                	// For napc_ssize literals
                	#define NAPC_SSIZE_LITERAL(_v) _v ## l
                
                	/*!
                	 * @name NAPC_SSIZE_PRINTF
                	 * @module Core
                	 * @version 1.0.0
                	 * @description
                	 * Format specifier for printing `napc_ssize` variables.
                	 * @changelog 1.0.0 17.02.2022 initial version
                	 * @example
                	 * napc_ssize var = -1;
                	 * 
                	 * napc_printf("var is = %" NAPC_SSIZE_PRINTF, var);
                	 */
                	#define NAPC_SSIZE_PRINTF "ld"
                #endif

/* original: #include <inttypes/time.h> // napc_time */
                #if !defined(NAPC_INTTYPES_TIME_h)
                	#define NAPC_INTTYPES_TIME_h
                

/* original: #include <inttypes/32bit/napc_u32.h> */
/* header file already included */
                
                	/*!
                	 * @name napc_time
                	 * @brief Unsigned timestamp int type.
                	 * @version 1.0.0
                	 * @description
                	 * Unsigned integer type for holding timestamps.
                	 * @changelog 1.0.0 17.02.2022 initial version
                	 */
                	typedef napc_u32 napc_time;
                
                	// For napc_time literals
                	#define NAPC_TIME_LITERAL(_v) NAPC_U32_LITERAL(_v)
                
                	/*!
                	 * @name NAPC_TIME_PRINTF
                	 * @module Core
                	 * @version 1.0.0
                	 * @description
                	 * Format specifier for printing `napc_time` variables.
                	 * @changelog 1.0.0 17.02.2022 initial version
                	 * @example
                	 * napc_time var = 1;
                	 * 
                	 * napc_printf("var is = %" NAPC_TIME_PRINTF, var);
                	 */
                	#define NAPC_TIME_PRINTF PRIu32
                #endif
            #endif
        #endif
    
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

/* original: #include <napc-time/napc-time.h> */
    #if !defined(NAPC_TIME_h)
    	#define NAPC_TIME_h
    

/* original: #include <libnapc.h> */
/* header file already included */
    
    	/*!
    	 * @name napc_getTimeSinceBoot
    	 * @brief Get time since boot.
    	 * @version 1.0.0
    	 * @description
    	 * Return number of milliseconds that have passed since boot.
    	 * @warning
    	 * The value returned by this function will overflow at some point in time.
    	 * @flags hw
    	 * @changelog 1.0.0 17.02.2022 initial version
    	 */
    	napc_time napc_getTimeSinceBoot(void) NAPC_FN_WARNUNUSED_RET();
    
    	/*!
    	 * @name napc_getTimeSinceBootHR
    	 * @brief Get time since boot in microseconds.
    	 * @version 2.0.0
    	 * @description
    	 * Return number of microseconds that have passed since boot.
    	 * @warning
    	 * The value returned by this function will overflow at some point in time.
    	 * @flags hw
    	 * @changelog 2.0.0 21.10.2022 initial version
    	 */
    	napc_time napc_getTimeSinceBootHR(void) NAPC_FN_WARNUNUSED_RET();
    #endif

/* original: #include <napc-delay/napc-delay.h> */
    #if !defined(NAPC_DELAY_h)
    	#define NAPC_DELAY_h
    

/* original: #include <libnapc.h> */
/* header file already included */
    
    	/*!
    	 * @name napc_delay
    	 * @brief Delay program execution.
    	 * @version 1.0.0
    	 * @description Delay program execution.
    	 * @warning
    	 * This function will block execution for a set amount of time.
    	 * 
    	 * It's better to use non-blocking code, see `napc__Timer` and `napc__HRTimer`.
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
    	 * @warning
    	 * This function will block execution for a set amount of time.
    	 * 
    	 * It's better to use non-blocking code, see `napc__Timer` and `napc__HRTimer`.
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

/* original: #include <napc-utils/napc-utils.h> */
    #if !defined(NAPC_UTILS_h)
    	#define NAPC_UTILS_h
    

/* original: #include <libnapc.h> */
/* header file already included */
    
    	/*!
    	 * @name napc_snprintf
    	 * @brief Format printf()-like string.
    	 * @version 1.0.0
    	 * @rationale
    	 * The `snprintf()` function defined by the C-Standard does not guarantee that the resulting string is NUL-terminated.
    	 * 
    	 * This function ensures the resulting string is always NUL-terminated.
    	 * @param buffer The buffer to write the formatted string to.
    	 * @param buffer_size The size of the buffer.
    	 * @param fmt printf()-like format string.
    	 * @param ... Values to incorporate into string.
    	 * @changelog 1.0.0 17.02.2022 initial version
    	 * @example
    	 * char buffer[512];
    	 * 
    	 * napc_snprintf(buffer, sizeof(buffer), "Hello %s!", "World!");
    	 * 
    	 * // buffer now contains 'Hello World!'
    	 */
    	void napc_snprintf(
    		char *buffer,
    		napc_size buffer_size,
    		const char *fmt,
    		...
    	) NAPC_FN_PRINTFLIKE(3, 4);
    
    	/*!
    	 * @name napc_vsnprintf
    	 * @brief Format printf()-like string.
    	 * @version 1.0.0
    	 * @description
    	 * Same as `napc_snprintf()` except it takes a `va_args` list instead of variadic arguments.
    	 * @param buffer The buffer to write the formatted string to.
    	 * @param buffer_size The size of the buffer.
    	 * @param fmt printf()-like format string.
    	 * @changelog 1.0.0 17.02.2022 initial version
    	 */
    	void napc_vsnprintf(
    		char *buffer,
    		napc_size buffer_size,
    		const char *fmt,
    		va_list args
    	);
    
    	/*!
    	 * @name napc_strncpy
    	 * @brief Copy a string.
    	 * @version 1.0.0
    	 * @description
    	 * Copy a string to another location.
    	 * @rationale
    	 * The `strncpy()` function defined by the C-Standard does not guarantee that the resulting string is NUL-terminated.
    	 * 
    	 * This function ensures the resulting string is always NUL-terminated.
    	 * @param dest Destination memory location.
    	 * @param source String to be copied to dest.
    	 * @param dest_size Size of destination.
    	 * @changelog 1.0.0 17.02.2022 initial version
    	 */
    	void napc_strncpy(char *dest, const char *source, napc_size dest_size);
    
    	/*!
    	 * @name napc_strlen
    	 * @brief Get length of string.
    	 * @version 1.0.0
    	 * @description
    	 * Count the number of characters in a string.
    	 * @notes
    	 * This is just an alias for `strlen()`.
    	 * @param str The string to be measured.
    	 * @return Returns the length of the string.
    	 * @changelog 1.0.0 17.02.2022 initial version
    	 * @example
    	 * napc_size str_length = napc_strlen("Hello World!");
    	 * 
    	 * napc_printf("String's length is %" NAPC_SIZE_PRINTF "\n", str_length);
    	 */
    	napc_size napc_strlen(const char *str) NAPC_FN_WARNUNUSED_RET();
    
    	/*!
    	 * @name napc_streql
    	 * @brief Compare two strings.
    	 * @version 1.0.0
    	 * @description
    	 * Perform case sensitive string comparsion.
    	 * @rationale
    	 * It's cumbersome to write `strcmp(str1, str2) == 0` to compare strings.
    	 * @param str1 First string.
    	 * @param str2 Second string.
    	 * @return Returns `true` if `str1` and `str2` are equal in contents.
    	 * @changelog 1.0.0 17.02.2022 initial version
    	 * @example
    	 * napc_streql("my_string", "my_string"); // returns true
    	 * 
    	 * napc_streql("my_string", "mY_sTring"); // returns false
    	 * 
    	 * napc_streql("my_string", "my_second_string"); // returns false
    	 */
    	bool napc_streql(const char *str1, const char *str2) NAPC_FN_WARNUNUSED_RET();
    
    	/*!
    	 * @name napc_streqli
    	 * @brief Compare two strings.
    	 * @version 1.0.0
    	 * @description
    	 * Perform case insensitive string comparsion.
    	 * @rationale
    	 * It's cumbersome to write `strcasecmp(str1, str2) == 0` to compare strings.
    	 * @param str1 First string.
    	 * @param str2 Second string.
    	 * @return Returns `true` if `str1` and `str2` are equal in contents.
    	 * @changelog 1.0.0 17.02.2022 initial version
    	 * @example
    	 * napc_streqli("my_string", "mY_sTring"); // returns true
    	 * 
    	 * napc_streqli("my_string", "my_second_string"); // returns false
    	 */
    	bool napc_streqli(const char *str1, const char *str2) NAPC_FN_WARNUNUSED_RET();
    
    	/*!
    	 * @name napc_memeql
    	 * @brief Compare two memory regions of equal size.
    	 * @version 1.0.0
    	 * @description
    	 * Compare two memory regions.
    	 * @param data1 Pointer to first memory location.
    	 * @param data2 Pointer to second memory location.
    	 * @param data_size Size of `data1` (resp. `data2`) in bytes.
    	 * @return Returns `true` if `data1` and `data2` have the same content.
    	 * @notes
    	 * The two memory regions need to be of the same size.
    	 * @rationale
    	 * It's cumbersome to write `memcmp(data1, data2, data_size) == 0` to compare memory blocks.
    	 * @changelog 1.0.0 17.02.2022 initial version
    	 * @example
    	 * char data1[3] = {0, 0, 7};
    	 * char data2[3] = {0, 0, 7};
    	 * 
    	 * if (napc_memeql(data1, data2, 3)) {
    	 *     napc_printf("data1 and data2 have the same content");
    	 * }
    	 */
    	bool napc_memeql(const void *data1, const void *data2, napc_size data_size) NAPC_FN_WARNUNUSED_RET();
    
    	/*!
    	 * @name napc_mzero
    	 * @brief Zero out memory region.
    	 * @version 1.0.0
    	 * @description
    	 * Clear memory section.
    	 * @param data Buffer to be zero'd out.
    	 * @param data_size Size of `data` buffer.
    	 * @rationale
    	 * It's cumbersome to write `memset(data, 0, data_size)`.
    	 * @changelog 1.0.0 17.02.2022 initial version
    	 * @example
    	 * char buffer[512];
    	 * 
    	 * // clear data buffer
    	 * napc_mzero(buffer, sizeof(buffer));
    	 */
    	void napc_mzero(void *data, napc_size data_size);
    #endif

/* original: #include <napc-panic/napc-panic.h> */
    #if !defined(NAPC_PANIC_h)
    	#define NAPC_PANIC_h
    

/* original: #include <libnapc.h> */
/* header file already included */
    
    	void napc_halt(
    		const char *file,
    		int file_line,
    		const char *fn,
    		const char *fmt,
    		...
    	) NAPC_FN_PRINTFLIKE(4, 5);
    
    	/*!
    	 * @name NAPC_PANIC
    	 * @module Core
    	 * @brief Abort program execution.
    	 * @version 1.0.0
    	 * @description
    	 * Abort program execution and print a message.
    	 * @param _cstring_ fmt printf()-like format string.
    	 * @param n/a ... Values to incorporate into string.
    	 * @changelog 1.0.0 17.02.2022 initial version
    	 * @example
    	 * NAPC_PANIC("Some error occurred: %s", "Could not open file");
    	 */
    	#define NAPC_PANIC(fmt, ...) \
    		napc_halt(__FILE__, __LINE__, __func__, fmt, ## __VA_ARGS__)
    #endif

/* original: #include <napc-core/napc-core.h> */
    #if !defined(NAPC_CORE_h)
    	#define NAPC_CORE_h
    

/* original: #include <libnapc.h> */
/* header file already included */
    

/* original: #include <napc-panic/napc-panic.h> */
/* header file already included */
    
    	extern void napc_setup(const char *platform);
    	extern bool napc_loop(napc_time uptime);
    
    	/*!
    	 * @name napc_getUptime
    	 * @brief Get uptime in seconds.
    	 * @version 1.0.0
    	 * @description
    	 * Get the uptime in seconds.
    	 * @return Returns the number of seconds that have passed since boot.
    	 * @flags hw
    	 * @changelog 1.0.0 17.02.2022 initial version
    	 * @example
    	 * napc_time uptime = napc_getUptime();
    	 * 
    	 * napc_printf("I'm up since %" NAPC_TIME_PRINTF " seconds", uptime);
    	 */
    	napc_time napc_getUptime(void) NAPC_FN_WARNUNUSED_RET();
    
    	/*!
    	 * @name napc_getFreeMemory
    	 * @brief Get available memory.
    	 * @version 1.0.0
    	 * @return
    	 * Returns the number of free bytes (on the stack) available.
    	 * @flags hw
    	 * @changelog 1.0.0 17.02.2022 initial version
    	 */
    	napc_size napc_getFreeMemory(void) NAPC_FN_WARNUNUSED_RET();
    
    	/*!
    	 * @name NAPC_ASSERT
    	 * @module Core
    	 * @brief Make an assertion.
    	 * @version 1.0.0
    	 * @description
    	 * Assert an expression.
    	 * @param bool expr Expression to assert.
    	 * @changelog 1.0.0 17.02.2022 initial version
    	 * @example
    	 * napc_u8 var = 13;
    	 * 
    	 * NAPC_ASSERT(var == 13);
    	 */
    	#define NAPC_ASSERT(expr)                    \
    		do {                                     \
    			if (!(expr)) {                       \
    				NAPC_PANIC("Assertion failed."); \
    			}                                    \
    		} while(false)
    #endif

/* original: #include <napc-log/napc-log.h> */
    #if !defined(NAPC_LOG_h)
    	#define NAPC_LOG_h
    

/* original: #include <libnapc.h> */
/* header file already included */
    
    	void napc_logMessage(
    		const char *subsys,
    		int level,
    		const char *function,
    		const char *fmt, ...
    	) NAPC_FN_PRINTFLIKE(4, 5);
    
    	typedef void (*napc_logHandlerFunction)(
    		void *context,
    		const char *subsys,
    		int level,
    		const char *function,
    		const char *message
    	);
    
    	/*!
    	 * @name napc_addLogHandlerFunction
    	 * @brief Add log handler function
    	 * @version 2.0.0
    	 * @param handler The log handler function
    	 * @param context Context to be passed to function
    	 * @return
    	 * On success a number that can be passed to `napc_removeLogHandlerFunction`.
    	 * 
    	 * Otherwise a negative number is returned.
    	 * @changelog 2.0.0 12.04.2022 initial version
    	 */
    	napc_ssize napc_addLogHandlerFunction(
    		napc_logHandlerFunction handler, void *context
    	);
    
    	/*!
    	 * @name napc_removeLogHandlerFunction
    	 * @brief Remove a log handler function
    	 * @version 2.0.0
    	 * @param log_handler_index Handler index returned by `napc_addLogHandlerFunction`
    	 * @changelog 2.0.0 12.04.2022 initial version
    	 */
    	void napc_removeLogHandlerFunction(
    		napc_size log_handler_index
    	);
    
    	/*!
    	 * @name NAPC_LEVEL_VERBOSE
    	 * @module Core
    	 * @version 1.0.0
    	 * @description
    	 * Representation of log priority `verbose`.
    	 * @changelog 1.0.0 17.02.2022 initial version
    	 * @example
    	 * NAPC_LOG("subsystem", NAPC_LEVEL_VERBOSE, "This is a verbose log message.");
    	 */
    	#define NAPC_LEVEL_VERBOSE     0
    
    	/*!
    	 * @name NAPC_LEVEL_TRACE
    	 * @module Core
    	 * @version 1.0.0
    	 * @description
    	 * Representation of log priority `trace`.
    	 * @changelog 1.0.0 17.02.2022 initial version
    	 * @example
    	 * NAPC_LOG("subsystem", NAPC_LEVEL_TRACE, "This is a trace log message.");
    	 */
    	#define NAPC_LEVEL_TRACE       1
    
    	/*!
    	 * @name NAPC_LEVEL_DEBUG
    	 * @module Core
    	 * @version 1.0.0
    	 * @description
    	 * Representation of log priority `debug`.
    	 * @changelog 1.0.0 17.02.2022 initial version
    	 * @example
    	 * NAPC_LOG("subsystem", NAPC_LEVEL_DEBUG, "This is a debug log message.");
    	 */
    	#define NAPC_LEVEL_DEBUG       2
    
    	/*!
    	 * @name NAPC_LEVEL_INFO
    	 * @module Core
    	 * @version 1.0.0
    	 * @description
    	 * Representation of log priority `info`.
    	 * @changelog 1.0.0 17.02.2022 initial version
    	 * @example
    	 * NAPC_LOG("subsystem", NAPC_LEVEL_INFO, "This is an info log message.");
    	 */
    	#define NAPC_LEVEL_INFO        3
    
    	/*!
    	 * @name NAPC_LEVEL_WARNING
    	 * @module Core
    	 * @version 1.0.0
    	 * @description
    	 * Representation of log priority `warning`.
    	 * @changelog 1.0.0 17.02.2022 initial version
    	 * @example
    	 * NAPC_LOG("subsystem", NAPC_LEVEL_WARNING, "This is a warning log message.");
    	 */
    	#define NAPC_LEVEL_WARNING     4
    
    	/*!
    	 * @name NAPC_LEVEL_ERROR
    	 * @module Core
    	 * @version 1.0.0
    	 * @description
    	 * Representation of log priority `error`.
    	 * @changelog 1.0.0 17.02.2022 initial version
    	 * @example
    	 * NAPC_LOG("subsystem", NAPC_LEVEL_ERROR, "This is an error log message.");
    	 */
    	#define NAPC_LEVEL_ERROR       5
    
    	/*!
    	 * @name NAPC_LEVEL_SECURITY
    	 * @module Core
    	 * @version 1.0.0
    	 * @description
    	 * Representation of log priority `security`.
    	 * @changelog 1.0.0 17.02.2022 initial version
    	 * @example
    	 * NAPC_LOG("subsystem", NAPC_LEVEL_SECURITY, "This is a security log message.");
    	 */
    	#define NAPC_LEVEL_SECURITY    9
    
    	const char *napc_logLevelToString(int log_level) NAPC_FN_WARNUNUSED_RET();
    
    	/*!
    	 * @name NAPC_LOG
    	 * @module Core
    	 * @version 1.0.0
    	 * @description
    	 * Log a message with a specific priority.
    	 * @param _cstring_ subsys Subsystem.
    	 * @param int level Log level.
    	 * @param _cstring_ fmt printf()-like format string.
    	 * @param n/a ... Values to incorporate into string.
    	 * @changelog 1.0.0 17.02.2022 initial version
    	 * @example
    	 * NAPC_LOG("subsystem", NAPC_LEVEL_INFO, "This is a %s!", "message");
    	 */
    	#define NAPC_LOG(subsys, level, fmt, ...) \
    		napc_logMessage(                      \
    			subsys,                           \
    			level,                            \
    			__func__,                         \
    			fmt,                              \
    			## __VA_ARGS__                    \
    		)
    
    	/*!
    	 * @name NAPC_LOG_VERBOSE
    	 * @module Core
    	 * @version 1.0.0
    	 * @description
    	 * Log a message with priority `VERBOSE`.
    	 * @param _cstring_ subsys Subsystem.
    	 * @param _cstring_ fmt printf()-like format string.
    	 * @param n/a ... Values to incorporate into string.
    	 * @changelog 1.0.0 17.02.2022 initial version
    	 * @example
    	 * NAPC_LOG_VERBOSE("subsystem", "This is a %s!", "message");
    	 */
    	#define NAPC_LOG_VERBOSE(subsys, fmt, ...) \
    		NAPC_LOG(subsys, NAPC_LEVEL_VERBOSE, fmt, ## __VA_ARGS__)
    
    	/*!
    	 * @name NAPC_LOG_TRACE
    	 * @module Core
    	 * @version 1.0.0
    	 * @description
    	 * Log a message with priority `TRACE`.
    	 * @param _cstring_ subsys Subsystem.
    	 * @param _cstring_ fmt printf()-like format string.
    	 * @param n/a ... Values to incorporate into string.
    	 * @changelog 1.0.0 17.02.2022 initial version
    	 * @example
    	 * NAPC_LOG_TRACE("subsystem", "This is a %s!", "message");
    	 */
    	#define NAPC_LOG_TRACE(subsys, fmt, ...) \
    		NAPC_LOG(subsys, NAPC_LEVEL_TRACE, fmt, ## __VA_ARGS__)
    
    	/*!
    	 * @name NAPC_LOG_DEBUG
    	 * @module Core
    	 * @version 1.0.0
    	 * @description
    	 * Log a message with priority `DEBUG`.
    	 * @param _cstring_ subsys Subsystem.
    	 * @param _cstring_ fmt printf()-like format string.
    	 * @param n/a ... Values to incorporate into string.
    	 * @changelog 1.0.0 17.02.2022 initial version
    	 * @example
    	 * NAPC_LOG_DEBUG("subsystem", "This is a %s!", "message");
    	 */
    	#define NAPC_LOG_DEBUG(subsys, fmt, ...) \
    		NAPC_LOG(subsys, NAPC_LEVEL_DEBUG, fmt, ## __VA_ARGS__)
    
    	/*!
    	 * @name NAPC_LOG_INFO
    	 * @module Core
    	 * @version 1.0.0
    	 * @description
    	 * Log a message with priority `INFO`.
    	 * @param _cstring_ subsys Subsystem.
    	 * @param _cstring_ fmt printf()-like format string.
    	 * @param n/a ... Values to incorporate into string.
    	 * @changelog 1.0.0 17.02.2022 initial version
    	 * @example
    	 * NAPC_LOG_INFO("subsystem", "This is a %s!", "message");
    	 */
    	#define NAPC_LOG_INFO(subsys, fmt, ...) \
    		NAPC_LOG(subsys, NAPC_LEVEL_INFO, fmt, ## __VA_ARGS__)
    
    	/*!
    	 * @name NAPC_LOG_WARNING
    	 * @module Core
    	 * @version 1.0.0
    	 * @description
    	 * Log a message with priority `WARNING`.
    	 * @param _cstring_ subsys Subsystem.
    	 * @param _cstring_ fmt printf()-like format string.
    	 * @param n/a ... Values to incorporate into string.
    	 * @changelog 1.0.0 17.02.2022 initial version
    	 * @example
    	 * NAPC_LOG_WARNING("subsystem", "This is a %s!", "message");
    	 */
    	#define NAPC_LOG_WARNING(subsys, fmt, ...) \
    		NAPC_LOG(subsys, NAPC_LEVEL_WARNING, fmt, ## __VA_ARGS__)
    
    	/*!
    	 * @name NAPC_LOG_ERROR
    	 * @module Core
    	 * @version 1.0.0
    	 * @description
    	 * Log a message with priority `ERROR`.
    	 * @param _cstring_ subsys Subsystem.
    	 * @param _cstring_ fmt printf()-like format string.
    	 * @param n/a ... Values to incorporate into string.
    	 * @changelog 1.0.0 17.02.2022 initial version
    	 * @example
    	 * NAPC_LOG_ERROR("subsystem", "This is a %s!", "message");
    	 */
    	#define NAPC_LOG_ERROR(subsys, fmt, ...) \
    		NAPC_LOG(subsys, NAPC_LEVEL_ERROR, fmt, ## __VA_ARGS__)
    
    	/*!
    	 * @name NAPC_LOG_SECURITY
    	 * @module Core
    	 * @version 1.0.0
    	 * @description
    	 * Log a message with priority `SECURITY`.
    	 * @param _cstring_ subsys Subsystem.
    	 * @param _cstring_ fmt printf()-like format string.
    	 * @param n/a ... Values to incorporate into string.
    	 * @changelog 1.0.0 17.02.2022 initial version
    	 * @example
    	 * NAPC_LOG_SECURITY("subsystem", "This is a %s!", "message");
    	 */
    	#define NAPC_LOG_SECURITY(subsys, fmt, ...) \
    		NAPC_LOG(subsys, NAPC_LEVEL_SECURITY, fmt, ## __VA_ARGS__)
    #endif

/* original: #include <napc-rand-source/napc-rand-source.h> */
    #if !defined(NAPC_RAND_SOURCE_h)
    	#define NAPC_RAND_SOURCE_h
    

/* original: #include <libnapc.h> */
/* header file already included */
    
    	/*!
    	 * @name napc_getRandomBitSources
    	 * @brief Get source ids for randomness.
    	 * @version 1.0.0
    	 * @description
    	 * Return a list of all available sources of randomness.
    	 * 
    	 * The end of the list is indicated with `-1` (which is not a valid source identifier).
    	 * @return Returns a list of integers that can be passed as a second parameter to `napc_getRandomBit`.
    	 * @notes
    	 * Since this function is hardware dependent, its output also is dependent on the target hardware.
    	 * @changelog 1.0.0 17.02.2022 initial version
    	 * @example
    	 * const int *sources = napc_getRandomBitSources();
    	 * 
    	 * for (int i = 0; sources[i] >= 0; ++i) {
    	 *     napc_printf("Source identifier %d\n", sources[i]);
    	 * }
    	 */
    	const int *napc_getRandomBitSources(void) NAPC_FN_WARNUNUSED_RET();
    
    	/*!
    	 * @name napc_getRandomBit
    	 * @brief Create a random bit value.
    	 * @version 1.0.0
    	 * @param out Location to put random bit into.
    	 * @param source Source to get the randomness from. See `napc_getRandomBitSources`.
    	 * @return Returns `true` if `out` contains a new randomly generated bit.
    	 * @warning
    	 * It's not advised to call this function directly, use `napc_getRandomByte` for generating a random byte instead.
    	 * @warning
    	 * `out` remains UNMODIFIED if function returned `false`.
    	 * @changelog 1.0.0 17.02.2022 initial version
    	 * @example
    	 * napc_u8 out;
    	 * 
    	 * if (napc_getRandomBit(&out)) {
    	 *     // do something with `out`
    	 * }
    	 */
    	bool napc_getRandomBit(bool *out, int source) NAPC_FN_WARNUNUSED_RET();
    
    	/*!
    	 * @name napc_getRandomByte
    	 * @brief Create a random byte.
    	 * @version 1.0.0
    	 * @param out Location to put random byte into.
    	 * @return Returns `true` if `out` contains a new randomly generated byte.
    	 * @warning
    	 * `out` remains UNMODIFIED if function returned `false`.
    	 * @changelog 1.0.0 17.02.2022 initial version
    	 * @example
    	 * napc_u8 out;
    	 * 
    	 * if (napc_getRandomByte(&out)) {
    	 *     // do something with `out`
    	 * }
    	 */
    	bool napc_getRandomByte(napc_u8 *out) NAPC_FN_WARNUNUSED_RET();
    #endif


/* original: #include <module/pool/pool.h> */
    /*!
     * @name Pool:intro
     * @brief Static memory allocation
     */
    #if !defined(NAPC_MODULE_POOL_h)
    	#define NAPC_MODULE_POOL_h
    

/* original: #include <libnapc.h> */
/* header file already included */

/* original: #include <napc-magic/napc-magic.h> */
        #if !defined(NAPC_MAGIC_h)
        	#define NAPC_MAGIC_h
        

/* original: #include <libnapc.h> */
/* header file already included */
        

/* original: #include <napc-panic/napc-panic.h> */
/* header file already included */
        
        	typedef uint32_t napc_init_magic;
        
        	#define NAPC_MAGIC_MEMBER napc_init_magic _init_magic
        
        	#define NAPC_MAGIC_DESTROYED NAPC_U32_LITERAL(0xFFFFFFFF)
        
        	#define NAPC_MAGIC_INIT(type, obj) (obj)->_init_magic = (NAPC_MAGIC_ ## type)
        	#define NAPC_MAGIC_DESTROY(obj) (obj)->_init_magic = NAPC_MAGIC_DESTROYED
        
        	// Used to silence -Waddress warnings
        	#define PV_NAPC_MAGIC_GET_VALUE(obj) \
        		((void *)(obj) != NULL ? (obj)->_init_magic : 0)
        
        	#define NAPC_MAGIC_ASSERT(type, obj)                                   \
        		do {                                                               \
        			const napc_init_magic actual   = PV_NAPC_MAGIC_GET_VALUE(obj); \
        			const napc_init_magic expected = (NAPC_MAGIC_ ## type);        \
        			if (actual == NAPC_MAGIC_DESTROYED) {                          \
        				NAPC_PANIC("Attempt to use destroyed " # type);            \
        			} else if (actual != expected) {                               \
        				NAPC_PANIC("Detected uninitialized " # type);              \
        			}                                                              \
        		} while (false)
        
        	/*
        	 * Is used for structs that are allocated on the stack and have an
        	 * _init() function.
        	 */
        	#define NAPC_MAGIC_napc__HRTimer                         NAPC_U32_LITERAL(0x56d3a4f1)
        	#define NAPC_MAGIC_napc__Timer                           NAPC_U32_LITERAL(0x2f1fa628)
        	#define NAPC_MAGIC_napc__Pool                            NAPC_U32_LITERAL(0xd3d0df2a)
        
        	#define NAPC_MAGIC_napc__Buffer                          NAPC_U32_LITERAL(0x7beccbe2)
        	#define NAPC_MAGIC_napc__Reader                          NAPC_U32_LITERAL(0xf0de7965)
        
        	#define NAPC_MAGIC_napc__Writer                          NAPC_U32_LITERAL(0x1b81b5d1)
        
        	#define NAPC_MAGIC_napc__IPv4Participant                 NAPC_U32_LITERAL(0x97d59a3d)
        #endif
    
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

/* original: #include <module/hr-timer/hr-timer.h> */
    /*!
     * @name HRTimer:intro
     * @brief High-resolution timer
     */
    #if !defined(NAPC_MODULE_HRTIMER_h)
    	#define NAPC_MODULE_HRTIMER_h
    

/* original: #include <libnapc.h> */
/* header file already included */

/* original: #include <napc-magic/napc-magic.h> */
/* header file already included */
    
    	/*!
    	 * @name napc__HRTimerMode
    	 * @module HRTimer
    	 * @brief Representation of timer operation mode.
    	 * @version 2.0.0
    	 * @enum NAPC_HRTIMER_MODE_REGULAR Regular timer mode.
    	 * @enum NAPC_HRTIMER_MODE_ONESHOT One-shot timer mode.
    	 * @changelog 2.0.0 21.10.2022 initial version
    	 */
    	typedef enum napc__HRTimerMode {
    		NAPC_HRTIMER_MODE_REGULAR = 0x10, // 0001 0000
    		NAPC_HRTIMER_MODE_ONESHOT = 0x20  // 0010 0000
    	} napc__HRTimerMode;
    
    	/*!
    	 * @name napc__HRTimer
    	 * @module HRTimer
    	 * @brief Representation of a high-resolution timer.
    	 * @version 2.0.0
    	 * @opaque
    	 * @changelog 2.0.0 25.03.2022 initial version
    	 */
    	typedef struct napc__HRTimer {
    		NAPC_MAGIC_MEMBER; // used to detect uninitialized timers
    
    		napc__HRTimerMode mode;
    
    		napc_time duration;
    		napc_time started_at;
    		bool expired;
    	} napc__HRTimer;
    
    	/*!
    	 * @name napc_HRTimer_init
    	 * @brief Initialize a high-resolution timer.
    	 * @version 2.0.0
    	 * @description
    	 * Initializes a timer with a duration of `duration` microseconds.
    	 * @param timer Timer to be initialized.
    	 * @param duration Timer duration in microseconds.
    	 * @param mode Timer mode.
    	 * @changelog 2.0.0 21.10.2022 initial version
    	 * @example
    	 * napc__HRTimer timer;
    	 * 
    	 * // one-shot mode means _expired will return
    	 * // 'true' only ONCE.
    	 * napc_HRTimer_init(&timer, 1000, NAPC_HRTIMER_MODE_ONESHOT); // 1000us = 1ms
    	 */
    	void napc_HRTimer_init(napc__HRTimer *timer, napc_time duration, napc__HRTimerMode mode);
    
    	/*!
    	 * @name napc_HRTimer_create
    	 * @brief Create a high-resolution timer object.
    	 * @version 2.0.0
    	 * @description
    	 * Creates a timer with a duration of `duration` microseconds.
    	 * @param duration Timer duration in microseconds.
    	 * @param mode Timer mode.
    	 * @changelog 2.0.0 21.10.2022 initial version
    	 * @example
    	 * // one-shot mode means _expired will return
    	 * // 'true' only ONCE.
    	 * napc__HRTimer timer = napc_HRTimer_create(1000, NAPC_HRTIMER_MODE_ONESHOT); // 1000us = 1ms
    	 */
    	napc__HRTimer napc_HRTimer_create(napc_time duration, napc__HRTimerMode mode);
    
    	/*!
    	 * @name napc_HRTimer_start
    	 * @brief Start a high-resolution timer.
    	 * @version 2.0.0
    	 * @description
    	 * Starts the high-resolution timer `timer`.
    	 * @param timer Timer to start.
    	 * @changelog 2.0.0 25.03.2022 initial version
    	 * @example
    	 * napc__HRTimer timer = napc_HRTimer_create(1000, NAPC_HRTIMER_MODE_REGULAR);
    	 * 
    	 * napc_HRTimer_start(&timer);
    	 */
    	void napc_HRTimer_start(napc__HRTimer *timer);
    
    	/*!
    	 * @name napc_HRTimer_expired
    	 * @brief Check if a high-resolution timer has expired.
    	 * @version 2.0.0
    	 * @param timer Timer to check.
    	 * @return Returns `true` if timer expired, `false` otherwise.
    	 * @notes
    	 * In REGULAR mode:
    	 * 
    	 * After the timer expired this function will always return `true`
    	 * until timer is restarted with `napc_HRTimer_restart`.
    	 * @notes
    	 * In ONESHOT mode:
    	 * 
    	 * This function will return `true` only once per started timer.
    	 * Subsequent calls on the same timer will return `false`.
    	 * @changelog 2.0.0 25.03.2022 initial version
    	 */
    	bool napc_HRTimer_expired(napc__HRTimer *timer) NAPC_FN_WARNUNUSED_RET();
    
    	/*!
    	 * @name napc_HRTimer_getMode
    	 * @brief Return the timer mode.
    	 * @version 2.0.0
    	 * @param timer Timer to return mode of.
    	 * @return Returns the set timer mode.
    	 * @changelog 2.0.0 25.03.2022 initial version
    	 */
    	napc__HRTimerMode napc_HRTimer_getMode(const napc__HRTimer *timer) NAPC_FN_WARNUNUSED_RET();
    
    	/*!
    	 * @name napc_HRTimer_restart
    	 * @brief Restart a timer.
    	 * @version 2.0.0
    	 * @param timer Timer to be restarted.
    	 * @changelog 2.0.0 25.03.2022 initial version
    	 * @example
    	 * if (napc_HRTimer_expired(&timer)) {
    	 *     napc_HRTimer_restart(&timer);
    	 * }
    	 */
    	void napc_HRTimer_restart(napc__HRTimer *timer);
    #endif

/* original: #include <module/timer/timer.h> */
    #if !defined(NAPC_MODULE_TIMER_h)
    	#define NAPC_MODULE_TIMER_h
    

/* original: #include <libnapc.h> */
/* header file already included */

/* original: #include <napc-magic/napc-magic.h> */
/* header file already included */
    
    	/*!
    	 * @name napc__TimerMode
    	 * @module Timer
    	 * @brief Representation of timer operation mode.
    	 * @version 2.0.0
    	 * @enum NAPC_TIMER_MODE_REGULAR Regular timer mode.
    	 * @enum NAPC_TIMER_MODE_ONESHOT One-shot timer mode.
    	 * @changelog 2.0.0 21.10.2022 initial version
    	 */
    	typedef enum napc__TimerMode {
    		NAPC_TIMER_MODE_REGULAR = 0x01, // 0000 0001
    		NAPC_TIMER_MODE_ONESHOT = 0x02  // 0000 0010
    	} napc__TimerMode;
    
    	/*!
    	 * @name napc__Timer
    	 * @module Timer
    	 * @brief Representation of a timer.
    	 * @version 2.0.0
    	 * @opaque
    	 * @changelog 2.0.0 25.03.2022 initial version
    	 */
    	typedef struct napc__Timer {
    		NAPC_MAGIC_MEMBER; // used to detect uninitialized timers
    
    		napc__TimerMode mode;
    
    		napc_time duration;
    		napc_time started_at;
    		bool expired;
    	} napc__Timer;
    
    	/*!
    	 * @name napc_Timer_init
    	 * @brief Initialize a timer.
    	 * @version 2.0.0
    	 * @description
    	 * Initializes a timer with a duration of `duration` milliseconds.
    	 * @param timer Timer to be initialized.
    	 * @param duration Timer duration in milliseconds.
    	 * @param mode Timer mode.
    	 * @changelog 2.0.0 21.10.2022 initial version
    	 * @example
    	 * napc__Timer timer;
    	 * 
    	 * // one-shot mode means _expired will return
    	 * // 'true' only ONCE.
    	 * napc_Timer_init(&timer, 1000, NAPC_TIMER_MODE_ONESHOT); // 1000ms = 1s
    	 */
    	void napc_Timer_init(napc__Timer *timer, napc_time duration, napc__TimerMode mode);
    
    	/*!
    	 * @name napc_Timer_create
    	 * @brief Create a timer object.
    	 * @version 2.0.0
    	 * @description
    	 * Creates a timer with a duration of `duration` milliseconds.
    	 * @param duration Timer duration in milliseconds.
    	 * @param mode Timer mode.
    	 * @changelog 2.0.0 21.10.2022 initial version
    	 * @example
    	 * // one-shot mode means _expired will return
    	 * // 'true' only ONCE.
    	 * napc__Timer timer = napc_Timer_create(1000, NAPC_TIMER_MODE_ONESHOT); // 1000ms = 1s
    	 */
    	napc__Timer napc_Timer_create(napc_time duration, napc__TimerMode mode);
    
    	/*!
    	 * @name napc_Timer_start
    	 * @brief Start a timer.
    	 * @version 2.0.0
    	 * @description
    	 * Starts the timer `timer`.
    	 * @param timer Timer to start.
    	 * @changelog 2.0.0 25.03.2022 initial version
    	 * @example
    	 * napc__Timer timer = napc_Timer_create(1000);
    	 * 
    	 * napc_Timer_start(&timer);
    	 */
    	void napc_Timer_start(napc__Timer *timer);
    
    	/*!
    	 * @name napc_Timer_expired
    	 * @brief Check if a timer has expired.
    	 * @version 2.0.0
    	 * @param timer Timer to check.
    	 * @return Returns `true` if timer expired, `false` otherwise.
    	 * @notes
    	 * In REGULAR mode:
    	 * 
    	 * After the timer expired this function will always return `true`
    	 * until timer is restarted with `napc_Timer_restart`.
    	 * @notes
    	 * In ONESHOT mode:
    	 * 
    	 * This function will return `true` only once per started timer.
    	 * Subsequent calls on the same timer will return `false`.
    	 * @changelog 2.0.0 25.03.2022 initial version
    	 */
    	bool napc_Timer_expired(napc__Timer *timer) NAPC_FN_WARNUNUSED_RET();
    
    	/*!
    	 * @name napc_Timer_getMode
    	 * @brief Return the timer mode.
    	 * @version 2.0.0
    	 * @param timer Timer to return mode of.
    	 * @return Returns the set timer mode.
    	 * @changelog 2.0.0 25.03.2022 initial version
    	 */
    	napc__TimerMode napc_Timer_getMode(const napc__Timer *timer) NAPC_FN_WARNUNUSED_RET();
    
    	/*!
    	 * @name napc_Timer_restart
    	 * @brief Restart a timer.
    	 * @version 2.0.0
    	 * @param timer Timer to be restarted.
    	 * @changelog 2.0.0 25.03.2022 initial version
    	 * @example
    	 * if (napc_Timer_expired(&timer)) {
    	 *     napc_Timer_restart(&timer);
    	 * }
    	 */
    	void napc_Timer_restart(napc__Timer *timer);
    #endif

/* original: #include <module/random/random.h> */
    /*!
     * @name random:intro
     * @brief Random number generation
     * @description
     * This module provides random number generation suitable for cryptographic purposes.
     * 
     * A typical application looks like this:
     * 
     * ```c
     * #include <napc.h>
     * 
     * napc_u8 random_bytes[16];
     * 
     * void napc_app_setup(const char *platform) {}
     * 
     * bool napc_app_loop(napc_time uptime) {
     * 	// request of 16 random bytes
     * 	if (napc_random_getRandomBytes(16, random_bytes)) {
     * 		// do something with random_bytes
     * 
     * 		napc_printf("Here are your random numbers: ");
     * 
     * 		for (int i = 0; i < 16; ++i) {
     * 			napc_printf("%2.2x", random_bytes[i]);
     * 		}
     * 
     * 		napc_printf("\n");
     * 
     * 		return false;
     * 	}
     * 
     * 	// collect new random data
     * 	napc_random_collectBytes();
     * 
     * 	return true;
     * }
     * ```
     * 
     * This program will output something similar to:
     * 
     * ```
     * Here are your random numbers: 162109b28bba5eabb17b69d83aeffd84
     * ```
     */
    #if !defined(NAPC_MODULE_RANDOM_h)
    	#define NAPC_MODULE_RANDOM_h
    

/* original: #include <libnapc.h> */
/* header file already included */
    
    	/*!
    	 * @name napc_random_collectBytes
    	 * @brief Collect random bits from various sources.
    	 * @version 1.0.0
    	 * @notes
    	 * This function must be called periodically for `napc_random_getRandomBytes` to work.
    	 * @changelog 1.0.0 17.02.2022 initial version
    	 */
    	void napc_random_collectBytes(void);
    
    	/*!
    	 * @name napc_random_getAvailableBytes
    	 * @brief Get number of available random bytes.
    	 * @version 1.0.0
    	 * @description
    	 * Get number of immediately available random bytes.
    	 * @return Returns the number of available random bytes.
    	 * @changelog 1.0.0 17.02.2022 initial version
    	 */
    	napc_size napc_random_getAvailableBytes(void) NAPC_FN_WARNUNUSED_RET();
    
    	/*!
    	 * @name napc_random_getRandomBytes
    	 * @brief Create random bytes.
    	 * @version 1.0.0
    	 * @description
    	 * Creates `n_bytes` random bytes.
    	 * @param n_bytes Number of bytes to be generated.
    	 * @param out Array to store collected bytes.
    	 * @return Returns `true` if array `out` was filled with `n_bytes` bytes of random data.
    	 * @notes
    	 * `napc_random_collectBytes` must be called periodically for this function to work.
    	 * @warning
    	 * `out` remains UNMODIFIED if function returned `false`.
    	 * @changelog 1.0.0 17.02.2022 initial version
    	 * @example
    	 * napc_u8 random_bytes[32];
    	 * 
    	 * if (napc_random_getRandomBytes(random_bytes, sizeof(random_bytes))) {
    	 *     // random_bytes now contains 32 random bytes
    	 * }
    	 */
    	bool napc_random_getRandomBytes(napc_size n_bytes, napc_u8 *out) NAPC_FN_WARNUNUSED_RET();
    
    	/*!
    	 * @name napc_random_getRandomBytesSync
    	 * @brief Create random bytes.
    	 * @version 1.5.0
    	 * @description
    	 * Creates `n_bytes` random bytes.
    	 * @param n_bytes Number of bytes to be generated.
    	 * @param out Array to store collected bytes.
    	 * @warning
    	 * Since this function blocks until enough random data is collected, it is better to use `napc_random_getRandomBytes`.
    	 * @changelog 1.5.0 25.03.2022 initial version
    	 * @example
    	 * napc_u8 random_bytes[32];
    	 * 
    	 * napc_random_getRandomBytesSync(random_bytes, sizeof(random_bytes));
    	 * 
    	 * // random_bytes now contains 32 random bytes
    	 */
    	void napc_random_getRandomBytesSync(napc_size n_bytes, napc_u8 *out);
    #endif

/* original: #include <module/parser/parser.h> */
    /*!
     * @name parser:intro
     * @brief String parsing
     * @description
     * This module contains all functions that parse strings.
     * 
     * All functions in this module follow the same rules<sup>*</sup>:
     * 
     * - The first parameter is always the string to be parsed.
     * - Every function returns a boolean indicating success or failure.
     * - It is allowed to pass `NULL` as output. This is useful for checking the format of a string:
     * 
     * ```c
     * if (napc_parser_parseIPv4Address(ip_str, NULL)) {
     * 	// ip_str is a valid IPv4Address
     * }
     * ```
     * 
     * > If a function returned `false` the contents of the parsed output is _undefined_.
     */
    #if !defined(NAPC_MODULE_PARSER_h)
    	#define NAPC_MODULE_PARSER_h
    

/* original: #include <libnapc.h> */
/* header file already included */
    

/* original: #include <module/parser/parser-decimal-number.h> */
        #if !defined(NAPC_MODULE_PARSER_DECIMAL_NUMBER_h)
        	#define NAPC_MODULE_PARSER_DECIMAL_NUMBER_h
        

/* original: #include <libnapc.h> */
/* header file already included */
        
        	/*!
        	 * @name napc_parser_parseDecimalNumberU8
        	 * @brief Parse a hexadecimal number from string.
        	 * @version 1.0.0
        	 * @description
        	 * Parse a string containing a decimal number.
        	 * @param string String to be parsed.
        	 * @param out Pointer to store the parsed number. (optional)
        	 * @return Returns `true` on success, `false` otherwise.
        	 * @changelog 1.0.0 17.02.2022 initial version
        	 * @example
        	 * napc_u8 out;
        	 * 
        	 * if (napc_parser_parseDecimalNumberU8("123", &out)) {
        	 *     napc_printf("Value is %d", out); // "Value is 123"
        	 * }
        	 */
        	bool napc_parser_parseDecimalNumberU8(
        		const char *string, napc_u8 *out
        	) NAPC_FN_WARNUNUSED_RET();
        
        	/*!
        	 * @name napc_parser_parseDecimalNumberU16
        	 * @brief Parse a hexadecimal number from string.
        	 * @version 1.0.0
        	 * @description
        	 * Parse a string containing a decimal number.
        	 * @param string String to be parsed.
        	 * @param out Pointer to store the parsed number. (optional)
        	 * @return Returns `true` on success, `false` otherwise.
        	 * @changelog 1.0.0 17.02.2022 initial version
        	 * @example
        	 * napc_u16 out;
        	 * 
        	 * if (napc_parser_parseDecimalNumberU16("1024", &out)) {
        	 *     napc_printf("Value is %d", out); // "Value is 1024"
        	 * }
        	 */
        	bool napc_parser_parseDecimalNumberU16(
        		const char *string, napc_u16 *out
        	) NAPC_FN_WARNUNUSED_RET();
        
        	/*!
        	 * @name napc_parser_parseDecimalNumberU32
        	 * @brief Parse a hexadecimal number from string.
        	 * @version 1.0.0
        	 * @description
        	 * Parse a string containing a decimal number.
        	 * @param string String to be parsed.
        	 * @param out Pointer to store the parsed number. (optional)
        	 * @return Returns `true` on success, `false` otherwise.
        	 * @changelog 1.0.0 17.02.2022 initial version
        	 * @example
        	 * napc_u32 out;
        	 * 
        	 * if (napc_parser_parseDecimalNumberU32("123456", &out)) {
        	 *     napc_printf("Value is %ld", out); // "Value is 123456"
        	 * }
        	 */
        	bool napc_parser_parseDecimalNumberU32(
        		const char *string, napc_u32 *out
        	) NAPC_FN_WARNUNUSED_RET();
        #endif

/* original: #include <module/parser/parser-hexadecimal-number.h> */
        #if !defined(NAPC_MODULE_PARSER_HEXADECIMAL_NUMBER_h)
        	#define NAPC_MODULE_PARSER_HEXADECIMAL_NUMBER_h
        

/* original: #include <libnapc.h> */
/* header file already included */
        
        	/*!
        	 * @name napc_parser_parseHexadecimalNumberU8
        	 * @brief Parse a decimal number from string.
        	 * @version 1.0.0
        	 * @description
        	 * Parse a string containing a hexadecimal number.
        	 * @param string String to be parsed.
        	 * @param out Pointer to store the parsed number. (optional)
        	 * @return Returns `true` on success, `false` otherwise.
        	 * @changelog 1.0.0 17.02.2022 initial version
        	 * @example
        	 * napc_u8 out;
        	 * 
        	 * if (napc_parser_parseHexadecimalNumberU8("ef", &out)) {
        	 *     napc_printf("Value is %ld", out); // "Value is 239"
        	 * }
        	 */
        	bool napc_parser_parseHexadecimalNumberU8(
        		const char *string,
        		napc_u8 *out
        	) NAPC_FN_WARNUNUSED_RET();
        
        	/*!
        	 * @name napc_parser_parseHexadecimalNumberU16
        	 * @brief Parse a decimal number from string.
        	 * @version 1.0.0
        	 * @description
        	 * Parse a string containing a hexadecimal number.
        	 * @param string String to be parsed.
        	 * @param out Pointer to store the parsed number. (optional)
        	 * @return Returns `true` on success, `false` otherwise.
        	 * @changelog 1.0.0 17.02.2022 initial version
        	 * @example
        	 * napc_u16 out;
        	 * 
        	 * if (napc_parser_parseHexadecimalNumberU16("beef", &out)) {
        	 *     napc_printf("Value is %ld", out); // "Value is 48879"
        	 * }
        	 */
        	bool napc_parser_parseHexadecimalNumberU16(
        		const char *string,
        		napc_u16 *out
        	) NAPC_FN_WARNUNUSED_RET();
        
        	/*!
        	 * @name napc_parser_parseHexadecimalNumberU32
        	 * @brief Parse a decimal number from string.
        	 * @version 1.0.0
        	 * @description
        	 * Parse a string containing a hexadecimal number.
        	 * @param string String to be parsed.
        	 * @param out Pointer to store the parsed number. (optional)
        	 * @return Returns `true` on success, `false` otherwise.
        	 * @changelog 1.0.0 17.02.2022 initial version
        	 * @example
        	 * napc_u32 out;
        	 * 
        	 * if (napc_parser_parseHexadecimalNumberU32("deadbeef", &out)) {
        	 *     napc_printf("Value is %ld", out); // "Value is 3735928559"
        	 * }
        	 */
        	bool napc_parser_parseHexadecimalNumberU32(
        		const char *string,
        		napc_u32 *out
        	) NAPC_FN_WARNUNUSED_RET();
        #endif
    
    	/*!
    	 * @name napc_parser_parseBoolean
    	 * @brief Parse a boolean from string.
    	 * @version 1.0.0
    	 * @description
    	 * Attempts to parse a boolean from a string.
    	 * 
    	 * This function recognizes the following formats:
    	 *  - `"yes"`, `"true"`, `"1"` for `true`
    	 *  - `"no"`, `"false"`, `"0"` for `false`
    	 * @param string The string to be parsed.
    	 * @param out Pointer to a variable to store the result. (optional)
    	 * @return Returns `true` on success, `false` otherwise.
    	 * @notes
    	 * The casing of the string formats does not matter. (for example `yeS` is recognized as `true`)
    	 * @changelog 1.0.0 17.02.2022 initial version
    	 * @example
    	 * bool out;
    	 * 
    	 * if (napc_parser_parseBoolean("yes", &out)) {
    	 *     // parsing sucessfull!
    	 *     // `out` now has the value `true`
    	 * }
    	 */
    	bool napc_parser_parseBoolean(
    		const char *string,
    		bool *out
    	) NAPC_FN_WARNUNUSED_RET();
    
    	/*!
    	 * @name napc_parser_parseHexString
    	 * @brief Parse a string containing hexadecimal characters.
    	 * @version 1.0.0
    	 * @description
    	 * Parse a string of hexadecimal characters.
    	 * @param string The string to be parsed.
    	 * @param n_bytes Number of bytes to be parsed.
    	 * @param out Array to store result. (optional)
    	 * @return Returns `true` on success, `false` otherwise.
    	 * @warning
    	 * The string's length must exactly be double `n_bytes`.
    	 * @changelog 1.0.0 17.02.2022 initial version
    	 * @example
    	 * const char *hex_str = "deadbeefabcdefaa123b";
    	 * napc_u8 bytes[10];
    	 * 
    	 * if (napc_parser_parseHexString(hex_str, 10, bytes)) {
    	 *     napc_printf("The hex value is: ");
    	 * 
    	 *     for (int i = 0; i < 10; ++i) {
    	 *         napc_printf("%2.2x", bytes[i]);
    	 *     }
    	 * 
    	 *     napc_printf("\n");
    	 * }
    	 */
    	bool napc_parser_parseHexString(
    		const char *string,
    		napc_size n_bytes,
    		napc_u8 *out
    	) NAPC_FN_WARNUNUSED_RET();
    
    	/*!
    	 * @name napc_parser_parseMACAddress
    	 * @brief Parse a MAC-Address.
    	 * @version 1.0.0
    	 * @description
    	 * Parse a MAC-Address (in the format of `aa:bb:cc:dd:ee:ff`) from string.
    	 * @param string String to be parsed.
    	 * @param out Array to store result. (optional)
    	 * @return Returns `true` on success, `false` otherwise.
    	 * @warning
    	 * The output array must have at least 6 elements (6 bytes).
    	 * @changelog 1.0.0 17.02.2022 initial version
    	 * @example
    	 * napc_u8 addr[6];
    	 * 
    	 * if (napc_parser_parseMACAddress("ab:de:ef:11:22:33", addr)) {
    	 *     // addr[0] now contains 171 (0xab)
    	 *     // addr[1] now contains 222 (0xde)
    	 *     // addr[2] now contains 239 (0xef)
    	 *     // addr[3] now contains 17  (0x11)
    	 *     // addr[4] now contains 34  (0x22)
    	 *     // addr[5] now contains 51  (0x33)
    	 * } else {
    	 *     napc_printf("Failed to parse MAC-Address!\n");
    	 * }
    	 */
    	bool napc_parser_parseMACAddress(
    		const char *string,
    		napc_u8 *out
    	) NAPC_FN_WARNUNUSED_RET();
    
    	/*!
    	 * @name napc_parser_parseIPv4Address
    	 * @brief Parse an IPv4-Address.
    	 * @version 1.0.0
    	 * @description
    	 * Parse an IPv4-Address (in the format of `a.b.c.d`) from string.
    	 * @param string The string to be parsed.
    	 * @param out Array to store result. (optional)
    	 * @return Returns `true` on success, `false` otherwise.
    	 * @warning
    	 * The output array must have at least 4 elements (4 bytes).
    	 * @changelog 1.0.0 17.02.2022 initial version
    	 * @example
    	 * napc_u8 addr[4];
    	 * 
    	 * if (napc_parser_parseIPv4Address("1.2.3.4", addr)) {
    	 *     // addr[0] now contains 1
    	 *     // addr[1] now contains 2
    	 *     // addr[2] now contains 3
    	 *     // addr[3] now contains 4
    	 * } else {
    	 *     napc_printf("Failed to parse IP-Address!\n");
    	 * }
    	 */
    	bool napc_parser_parseIPv4Address(
    		const char *string,
    		napc_u8 *out)
    	NAPC_FN_WARNUNUSED_RET();
    
    	/*!
    	 * @name napc_parser_parseKeyValue
    	 * @brief Parse a key,value pair.
    	 * @version 1.0.0
    	 * @description
    	 * Parse a string in `key,value` format.
    	 * @param string The string to be parsed.
    	 * @param key Buffer to place parsed key string.
    	 * @param key_len Size of `key` buffer.
    	 * @param value Buffer to place parsed value string.
    	 * @param value_len Size of `value` buffer.
    	 * @return Returns `true` on success, `false` otherwise.
    	 * @changelog 1.0.0 17.02.2022 initial version
    	 * @example
    	 * char key[32];
    	 * char value[32];
    	 * 
    	 * bool result = napc_parser_parseKeyValue(
    	 *     "test,1234",
    	 *      key, sizeof(key),
    	 *      value, sizeof(value)
    	 * );
    	 * 
    	 * if (result) {
    	 *     // key is "test"
    	 *     // value is "1234"
    	 * }
    	 */
    	bool napc_parser_parseKeyValue(
    		const char *string,
    		char *key, napc_size key_len,
    		char *value, napc_size value_len
    	) NAPC_FN_WARNUNUSED_RET();
    #endif

/* original: #include <module/aes/aes.h> */
    /*!
     * @name aes:intro
     * @brief Encrypt & decrypt messages
     */
    #if !defined(NAPC_MODULE_AES_h)
    	#define NAPC_MODULE_AES_h
    

/* original: #include <libnapc.h> */
/* header file already included */
    
    	/*!
    	 * @name napc_aes_encrypt
    	 * @brief Encrypt a message with AES-256.
    	 * @version 1.0.0
    	 * @description
    	 * Encrypt a message with AES-256 in CBC mode.
    	 * @param iv Initialization vector (16 bytes)
    	 * @param key Key in HEX format (32 bytes)
    	 * @param buffer Buffer to encrypt.
    	 * @param buffer_size Size of buffer.
    	 * @warning The input buffer must always be aligned to 16 bytes.
    	 * @changelog 1.0.0 17.02.2022 initial version
    	 * @example
    	 * char message[32];
    	 * napc_u8 iv[16];
    	 * const char *key = "secret";
    	 * char key_hashed[65];
    	 * 
    	 * // initialize IV with random bytes
    	 * // note that napc_random_getRandomBytesSync() is used here for simplicity
    	 * // it is better to use napc_random_getRandomBytes().
    	 * napc_random_getRandomBytesSync(sizeof(iv), iv);
    	 * 
    	 * // since napc_aes_encrypt() expects a HEX formatted key string
    	 * // we simply calculate the SHA256 hash of the key
    	 * // which is guaranteed to be a 32 byte hex formatted string.
    	 * if (napc_sha_calculate(key, napc_strlen(key), key_hashed, sizeof(key_hashed))) {
    	 *     // set all bytes in message to zero
    	 *     // napc_aes_encrypt() always needs the input buffer's size to be 
    	 *     // a multiple of 16. This way unused bytes are always zero.
    	 *     napc_mzero(message, sizeof(message));
    	 * 
    	 *     // copy a message
    	 *     napc_strncpy(message, "Hello, World!", sizeof(message));
    	 * 
    	 *     // do the encryption
    	 *     if (napc_aes_encrypt(iv, key_hashed, message, sizeof(message))) {
    	 *         // message is now encrypted
    	 *         napc_printf("Message encrypted!\n");
    	 * 
    	 *         napc_printf("Key: %s\n", key_hashed);
    	 * 
    	 *         napc_printf("IV: ");
    	 *         napc_misc_printHexArray(iv, sizeof(iv));
    	 *         napc_printf("\n");
    	 * 
    	 *         napc_printf("Ciphertext: ");
    	 *         napc_misc_printHexArray(message, sizeof(message));
    	 *         napc_printf("\n");
    	 *     }
    	 * }
    	 */
    	bool napc_aes_encrypt(
    		const napc_u8 *iv,
    		const char *key,
    		void *buffer, napc_size buffer_size
    	) NAPC_FN_WARNUNUSED_RET();
    
    	/*!
    	 * @name napc_aes_decrypt
    	 * @brief Decrypt a message with AES-256.
    	 * @version 1.0.0
    	 * @description
    	 * Decrypt a message with AES-256 in CBC mode.
    	 * @param iv Initialization vector (16 bytes)
    	 * @param key Key in HEX format (32 bytes)
    	 * @param buffer Buffer to encrypt.
    	 * @param buffer_size Size of buffer.
    	 * @return Returns `true` on success, `false` otherwise.
    	 * @warning The input buffer must always be aligned to 16 bytes.
    	 * @changelog 1.0.0 17.02.2022 initial version
    	 */
    	bool napc_aes_decrypt(
    		const napc_u8 *iv,
    		const char *key,
    		void *buffer, napc_size buffer_size
    	) NAPC_FN_WARNUNUSED_RET();
    #endif

/* original: #include <module/hmac/hmac.h> */
    /*!
     * @name hmac:intro
     * @brief Sign & verify messages
     */
    #if !defined(NAPC_MODULE_HMAC_h)
    	#define NAPC_MODULE_HMAC_h
    

/* original: #include <libnapc.h> */
/* header file already included */
    
    	/*!
    	 * @name napc_hmac_calculate
    	 * @brief Calculate HMAC of a message.
    	 * @version 1.0.0
    	 * @description
    	 * Calculate the SHA-256 HMAC signature of a message.
    	 * @param out Pointer to store resulting HMAC (32 bytes)
    	 * @param key Key to be used.
    	 * @param buffer Buffer containing the message.
    	 * @param buffer_size Size of buffer.
    	 * @changelog 1.0.0 17.02.2022 initial version
    	 */
    	void napc_hmac_calculate(
    		napc_u8 *out,
    		const char *key,
    		const void *buffer, napc_size buffer_size
    	);
    
    	/*!
    	 * @name napc_hmac_verify
    	 * @brief Verify a message with HMAC.
    	 * @version 1.0.0
    	 * @description
    	 * Verify a message.
    	 * @param key Key to be used.
    	 * @param hmac Pointer to HMAC (32 bytes)
    	 * @param buffer Buffer containing the message.
    	 * @param buffer_size Size of buffer.
    	 * @return Returns `true` if the message matches the `hmac` signature.
    	 * @changelog 1.0.0 17.02.2022 initial version
    	 */
    	bool napc_hmac_verify(
    		const char *key, const napc_u8 *hmac,
    		const void *buffer, napc_size buffer_size
    	) NAPC_FN_WARNUNUSED_RET();
    #endif

/* original: #include <module/misc/misc.h> */
    #if !defined(NAPC_MODULE_MISC_h)
    	#define NAPC_MODULE_MISC_h
    

/* original: #include <libnapc.h> */
/* header file already included */
    

/* original: #include <string.h> // memcmp(), memcpy() etc. */
    #include <string.h> // memcmp(), memcpy() etc.
    
    	/*!
    	 * @name napc_misc_printHexArray
    	 * @brief Print an array of integers
    	 * @version 1.5.0
    	 * @rationale
    	 * It's cumbersome to write a loop for printing out hex arrays.
    	 * @param bytes Bytes array.
    	 * @param n_bytes Size of bytes array.
    	 * @changelog 1.5.0 25.03.2022 initial version
    	 * @example
    	 * napc_u8 array[4] = {0xde, 0xad, 0xbe, 0xef};
    	 * 
    	 * // prints deadbeef
    	 * napc_misc_printHexArray(array, sizeof(array));
    	 */
    	void napc_misc_printHexArray(const void *bytes, napc_size n_bytes);
    
    	/*!
    	 * @name napc_misc_shiftArrayRight
    	 * @brief Shift elements in an array.
    	 * @version 1.0.0
    	 * @description
    	 * Shift elements in `array` one element to the right discarding the last
    	 * element in the array.
    	 * @param array The array to be shifted.
    	 * @param n_elements The number of elements in `array`.
    	 * @param element_size The size (in bytes) of one element in `array`.
    	 * @notes
    	 * The contents of the first element in `array` will be undefined after this operation.
    	 * @changelog 1.0.0 17.02.2022 initial version
    	 * @example
    	 * int data[5] = {1, 2, 3, 4, 5};
    	 * 
    	 * napc_misc_shiftArrayRight(data, 5, sizeof(int));
    	 * 
    	 * // data[0] is now undefined
    	 * // data[1] is now 1
    	 * // data[2] is now 2
    	 * // data[3] is now 3
    	 * // data[4] is now 4
    	 */
    	void napc_misc_shiftArrayRight(
    		void *array, napc_size n_elements, napc_size element_size
    	);
    
    	/**************************
    	 * Memory fences
    	 * To detect buffer over and underflows.
    	 */
    	void napc_misc_setMemoryFenceBytes(
    		unsigned char *buffer, napc_size buffer_size,
    		napc_size memory_fence_size, napc_u8 fence_value
    	);
    
    	bool napc_misc_verifyMemoryFenceBytes(
    		unsigned char *buffer, napc_size buffer_size,
    		napc_size memory_fence_size, napc_u8 fence_value
    	);
    
    	/**************************
    	 * Chunks
    	 */
    	typedef napc_ssize (*napc_misc_ChunkedOperationCallback)(
    		const void *data, napc_size data_size, void *context
    	);
    
    	/*!
    	 * @name napc_misc_chunkedOperation
    	 * @brief Perform an operation in chunks.
    	 * @version 1.0.0
    	 * @description
    	 * Performs an operation in chunks.
    	 * @param data Data to process.
    	 * @param data_size Size of data to process.
    	 * @param chunk_size Size of one chunk.
    	 * @param fn Callback for processing one chunk.
    	 * @param fn_context Optional context for `fn` callback.
    	 * @return Returns `true` on success, `false` otherwise.
    	 * @notes
    	 * `fn` is a function with the following prototype:
    	 * 
    	 * `napc_ssize (const void *data, napc_size data_size, void *context)`
    	 * @changelog 1.0.0 17.02.2022 initial version
    	 */
    	bool napc_misc_chunkedOperation(
    		const void *data, napc_size data_size, napc_size chunk_size,
    		napc_misc_ChunkedOperationCallback fn, void *fn_context
    	) NAPC_FN_WARNUNUSED_RET();
    #endif

/* original: #include <module/reader/reader.h> */
    /*!
     * @name Reader:intro
     * @brief Binary buffer reader
     */
    #if !defined(NAPC_MODULE_READER_h)
    	#define NAPC_MODULE_READER_h
    

/* original: #include <libnapc.h> */
/* header file already included */

/* original: #include <napc-magic/napc-magic.h> */
/* header file already included */
    
    	/*!
    	 * @name napc__ReaderFailMode
    	 * @module Reader
    	 * @brief Action to be taken on access failure.
    	 * @version 2.0.0
    	 * @enum NAPC_READER_FAILMODE_NONE Do nothing.
    	 * @enum NAPC_READER_FAILMODE_LOG Emit a log message of type error. This is the default.
    	 * @enum NAPC_READER_FAILMODE_PANIC Call NAPC_PANIC.
    	 * @changelog 2.0.0 21.10.2022 initial version
    	 */
    	typedef enum napc__ReaderFailMode {
    		NAPC_READER_FAILMODE_NONE  = 0x10, // 0001 0000
    		NAPC_READER_FAILMODE_LOG   = 0x20, // 0010 0000
    		NAPC_READER_FAILMODE_PANIC = 0x40  // 0100 0000
    	} napc__ReaderFailMode;
    
    	/*!
    	 * @name napc__Reader
    	 * @module Reader
    	 * @brief Representation of a reader.
    	 * @version 1.0.0
    	 * @opaque
    	 * @changelog 1.0.0 17.02.2022 initial version
    	 */
    	typedef struct napc__Reader {
    		NAPC_MAGIC_MEMBER;
    
    		napc__ReaderFailMode _fail_mode;
    
    		napc_size _offset;
    		napc_size size;
    		const void *data;
    	} napc__Reader;
    
    	/*!
    	 * @name napc_Reader_init
    	 * @brief Initialize a reader.
    	 * @version 1.0.0
    	 * @description
    	 * Initialize a reader.
    	 * @param ctx Pointer to the napc__Reader instance.
    	 * @param data Pointer to the buffer to be read.
    	 * @param data_size Size of buffer.
    	 * @changelog 1.0.0 17.02.2022 initial version
    	 * @example
    	 * napc__Reader reader;
    	 * char buffer[512];
    	 * 
    	 * napc_Reader_init(&reader, buffer, sizeof(buffer));
    	 */
    	void napc_Reader_init(
    		napc__Reader *ctx, const void *data, napc_size data_size
    	);
    
    	/*!
    	 * @name napc_Reader_create
    	 * @brief Create a reader object.
    	 * @version 1.0.0
    	 * @description
    	 * Create a reader.
    	 * @param ctx Pointer to the napc__Reader instance.
    	 * @param data Pointer to the buffer to be read.
    	 * @param data_size Size of `data`.
    	 * @changelog 1.0.0 17.02.2022 initial version
    	 * @example
    	 * char buffer[512];
    	 * 
    	 * napc__Reader reader = napc_Reader_create(buffer, sizeof(buffer));
    	 */
    	napc__Reader napc_Reader_create(const void *data, napc_size data_size);
    
    	/*!
    	 * @name napc_Reader_setAccessFailureMode
    	 * @brief Set action to be taken on access failure.
    	 * @version 2.0.0.
    	 * @description
    	 * Sets the action to be taken when one of the `reader` functions
    	 * fails (i.e. returns `false`).
    	 * 
    	 * The default is to log an error message.
    	 * @param ctx Pointer to the napc__Reader instance.
    	 * @param mode The fail mode to set.
    	 * @notes
    	 * Failure mode `PANIC` should be used when you're sure reads to a buffer will not fail.
    	 * 
    	 * Failure mode `NONE` can be used to disable logging.
    	 * 
    	 * Failure mode `LOG` is the default behaviour.
    	 * @changelog 2.0.0 21.10.2022 initial version
    	 */
    	void napc_Reader_setAccessFailureMode(
    		napc__Reader *ctx, napc__ReaderFailMode mode
    	);
    
    	/*!
    	 * @name napc_Reader_readU8
    	 * @brief Read an unsigned integer (8 bits).
    	 * @version 1.0.0
    	 * @description
    	 * Read an unsigned integer (8 bit) from buffer.
    	 * @param ctx Pointer to napc__Reader instance.
    	 * @param out Pointer to store result.
    	 * @changelog 1.0.0 17.02.2022 initial version
    	 * @return Returns `true` on success, `false` otherwise.
    	 * @example
    	 * napc_u8 buffer[] = {4, 3, 2, 1};
    	 * napc__Reader reader;
    	 * 
    	 * napc_Reader_init(&reader, buffer, sizeof(buffer));
    	 * 
    	 * napc_u8 out;
    	 * 
    	 * if (napc_Reader_readU8(&reader, &out)) {
    	 *     // out has the value '4'
    	 * }
    	 */
    	bool napc_Reader_readU8(
    		napc__Reader *ctx, napc_u8 *out
    	) NAPC_FN_WARNUNUSED_RET();
    
    	/*!
    	 * @name napc_Reader_readU8Array
    	 * @brief Read an array of unsigned integers (8 bits).
    	 * @version 1.0.0
    	 * @description
    	 * Read an array of unsigned integers (8 bit) from buffer.
    	 * @param ctx Pointer to napc__Reader instance.
    	 * @param n_elements Number of elements to read.
    	 * @param out Array to store bytes.
    	 * @return Returns `true` on success, `false` otherwise.
    	 * @changelog 1.0.0 17.02.2022 initial version
    	 */
    	bool napc_Reader_readU8Array(
    		napc__Reader *ctx,
    		napc_size n_elements,
    		napc_u8 *out
    	) NAPC_FN_WARNUNUSED_RET();
    
    	/*!
    	 * @name napc_Reader_readU16BE
    	 * @brief Read an unsigned integer (16 bits).
    	 * @version 1.0.0
    	 * @description
    	 * Read an unsigned integer (16 bit) in big endian order from buffer.
    	 * @param ctx Pointer to napc__Reader instance.
    	 * @param out Pointer to store result.
    	 * @return Returns `true` on success, `false` otherwise.
    	 * @changelog 1.0.0 17.02.2022 initial version
    	 * @example
    	 * napc_u8 buffer[] = {4, 3, 2, 1};
    	 * napc__Reader reader;
    	 * 
    	 * napc_Reader_init(&reader, buffer, sizeof(buffer));
    	 * 
    	 * napc_u16 out;
    	 * 
    	 * if (napc_Reader_readU16BE(&reader, &out)) {
    	 *     // out has the value 772 (0x0403)
    	 * }
    	 */
    	bool napc_Reader_readU16BE(
    		napc__Reader *ctx, napc_u16 *out
    	) NAPC_FN_WARNUNUSED_RET();
    
    	/*!
    	 * @name napc_Reader_readU32BE
    	 * @brief Read an unsigned integer (32 bits).
    	 * @version 1.0.0
    	 * @description
    	 * Read an unsigned integer (32 bit) in big endian order from buffer.
    	 * @param ctx Pointer to napc__Reader instance.
    	 * @param out Pointer to store result.
    	 * @return Returns `true` on success, `false` otherwise.
    	 * @changelog 1.0.0 17.02.2022 initial version
    	 * @example
    	 * napc_u8 buffer[] = {4, 3, 2, 1};
    	 * napc__Reader reader;
    	 * 
    	 * napc_Reader_init(&reader, buffer, sizeof(buffer));
    	 * 
    	 * napc_u32 out;
    	 * 
    	 * if (napc_Reader_readU32BE(&reader, &out)) {
    	 *     // out has the value 67305985 (0x04030201)
    	 * }
    	 */
    	bool napc_Reader_readU32BE(
    		napc__Reader *ctx, napc_u32 *out
    	) NAPC_FN_WARNUNUSED_RET();
    
    	/*!
    	 * @name napc_Reader_readChar
    	 * @brief Read a single character.
    	 * @version 1.0.0
    	 * @description
    	 * Read a character (8 bit) from buffer.
    	 * @param ctx Pointer to napc__Reader instance.
    	 * @param out Pointer to store result.
    	 * @return Returns `true` on success, `false` otherwise.
    	 * @changelog 1.0.0 17.02.2022 initial version
    	 */
    	bool napc_Reader_readChar(
    		napc__Reader *ctx, char *out
    	) NAPC_FN_WARNUNUSED_RET();
    
    	/*!
    	 * @name napc_Reader_readString
    	 * @brief Read a string.
    	 * @version 1.0.0
    	 * @description
    	 * Read a string from buffer.
    	 * @param ctx Pointer to napc__Reader instance.
    	 * @param str_len Length of string to be read.
    	 * @param out Pointer to store result.
    	 * @param out_size Size of `out`.
    	 * @return Returns `true` on success, `false` otherwise.
    	 * @notes
    	 * Resulting string (that is placed in `out`) is always NUL-terminated.
    	 * @changelog 1.0.0 17.02.2022 initial version
    	 */
    	bool napc_Reader_readString(
    		napc__Reader *ctx,
    		napc_size str_len,
    		char *out,
    		napc_size out_size
    	) NAPC_FN_WARNUNUSED_RET();
    
    	/*!
    	 * @name napc_Reader_readLine
    	 * @brief Read a line.
    	 * @version 1.0.0
    	 * @description
    	 * Read a line from buffer.
    	 * @param ctx Pointer to napc__Reader instance.
    	 * @param line_buffer Buffer to place line into.
    	 * @param line_buffer_size Size of the line buffer.
    	 * @return Returns `line_buffer` if a line was parsed, `NULL` otherwise.
    	 * @notes
    	 * The resulting string in `line_buffer` will always be NUL-terminated.
    	 * @changelog 1.0.0 17.02.2022 initial version
    	 * @example
    	 * char line_buffer[128];
    	 * napc__Reader reader;
    	 * const char *str = "First line\nSecond line\nThird line";
    	 * 
    	 * napc_Reader_init(&reader, str, napc_strlen(str));
    	 * 
    	 * while (true) {
    	 *     const char *current_line = napc_Reader_readLine(&reader, line_buffer, sizeof(line_buffer));
    	 * 
    	 *     if (!current_line) break;
    	 * 
    	 *     napc_printf("Read line: %s", current_line);
    	 * }
    	 */
    	const char *napc_Reader_readLine(
    		napc__Reader *ctx, char *line_buffer, napc_size line_buffer_size
    	);
    
    	/*!
    	 * @name napc_Reader_getCurrentOffset
    	 * @brief Get current offset.
    	 * @version 2.0.0
    	 * @description
    	 * Returns the current offset the reader is at.
    	 * @changelog 2.0.0 10.04.2022 initial version
    	 */
    	napc_size napc_Reader_getCurrentOffset(
    		const napc__Reader *ctx
    	);
    
    	/*!
    	 * @name napc_Reader_getRemainingBytes
    	 * @brief Get remaining bytes to be read.
    	 * @version 2.0.0
    	 * @description
    	 * Returns the remaining bytes to be read `(size - offset)`.
    	 * @changelog 2.0.0 10.04.2022 initial version
    	 */
    	napc_size napc_Reader_getRemainingBytes(
    		const napc__Reader *ctx
    	);
    
    	/*!
    	 * @name napc_Reader_getCurrentAddress
    	 * @brief Get current address.
    	 * @version 2.0.0
    	 * @description
    	 * Returns the current address the reader is at `(data + offset)`.
    	 * @changelog 2.0.0 10.04.2022 initial version
    	 */
    	const void *napc_Reader_getCurrentAddress(
    		const napc__Reader *ctx
    	);
    
    	/*!
    	 * @name napc_Reader_getStartAddress
    	 * @brief Get the start address.
    	 * @version 2.0.0
    	 * @description
    	 * Returns the start address.
    	 * @changelog 2.0.0 10.04.2022 initial version
    	 */
    	const void *napc_Reader_getStartAddress(
    		const napc__Reader *ctx
    	);
    
    	/*!
    	 * @name napc_Reader_getEndAddress
    	 * @brief Get the last address.
    	 * @version 2.0.0
    	 * @description
    	 * Returns the end address `(data + (size - 1))`.
    	 * @changelog 2.0.0 10.04.2022 initial version
    	 */
    	const void *napc_Reader_getEndAddress(
    		const napc__Reader *ctx
    	);
    #endif

/* original: #include <module/writer/writer.h> */
    /*!
     * @name Writer:intro
     * @brief Binary buffer writer
     */
    #if !defined(NAPC_MODULE_WRITER_h)
    	#define NAPC_MODULE_WRITER_h
    

/* original: #include <libnapc.h> */
/* header file already included */

/* original: #include <napc-magic/napc-magic.h> */
/* header file already included */
    
    	/*!
    	 * @name napc__WriterFailMode
    	 * @module Writer
    	 * @brief Action to be taken on failure.
    	 * @version 2.0.0
    	 * @enum NAPC_WRITER_FAILMODE_NONE Do nothing.
    	 * @enum NAPC_WRITER_FAILMODE_LOG Emit a log message of type error. This is the default.
    	 * @enum NAPC_WRITER_FAILMODE_PANIC Call NAPC_PANIC.
    	 * @changelog 2.0.0 21.10.2022 initial version
    	 */
    	typedef enum napc__WriterFailMode {
    		NAPC_WRITER_FAILMODE_NONE  = 0x01, // 0000 0001
    		NAPC_WRITER_FAILMODE_LOG   = 0x02, // 0000 0010
    		NAPC_WRITER_FAILMODE_PANIC = 0x04  // 0000 0100
    	} napc__WriterFailMode;
    
    	/*!
    	 * @name napc__Writer
    	 * @module Writer
    	 * @brief Representation of a writer.
    	 * @version 1.0.0
    	 * @opaque
    	 * @changelog 1.0.0 17.02.2022 initial version
    	 * @changelog 2.0.0 21.10.2022 add mode
    	 */
    	typedef struct napc__Writer {
    		NAPC_MAGIC_MEMBER;
    
    		napc__WriterFailMode _fail_mode;
    
    		napc_size _offset;
    		napc_size size;
    		void *data;
    	} napc__Writer;
    
    	/*!
    	 * @name napc_Writer_init
    	 * @brief Initialize a writer.
    	 * @version 1.0.0.
    	 * @description
    	 * Initialize a writer.
    	 * @param ctx Pointer to the napc__Writer instance to be initialized.
    	 * @param data Pointer to the buffer that we want to write to.
    	 * @param data_size Size of `data`.
    	 * @changelog 1.0.0 17.02.2022 initial version
    	 * @changelog 2.0.0 21.10.2022 add mode
    	 * @example
    	 * napc__Writer writer;
    	 * char buffer[512];
    	 * 
    	 * napc_Writer_init(&writer, buffer, sizeof(buffer));
    	 */
    	void napc_Writer_init(
    		napc__Writer *ctx, void *data, napc_size data_size
    	);
    
    	/*!
    	 * @name napc_Writer_create
    	 * @brief Create a writer object.
    	 * @version 1.0.0.
    	 * @description
    	 * Create a writer.
    	 * @param data Pointer to the buffer that we want to write to.
    	 * @param data_size Size of `data`.
    	 * @changelog 1.0.0 17.02.2022 initial version
    	 * @changelog 2.0.0 21.10.2022 add mode
    	 * @example
    	 * char buffer[512];
    	 * 
    	 * napc__Writer writer = napc_Writer_create(buffer, sizeof(buffer));
    	 */
    	napc__Writer napc_Writer_create(void *data, napc_size data_size);
    
    	/*!
    	 * @name napc_Writer_setAccessFailureMode
    	 * @brief Set action to be taken on access failure.
    	 * @version 2.0.0.
    	 * @description
    	 * Sets the action to be taken when one of the `write` functions
    	 * fails (i.e. returns `false`).
    	 * 
    	 * The default is to log an error message.
    	 * @param ctx Pointer to the napc__Writer instance.
    	 * @param mode The fail mode to set.
    	 * @notes
    	 * Failure mode `PANIC` should be used when you're sure writes to a buffer will not fail.
    	 * 
    	 * Failure mode `NONE` can be used to disable logging.
    	 * 
    	 * Failure mode `LOG` is the default behaviour.
    	 * @changelog 2.0.0 21.10.2022 initial version
    	 */
    	void napc_Writer_setAccessFailureMode(
    		napc__Writer *ctx, napc__WriterFailMode mode
    	);
    
    	/*!
    	 * @name napc_Writer_moveCurrentOffsetByAmount
    	 * @brief Move internal offset.
    	 * @version 1.0.0
    	 * @description
    	 * Move offset by `amount` of bytes.
    	 * A negative `offset` is permitted.
    	 * @param ctx Pointer to the napc__Writer instance.
    	 * @param amount The amount.
    	 * @return Returns `true` on success, otherwise `false`.
    	 * @changelog 1.0.0 17.02.2022 initial version
    	 */
    	bool napc_Writer_moveCurrentOffsetByAmount(
    		napc__Writer *ctx, napc_ssize amount
    	);
    
    	/*!
    	 * @name napc_Writer_resetCurrentOffset
    	 * @brief Reset internal offset.
    	 * @version 1.0.0
    	 * @description
    	 * Reset offset back to zero.
    	 * @param ctx Pointer to the napc__Writer instance.
    	 * @changelog 1.0.0 17.02.2022 initial version
    	 */
    	void napc_Writer_resetCurrentOffset(
    		napc__Writer *ctx
    	);
    
    	/*!
    	 * @name napc_Writer_writeU8
    	 * @brief Write an unsigned integer (8 bits).
    	 * @version 1.0.0
    	 * @description
    	 * Write the unsigned integer value `value`.
    	 * @param ctx Pointer to the napc__Writer instance.
    	 * @param value Value to be written.
    	 * @return Returns `true` on success, otherwise `false`.
    	 * @changelog 1.0.0 17.02.2022 initial version
    	 * @example
    	 * napc__Writer writer;
    	 * char buffer[512];
    	 * 
    	 * napc_Writer_init(&writer, buffer, sizeof(buffer));
    	 * 
    	 * napc_Writer_writeU8(&writer, 0xAA);
    	 * napc_Writer_writeU8(&writer, 0xBB);
    	 * 
    	 * // buffer[0] is now 0xAA
    	 * // buffer[1] is now 0xBB
    	 */
    	bool napc_Writer_writeU8(
    		napc__Writer *ctx, napc_u8 value
    	);
    
    	/*!
    	 * @name napc_Writer_writeU8Array
    	 * @brief Write an array unsigned integers (8 bits).
    	 * @version 1.0.0
    	 * @description
    	 * Write an array of unsigned integer values.
    	 * @param ctx Pointer to the napc__Writer instance.
    	 * @param n_elements The number of elements in `array`.
    	 * @param array The array to be written.
    	 * @return Returns `true` on success, otherwise `false`.
    	 * @changelog 1.0.0 17.02.2022 initial version
    	 */
    	bool napc_Writer_writeU8Array(
    		napc__Writer *ctx,
    		napc_size n_elements,
    		const napc_u8 *array
    	); // needs test
    
    	/*!
    	 * @name napc_Writer_writeU16BE
    	 * @brief Write an unsigned integer (16 bits).
    	 * @version 1.0.0
    	 * @description
    	 * Write the 16 bit unsigned integer value `value` in big endian order.
    	 * @param ctx Pointer to the napc__Writer instance.
    	 * @param value Value to be written.
    	 * @return Returns `true` on success, otherwise `false`.
    	 * @changelog 1.0.0 17.02.2022 initial version
    	 */
    	bool napc_Writer_writeU16BE(
    		napc__Writer *ctx, napc_u16 value
    	);
    
    	/*!
    	 * @name napc_Writer_writeU32BE
    	 * @brief Write an unsigned integer (32 bits).
    	 * @version 1.0.0
    	 * @description
    	 * Write the 32 bit unsigned integer value `value` in big endian order.
    	 * @param ctx Pointer to the napc__Writer instance.
    	 * @param value Value to be written.
    	 * @return Returns `true` on success, otherwise `false`.
    	 * @changelog 1.0.0 17.02.2022 initial version
    	 */
    	bool napc_Writer_writeU32BE(
    		napc__Writer *ctx, napc_u32 value
    	);
    
    	/*!
    	 * @name napc_Writer_writeChar
    	 * @brief Write a single character.
    	 * @version 1.0.0
    	 * @description
    	 * Attempts to write the character `value`.
    	 * @param ctx Pointer to the napc__Writer instance.
    	 * @param value Character to be written.
    	 * @return Returns `true` on success, otherwise `false`.
    	 * @changelog 1.0.0 17.02.2022 initial version
    	 */
    	bool napc_Writer_writeChar(
    		napc__Writer *ctx, char value
    	);
    
    	/*!
    	 * @name napc_Writer_writeString
    	 * @brief Write a string.
    	 * @version 1.0.0
    	 * @description
    	 * Write a string.
    	 * @param ctx Pointer to the napc__Writer instance.
    	 * @param value String to be written.
    	 * @return Returns `true` on success, otherwise `false`.
    	 * @notes
    	 * No NUL-termination will be placed in the underlying buffer.
    	 * @changelog 1.0.0 17.02.2022 initial version
    	 */
    	bool napc_Writer_writeString(
    		napc__Writer *ctx, const char *value
    	);
    
    	/*!
    	 * @name napc_Writer_writeStringFormat
    	 * @brief Write a string format.
    	 * @version 1.0.0
    	 * @description
    	 * Write a printf-like formatted string.
    	 * @param ctx Pointer to the napc__Writer instance.
    	 * @param fmt printf()-like format string.
    	 * @param ... Values to incorporate into string.
    	 * @return Returns `true` on success, otherwise `false`.
    	 * @flags smem
    	 * @notes
    	 * No NUL-termination will be placed in the underlying buffer.
    	 * @changelog 1.0.0 17.02.2022 initial version
    	 * @example
    	 * napc__Writer writer;
    	 * char buffer[512];
    	 * 
    	 * napc_Writer_init(&writer, buffer, sizeof(buffer));
    	 * 
    	 * napc_Writer_writeStringFormat(&writer, "Hello %s!", "World!");
    	 * 
    	 * // the first 12 bytes of `buffer`
    	 * // now contain "Hello World!"
    	 */
    	bool napc_Writer_writeStringFormat(
    		napc__Writer *ctx, const char *fmt, ...
    	) NAPC_FN_PRINTFLIKE(2, 3);
    
    	/*!
    	 * @name napc_Writer_getCurrentOffset
    	 * @brief Get internal offset.
    	 * @version 1.0.0
    	 * @description
    	 * Get buffer offset from the writer instance.
    	 * @return Returns the current buffer offset from the writer instance.
    	 * @param ctx Pointer to the napc__Writer instance.
    	 * @changelog 1.0.0 17.02.2022 initial version
    	 */
    	napc_size napc_Writer_getCurrentOffset(
    		const napc__Writer *ctx
    	);
    
    	/*!
    	 * @name napc_Writer_getCurrentAddress
    	 * @brief Get current address.
    	 * @version 2.0.0
    	 * @description
    	 * Returns the current address the writer is at `(data + offset)`.
    	 * @changelog 2.0.0 12.04.2022 initial version
    	 */
    	void *napc_Writer_getCurrentAddress(
    		const napc__Writer *ctx
    	);
    
    	/*!
    	 * @name napc_Writer_getStartAddress
    	 * @brief Get the start address.
    	 * @version 2.0.0
    	 * @description
    	 * Returns the start address.
    	 * @changelog 2.0.0 12.04.2022 initial version
    	 */
    	void *napc_Writer_getStartAddress(
    		const napc__Writer *ctx
    	);
    
    	/*!
    	 * @name napc_Writer_getEndAddress
    	 * @brief Get the last address.
    	 * @version 2.0.0
    	 * @description
    	 * Returns the end address `(data + (size - 1))`.
    	 * @changelog 2.0.0 12.04.2022 initial version
    	 */
    	void *napc_Writer_getEndAddress(
    		const napc__Writer *ctx
    	);
    #endif

/* original: #include <module/ipv4participant/ipv4participant.h> */
    /*!
     * @name IPv4Participant:intro
     * @description
     * To reduce parameter count this module is used to combine an IPv4-Address and a port number:
     * 
     * ```c
     * // Holds address for google's DNS server 8.8.8.8:53
     * napc__IPv4Participant google_dns;
     * 
     * // Initialize google_dns variable
     * napc_IPv4Participant_init(&google_dns, "8.8.8.8", 53);
     * ```
     */
    #if !defined(NAPC_MODULE_IPV4PARTICIPANT_h)
    	#define NAPC_MODULE_IPV4PARTICIPANT_h
    

/* original: #include <libnapc.h> */
/* header file already included */

/* original: #include <module/net/net.h> */
        #if !defined(NAPC_MODULE_NET_h)
        	#define NAPC_MODULE_NET_h
        

/* original: #include <libnapc.h> */
/* header file already included */
        
        	#define NAPC_MODULE_NET_IP_STR_MAX 64u
        #endif
    

/* original: #include <napc-magic/napc-magic.h> */
/* header file already included */
    
    	/*!
    	 * @name napc__IPv4Participant
    	 * @module IPv4Participant
    	 * @brief Representation a network device.
    	 * @version 1.0.0
    	 * @description
    	 * Representation of a participant in the internet protocol version 4 (IPv4).
    	 * @field addr IPv4-Address as string in format `a.b.c.d`.
    	 * @field port Port number.
    	 * @changelog 1.0.0 17.02.2022 initial version
    	 */
    	typedef struct napc__IPv4Participant {
    		NAPC_MAGIC_MEMBER;
    
    		char addr[NAPC_MODULE_NET_IP_STR_MAX];
    		napc_u16 port;
    	} napc__IPv4Participant;
    
    	/*!
    	 * @name napc_IPv4Participant_init
    	 * @brief Initialize a participant.
    	 * @version 1.0.0
    	 * @description
    	 * Initialize a participant.
    	 * @param participant Pointer to instance to initialize.
    	 * @param addr IPv4-Address of participant in format `a.b.c.d`.
    	 * @param port Port of participant.
    	 * @notes
    	 * Input address (`addr`) will be copied into `participant`.
    	 * @changelog 1.0.0 17.02.2022 initial version
    	 */
    	void napc_IPv4Participant_init(
    		napc__IPv4Participant *participant,
    		const char *addr, napc_u16 port
    	);
    
    	/*!
    	 * @name napc_IPv4Participant_create
    	 * @brief Create a participant object.
    	 * @version 1.0.0
    	 * @description
    	 * Create a participant.
    	 * @param addr IPv4-Address of participant in format `a.b.c.d`.
    	 * @param port Port of participant.
    	 * @return Returns an initialized participant.
    	 * @notes
    	 * Input address (`addr`) will be copied into `participant`.
    	 * @changelog 1.0.0 17.02.2022 initial version
    	 * @example
    	 * napc__IPv4Participant google_dns = napc_IPv4Participant_create("8.8.8.8", 53);
    	 */
    	napc__IPv4Participant napc_IPv4Participant_create(const char *addr, napc_u16 port);
    
    	/*!
    	 * @name napc_IPv4Participant_copy
    	 * @brief Copy a participant.
    	 * @version 1.0.0
    	 * @description
    	 * Create a copy of a participant.
    	 * @param dest Pointer to destination.
    	 * @param source Source.
    	 * @todo make source a pointer too and add const?
    	 * @changelog 1.0.0 17.02.2022 initial version
    	 */
    	void napc_IPv4Participant_copy(
    		napc__IPv4Participant *dest,
    		napc__IPv4Participant source
    	);
    #endif

/* original: #include <module/dns/dns.h> */
    #if !defined(NAPC_MODULE_DNS_h)
    	#define NAPC_MODULE_DNS_h
    

/* original: #include <libnapc.h> */
/* header file already included */

/* original: #include <module/dns/dns-header.h> */
        #if !defined(NAPC_MODULE_DNS_HEADER_h)
        	#define NAPC_MODULE_DNS_HEADER_h
        

/* original: #include <libnapc.h> */
/* header file already included */
        
        	/*!
        	 * @name napc__DNSOPCode
        	 * @module DNS
        	 * @brief Representation of a DNS operation code.
        	 * @version 1.0.0
        	 * @enum NAPC_DNS_OPCODE_QUERY Standard DNS-Query.
        	 * @enum NAPC_DNS_OPCODE_IQUERY Inverse DNS-Query.
        	 * @enum NAPC_DNS_OPCODE_STATUS Status query.
        	 * @enum NAPC_DNS_OPCODE_NOTIFY
        	 * @enum NAPC_DNS_OPCODE_UPDATE
        	 */
        	typedef enum napc__DNSOPCode {
        		NAPC_DNS_OPCODE_QUERY,
        		NAPC_DNS_OPCODE_IQUERY,
        		NAPC_DNS_OPCODE_STATUS,
        		NAPC_DNS_OPCODE_NOTIFY,
        		NAPC_DNS_OPCODE_UPDATE
        	} napc__DNSOPCode;
        
        	/*!
        	 * @name napc__DNSHeader
        	 * @module DNS
        	 * @brief Representation of a DNS header.
        	 * @version 2.0.0
        	 * @field raw_flags Contains the raw dns header flags (16 bit)
        	 * @field opcode DNS operation code. See `napc__DNSOPCode`.
        	 * @field authoritative_answer Authoritative answer flag.
        	 * @field truncated Truncated flag.
        	 * @field request_identifier DNS request identifier.
        	 * @field response_code DNS-Server response code.
        	 * @field question_count Number of DNS queries.
        	 * @field answer_count Number of DNS answers.
        	 * @changelog 1.0.0 17.02.2022 initial version
        	 * @changelog 2.0.0 12.04.2022 added `raw_flags` member
        	 */
        	typedef struct napc__DNSHeader {
        		napc_u16 raw_flags;
        
        		napc__DNSOPCode opcode;
        
        		bool authoritative_answer;
        		bool truncated;
        //		bool recursion_desired;
        //		bool recursion_available;
        
        		napc_u16 request_identifier;
        		napc_u16 response_code;
        		napc_u16 question_count;
        		napc_u16 answer_count;
        	} napc__DNSHeader;
        
        	/*!
        	 * @name napc_DNS_parseHeader
        	 * @brief Parse a DNS-Header from a buffer.
        	 * @version 1.0.0
        	 * @param out Pointer to a `napc__DNSHeader` to store result.
        	 * @param buffer Buffer to be parsed.
        	 * @param buffer_size Size of buffer.
        	 * @return Returns `true` on success, `false` otherwise.
        	 * @changelog 1.0.0 17.02.2022 initial version
        	 */
        	bool napc_DNS_parseHeader(
        		napc__DNSHeader *out,
        		const void *buffer, napc_size buffer_size
        	) NAPC_FN_WARNUNUSED_RET();
        #endif

/* original: #include <module/dns/dns-query.h> */
        #if !defined(NAPC_MODULE_DNS_QUERY_h)
        	#define NAPC_MODULE_DNS_QUERY_h
        

/* original: #include <libnapc.h> */
/* header file already included */

/* original: #include <module/dns/dns-qtype.h> */
            #if !defined(NAPC_MODULE_DNS_QTYPE_h)
            	#define NAPC_MODULE_DNS_QTYPE_h
            

/* original: #include <libnapc.h> */
/* header file already included */
            
            	/*!
            	 * @name napc__DNSQType
            	 * @module DNS
            	 * @brief Representation of DNS query type.
            	 * @version 1.0.0
            	 * @enum NAPC_DNS_QTYPE_A A-Record query
            	 * @enum NAPC_DNS_QTYPE_CNAME CNAME-Record query
            	 * @enum NAPC_DNS_QTYPE_MX MX-Record query
            	 * @enum NAPC_DNS_QTYPE_TXT TXT-Record query
            	 * @enum NAPC_DNS_QTYPE_AAAA AAAA-Record query
            	 * @changelog 1.0.0 17.02.2022 initial version
            	 * @changelog 2.0.0 14.04.2022 added CNAME,MX and TXT types
            	 */
            	typedef enum napc__DNSQType {
            		NAPC_DNS_QTYPE_A     = 1,
            		NAPC_DNS_QTYPE_CNAME = 5,
            		NAPC_DNS_QTYPE_MX    = 15,
            		NAPC_DNS_QTYPE_TXT   = 16,
            		NAPC_DNS_QTYPE_AAAA  = 28
            	} napc__DNSQType;
            #endif
        
        	#define NAPC_MODULE_DNS_MAX_NAME 64 // was 254 before
        
        	/*!
        	 * @name napc__DNSQuery
        	 * @module DNS
        	 * @brief Representation of a DNS query.
        	 * @version 1.0.0
        	 * @field name Name to lookup.
        	 * @field qtype Query type, see `napc__DNSQType`.
        	 * @changelog 1.0.0 17.02.2022 initial version
        	 */
        	typedef struct napc__DNSQuery {
        		char name[NAPC_MODULE_DNS_MAX_NAME];
        		napc__DNSQType qtype;
        	} napc__DNSQuery;
        #endif

/* original: #include <module/dns/dns-answer.h> */
        #if !defined(NAPC_MODULE_DNS_ANSWER_h)
        	#define NAPC_MODULE_DNS_ANSWER_h
        

/* original: #include <libnapc.h> */
/* header file already included */
        
        	#define NAPC_MODULE_DNS_MAX_RD_DATA_LENGTH 16u
        
        	/*!
        	 * @name napc__DNSAnswer
        	 * @module DNS
        	 * @brief Representation of a DNS answer.
        	 * @version 1.0.0
        	 * @field ttl Time to live (in seconds).
        	 * @field rd_length Response data size in bytes.
        	 * @field rd_data Response data.
        	 * @changelog 1.0.0 17.02.2022 initial version
        	 */
        	typedef struct napc__DNSAnswer {
        		napc_u32 ttl;
        
        		napc_u16 rd_length;
        		napc_u8 rd_data[NAPC_MODULE_DNS_MAX_RD_DATA_LENGTH];
        	} napc__DNSAnswer;
        #endif
    

/* original: #include <module/reader/reader.h> */
/* header file already included */
    
    	#define NAPC_MODULE_DNS_MAX_ANSWERS 4u
    
    	/*!
    	 * @name napc__DNSRequest
    	 * @module DNS
    	 * @brief Representation of a DNS request.
    	 * @version 1.0.0
    	 * @field header DNS-Header, see `napc__DNSHeader`.
    	 * @field query DNS-Query, see `napc__DNSQuery`.
    	 * @changelog 1.0.0 17.02.2022 initial version
    	 */
    	typedef struct napc__DNSRequest {
    		napc__DNSHeader header;
    		napc__DNSQuery query;
    	} napc__DNSRequest;
    
    	/*!
    	 * @name napc__DNSResponse
    	 * @module DNS
    	 * @brief Representation of a DNS response.
    	 * @version 1.0.0
    	 * @field header DNS-Header, see `napc__DNSHeader`.
    	 * @field num_answers Represents number of elements in `answers` array.
    	 * @field answers DNS-Answers, see `napc__DNSAnswer`.
    	 * @changelog 1.0.0 17.02.2022 initial version
    	 */
    	typedef struct napc__DNSResponse {
    		napc__DNSHeader header;
    		// this field is different from header.answer_count
    		// header.answer_count contains the raw count of the number of
    		// answers present in the response.
    		// num_answers says how many elements are in the answers[] array
    		// (might be capped)
    		napc_size num_answers;
    		napc__DNSAnswer answers[NAPC_MODULE_DNS_MAX_ANSWERS];
    	} napc__DNSResponse;
    
    	/*!
    	 * @name napc_DNS_parseRequest
    	 * @brief Parse a DNS-Request from a buffer.
    	 * @version 1.0.0
    	 * @param out Pointer to a `napc__DNSRequest` to store result.
    	 * @param buffer Buffer to be parsed.
    	 * @param buffer_size Size of buffer.
    	 * @return Returns `true` on success, `false` otherwise.
    	 * @changelog 1.0.0 17.02.2022 initial version
    	 */
    	bool napc_DNS_parseRequest(
    		napc__DNSRequest *out,
    		const void *buffer, napc_size buffer_size
    	) NAPC_FN_WARNUNUSED_RET();
    
    	/*!
    	 * @name napc_DNS_parseResponse
    	 * @brief Parse a DNS-Response from a buffer.
    	 * @version 1.0.0
    	 * @description
    	 * Parse a DNS-Response from a buffer.
    	 * @param out Pointer to a `napc__DNSResponse` to store result.
    	 * @param buffer Buffer to be parsed.
    	 * @param buffer_size Size of buffer.
    	 * @return Returns `true` on success, `false` otherwise.
    	 * @changelog 1.0.0 17.02.2022 initial version
    	 */
    	bool napc_DNS_parseResponse(
    		napc__DNSResponse *out,
    		const void *buffer, napc_size buffer_size
    	) NAPC_FN_WARNUNUSED_RET();
    #endif

/* original: #include <module/sha/sha.h> */
    #if !defined(NAPC_MODULE_SHA_h)
    	#define NAPC_MODULE_SHA_h
    

/* original: #include <libnapc.h> */
/* header file already included */
    
    	/*!
    	 * @name napc_sha_calculate
    	 * @brief Calculate SHA256 hash.
    	 * @version 1.5.0
    	 * @description
    	 * Calculates the SHA-256 hash of a message.
    	 * @param buffer Buffer to calculate hash of.
    	 * @param buffer_size Size of buffer.
    	 * @param out Array to store output in HEX format (32 bytes).
    	 * @param out_size Size of output array.
    	 * @warning The output array must have at least 65 elements.
    	 * @changelog 1.5.0 25.03.2022 initial version
    	 * @example
    	 * char out[65];
    	 * const char *str = "secret";
    	 * 
    	 * napc_sha_calculate(str, napc_strlen(str), out, sizeof(out));
    	 * 
    	 * napc_printf("SHA256-hash of '%s' is '%s'\n");
    	 */
    	bool napc_sha_calculate(
    		const void *buffer, napc_size buffer_size,
    		char *out, napc_size out_size
    	) NAPC_FN_WARNUNUSED_RET();
    #endif


/* original: #include <hw.module/eth/eth.h> */
    #if !defined(NAPC_HW_MODULE_ETH_h)
    	#define NAPC_HW_MODULE_ETH_h
    

/* original: #include <libnapc.h> */
/* header file already included */
    
    	/*!
    	 * @name napc_eth_getLinkStatus
    	 * @brief Get the link status of network adapter.
    	 * @version 1.0.0
    	 * @return Returns `true` if ethernet link is established, `false` otherwise.
    	 * @changelog 1.0.0 17.02.2022 initial version
    	 * @example
    	 * if (napc_eth_getLinkStatus()) {
    	 *     napc_printf("Ethernet link established.\n");
    	 * }
    	 */
    	bool napc_eth_getLinkStatus(void) NAPC_FN_WARNUNUSED_RET();
    
    	/*!
    	 * @name napc_eth_setMACAddress
    	 * @brief Set mac address of network adapter.
    	 * @version 1.0.0
    	 * @param mac MAC-Address in format `aa:bb:cc:dd:ee:ff`.
    	 * @changelog 1.0.0 17.02.2022 initial version
    	 * @example
    	 * napc_eth_setMACAddress("88:24:D3:27:9A:2F");
    	 */
    	void napc_eth_setMACAddress(const char *mac);
    
    	/*!
    	 * @name napc_eth_setIPAddress
    	 * @brief Set ip address of network adapter.
    	 * @version 1.0.0
    	 * @param ip IPv4-Address in format `a.b.c.d`.
    	 * @changelog 1.0.0 17.02.2022 initial version
    	 * @example
    	 * napc_eth_setIPAddress("192.168.1.50");
    	 */
    	void napc_eth_setIPAddress(const char *ip);
    
    	/*!
    	 * @name napc_eth_setSubnetMask
    	 * @brief Set subnetmask of network adapter.
    	 * @version 1.0.0
    	 * @param submask Subnetmask in format `a.b.c.d`.
    	 * @changelog 1.0.0 17.02.2022 initial version
    	 * @example
    	 * napc_eth_setSubnetMask("255.255.255.0");
    	 */
    	void napc_eth_setSubnetMask(const char *submask);
    
    	/*!
    	 * @name napc_eth_setGatewayAddress
    	 * @brief Set the gateway address of network adapter.
    	 * @version 1.0.0
    	 * @param ip IPv4-Address in format `a.b.c.d`.
    	 * @changelog 1.0.0 17.02.2022 initial version
    	 * @example
    	 * napc_eth_setGatewayAddress("192.168.1.1");
    	 */
    	void napc_eth_setGatewayAddress(const char *ip);
    
    	/*!
    	 * @name napc_eth_calculateBroadcastAddress
    	 * @brief Calulcate broadcast address of IP-address.
    	 * @version 2.0.0
    	 * @param ip IPv4-Address in format `a.b.c.d`.
    	 * @param submask IPv4-Subnetmask in format `a.b.c.d`.
    	 * @param out Output array.
    	 * @param out_size Size of output array.
    	 * @changelog 2.0.0 12.04.2022 initial version
    	 * @example
    	 * char broadcast_addr[32];
    	 * 
    	 * bool result = napc_eth_calculateBroadcastAddress(
    	 *     "10.1.2.5",
    	 *     "255.255.255.0",
    	 *     broadcast_addr, sizeof(broadcast_addr)
    	 * );
    	 * 
    	 * if (result) {
    	 *     napc_printf("Broadcast address of 10.1.2.5 is %s\n", broadcast_addr);
    	 * }
    	 */
    	bool napc_eth_calculateBroadcastAddress(
    		const char *ip,
    		const char *submask,
    		char *out, napc_size out_size
    	) NAPC_FN_WARNUNUSED_RET();
    #endif

/* original: #include <hw.module/udp/udp.h> */
    /*!
     * @name UDP:intro
     * @brief Send & receive network packets
     * @description
     * Used to send and/or receive IP packets over the UDP protocol.
     * @example
     * #include <napc.h>
     *
     * napc__UDPSocket sock;
     * int counter = 0;
     *
     * void napc_setup(const char *p) {
     * 	if (!napc_env_isEthernetAvailable()) {
     * 		NAPC_PANIC("Sorry, ethernet is not available :(\n");
     * 	}
     *
     * 	// initialize ethernet
     * 	napc_eth_setIPAddress("192.168.0.20");
     * 	napc_eth_setMACAddress("aa:bb:cc:dd:ee:ff");
     *
     * 	// open udp socket on port 2020
     * 	sock = napc_UDP_createSocket(2020);
     *
     * 	napc_printf("Opened UDP socket on port 2020\n");
     * }
     *
     * bool napc_loop(napc_time uptime) {
     * 	char packet_buffer[512];
     *
     * 	napc__Buffer buffer = napc_Buffer_create(packet_buffer, sizeof(packet_buffer));
     * 	napc__IPv4Participant source_ip;
     *
     * 	if (napc_UDP_receive(sock, &source_ip, &buffer)) {
     * 		napc_printf(
     * 			"Received %" NAPC_SIZE_PRINTF " bytes from %s:%u\n",
     * 			buffer.size,
     * 			source_ip.addr,
     * 			source_ip.port
     * 		);
     *
     * 		napc_UDP_send(sock, source_ip, buffer.data, buffer.size);
     * 	}
     *
     * 	return true;
     * }
     */
    #if !defined(NAPC_HW_MODULE_UDP_h)
    	#define NAPC_HW_MODULE_UDP_h
    

/* original: #include <libnapc.h> */
/* header file already included */
    

/* original: #include <module/ipv4participant/ipv4participant.h> */
/* header file already included */

/* original: #include <module/buffer/buffer.h> */
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
        

/* original: #include <libnapc.h> */
/* header file already included */
        

/* original: #include <napc-magic/napc-magic.h> */
/* header file already included */
        
        	/*!
        	 * @name napc__Buffer
        	 * @module Buffer
        	 * @brief Representation of a memory buffer.
        	 * @version 1.0.0
        	 * @field size Size of data.
        	 * @field data Pointer to data.
        	 * @changelog 1.0.0 17.02.2022 initial version
        	 */
        	typedef struct napc__Buffer {
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
    
    	/*!
    	 * @name napc__UDPSocket
    	 * @module UDP
    	 * @brief Representation of a UDP-Socket.
    	 * @version 1.0.0
    	 * @opaque
    	 * @changelog 1.0.0 17.02.2022 initial version
    	 */
    	typedef napc_ssize napc__UDPSocket;
    
    	/*!
    	 * @name napc_UDP_createSocket
    	 * @brief Open an UDP-Socket.
    	 * @version 1.0.0
    	 * @description
    	 * Open an UDP-socket on port `port` for receiving and sending messages.
    	 * @param port IPv4 port number.
    	 * @return Returns a negative number if socket could not be created.
    	 * @changelog 1.0.0 17.02.2022 initial version
    	 * @example
    	 * napc__UDPSocket udp_sock = napc_UDP_createSocket(2020);
    	 * 
    	 * if (0 > udp_sock) {
    	 *     NAPC_PANIC("Failed to create UDP-socket.");
    	 * }
    	 */
    	napc__UDPSocket napc_UDP_createSocket(napc_u16 port);
    
    	/*!
    	 * @name napc_UDP_receive
    	 * @brief Receive an UDP-message.
    	 * @version 1.0.0
    	 * @description
    	 * Receive a message on a UDP socket.
    	 * @param udp_socket The UDP socket to receive from.
    	 * @param source Source of received message (optional).
    	 * @param out Pointer to a buffer to place received message.
    	 * @return Returns `false` if no message was received.
    	 * @warning It's not possible to receive a UDP packet with a size greater than `1500` bytes (MTU limit).
    	 * @changelog 1.0.0 17.02.2022 initial version
    	 * @example
    	 * char message_buffer[512];
    	 * napc__Buffer buf;
    	 * 
    	 * napc__UDPSocket udp_socket = napc_UDP_createSocket(2020);
    	 * 
    	 * napc_Buffer_init(&buf, message_buffer, sizeof(message_buffer));
    	 * 
    	 * if (napc_UDP_receive(&udp_socket, NULL, &buf)) {
    	 *     napc_printf("Received %" NAPC_SIZE_PRINTF " bytes\n", buf.size);
    	 * }
    	 */
    	bool napc_UDP_receive(
    		napc__UDPSocket udp_socket,
    		napc__IPv4Participant *source,
    		napc__Buffer *out
    	) NAPC_FN_WARNUNUSED_RET();
    
    	/*!
    	 * @name napc_UDP_send
    	 * @brief Send an UPD-message.
    	 * @version 1.0.0
    	 * @description
    	 * Send a UDP message to `destination`.
    	 * @param udp_socket The UDP socket to write the message to.
    	 * @param destination IPv4 destination (ip & port).
    	 * @param buffer Message to be sent.
    	 * @param buffer_size Size of the message.
    	 * @return Returns `true` on success, `false` otherwise.
    	 * @warning It's not possible to send UDP packets with a size greater than `1500` bytes (MTU limit).
    	 * @changelog 1.0.0 17.02.2022 initial version
    	 */
    	bool napc_UDP_send(
    		napc__UDPSocket udp_socket,
    		napc__IPv4Participant destination,
    		const void *buffer, napc_size buffer_size
    	);
    
    	/*!
    	 * @name napc_UDP_sendSilent
    	 * @brief Send an UDP-message.
    	 * @version 1.0.0
    	 * @description
    	 * Same as `napc_UDP_send()` but does not log anything.
    	 * Used to send log over the network to another device.
    	 * @param udp_socket The UDP socket to write the message to.
    	 * @param destination IPv4 destination (ip & port).
    	 * @param buffer Message to be sent.
    	 * @param buffer_size Size of the message.
    	 * @return Returns `true` on success, `false` otherwise.
    	 * @warning It's not possible to send UDP packets with a size greater than `1500` bytes (MTU limit).
    	 * @changelog 1.0.0 17.02.2022 initial version
    	 */
    	bool napc_UDP_sendSilent(
    		napc__UDPSocket udp_socket,
    		napc__IPv4Participant destination,
    		const void *buffer, napc_size buffer_size
    	);
    
    	/*!
    	 * @name napc_UDP_closeSocket
    	 * @brief Close an open UDP-socket.
    	 * @version 1.0.0
    	 * @description
    	 * Close an open UDP-socket.
    	 * @param udp_socket The UDP-socket to be closed.
    	 * @changelog 1.0.0 17.02.2022 initial version
    	 */
    	void napc_UDP_closeSocket(napc__UDPSocket udp_socket);
    
    	/*!
    	 * @name napc_UDP_getNumOpenSockets
    	 * @brief Get the number of open UDP sockets.
    	 * @version 1.0.0
    	 * @description
    	 * Gets the number of currently open UDP sockets.
    	 * @return Returns the number of open UDP sockets.
    	 * @changelog 1.0.0 17.02.2022 initial version
    	 */
    	napc_size napc_UDP_getNumOpenSockets(void);
    #endif

/* original: #include <hw.module/file/file.h> */
    #if !defined(NAPC_HW_MODULE_FILE_h)
    	#define NAPC_HW_MODULE_FILE_h
    

/* original: #include <libnapc.h> */
/* header file already included */
    
    	/*!
    	 * @name napc__File
    	 * @module File
    	 * @brief Representation of a file.
    	 * @version 1.0.0
    	 * @description
    	 * Representation of a file.
    	 * @opaque
    	 * @changelog 1.0.0 17.02.2022 initial version
    	 */
    	typedef napc_ssize napc__File;
    
    	/*!
    	 * @name napc_File_open
    	 * @brief Open a file.
    	 * @version 1.0.0
    	 * @description
    	 * Open a file for reading or writing.
    	 * @param path Path to the file.
    	 * @param mode Mode (`"r"` for reading, `"w"` for writing).
    	 * @return Returns a negative number if file could not be opened.
    	 * @notes
    	 * On linux the environment variable `NAPC_FILE_ROOT_PATH` is prepended to `path`.
    	 * @warning
    	 * Opening a file in write mode (`"w"`) will always clear the previous contents of the file.
    	 * @changelog 1.0.0 17.02.2022 initial version
    	 * @example
    	 * napc__File fd = napc_File_open("TEST.TXT", "r");
    	 * 
    	 * if (0 > fd) {
    	 *     NAPC_PANIC("Failed to open TEST.TXT!");
    	 * }
    	 */
    	napc__File napc_File_open(const char *path, const char *mode) NAPC_FN_WARNUNUSED_RET();
    
    	/*!
    	 * @name napc_File_write
    	 * @brief Write to a file.
    	 * @version 1.0.0
    	 * @description
    	 * Write data to an open file.
    	 * @param file File to write to.
    	 * @param data Buffer to write.
    	 * @param data_size Size of buffer.
    	 * @return Returns the number of bytes written or `-1` on error.
    	 * @changelog 1.0.0 17.02.2022 initial version
    	 */
    	napc_ssize napc_File_write(napc__File file, const void *data, napc_size data_size);
    
    	/*!
    	 * @name napc_File_read
    	 * @brief Read from a file.
    	 * @version 1.0.0
    	 * @description
    	 * Reads data from an open file.
    	 * @param file File to read from.
    	 * @param buffer Buffer to write data to.
    	 * @param buffer_size Size of buffer.
    	 * @return Returns the number of bytes read or `-1` on error.
    	 * @changelog 1.0.0 17.02.2022 initial version
    	 */
    	napc_ssize napc_File_read(napc__File file, void *buffer, napc_size buffer_size);
    
    	/*!
    	 * @name napc_File_getSize
    	 * @brief Get size of file.
    	 * @version 1.0.0
    	 * @description
    	 * Get the size of an open file.
    	 * @param file File to be measured.
    	 * @return Returns the file size in bytes.
    	 * @changelog 1.0.0 17.02.2022 initial version
    	 */
    	napc_size napc_File_getSize(napc__File file);
    
    	/*!
    	 * @name napc_File_close
    	 * @brief Close open file.
    	 * @version 1.0.0
    	 * @description
    	 * Close an open file.
    	 * @param file File to be closed.
    	 * @changelog 1.0.0 17.02.2022 initial version
    	 */
    	void napc_File_close(napc__File file);
    #endif

/* original: #include <hw.module/fs/fs.h> */
    /*!
     * @name fs:intro
     * @brief Write & read files
     */
    #if !defined(NAPC_HW_MODULE_FS_h)
    	#define NAPC_HW_MODULE_FS_h
    

/* original: #include <libnapc.h> */
/* header file already included */
    

/* original: #include <module/buffer/buffer.h> */
/* header file already included */
    
    	/*!
    	 * @name napc_fs_writeFile
    	 * @brief Write data to a file.
    	 * @version 1.0.0
    	 * @description
    	 * Writes data to a file overwriting its previous contents.
    	 * @param path File path.
    	 * @param buffer Buffer to write.
    	 * @param buffer_size Size of buffer.
    	 * @return Returns `true` on success, `false` otherwise.
    	 * @notes
    	 * On linux the environment variable `NAPC_FILE_ROOT_PATH` is prepended to `path`.
    	 * @warning This function will always overwrite the previous contents of the file.
    	 * @changelog 1.0.0 17.02.2022 initial version
    	 */
    	bool napc_fs_writeFile(
    		const char *path, const void *buffer, napc_size buffer_size
    	) NAPC_FN_WARNUNUSED_RET();
    
    	/*!
    	 * @name napc_fs_writeFileCString
    	 * @brief Write a string to a file.
    	 * @version 1.0.0
    	 * @description
    	 * Writes a string to a file overwriting its previous contents.
    	 * @param path File path.
    	 * @param string String to write to file.
    	 * @return Returns `true` on success, `false` otherwise.
    	 * @notes
    	 * On linux the environment variable `NAPC_FILE_ROOT_PATH` is prepended to `path`.
    	 * @warning This function will always overwrite the previous contents of the file.
    	 * @changelog 1.0.0 17.02.2022 initial version
    	 */
    	bool napc_fs_writeFileCString(
    		const char *path, const char *string
    	) NAPC_FN_WARNUNUSED_RET();
    
    	/*!
    	 * @name napc_fs_readFile
    	 * @brief Read a file in its entirety.
    	 * @version 1.0.0
    	 * @description
    	 * Reads the entire content of a file into a buffer.
    	 * @param path File path.
    	 * @param buffer Buffer to write to.
    	 * @return Returns `true` on success, `false` otherwise.
    	 * @notes
    	 * On linux the environment variable `NAPC_FILE_ROOT_PATH` is prepended to `path`.
    	 * @changelog 1.0.0 17.02.2022 initial version
    	 */
    	bool napc_fs_readFile(
    		const char *path, napc__Buffer *buffer
    	) NAPC_FN_WARNUNUSED_RET();
    
    	/*!
    	 * @name napc_fs_readFileCString
    	 * @brief Read a file in its entirety.
    	 * @version 1.0.0
    	 * @description
    	 * Reads the entire content of a file into a NUL-terminated string.
    	 * @param path File path.
    	 * @param buffer Buffer to write to.
    	 * @param buffer_size Size of buffer.
    	 * @return Returns `true` on success, `false` otherwise.
    	 * @notes
    	 * On linux the environment variable `NAPC_FILE_ROOT_PATH` is prepended to `path`.
    	 * @changelog 1.0.0 17.02.2022 initial version
    	 */
    	bool napc_fs_readFileCString(
    		const char *path, char *buffer, napc_size buffer_size
    	) NAPC_FN_WARNUNUSED_RET();
    #endif

/* original: #include <hw.module/env/env.h> */
    #if !defined(NAPC_HW_MODULE_ENV_h)
    	#define NAPC_HW_MODULE_ENV_h
    

/* original: #include <libnapc.h> */
/* header file already included */
    
    	/*!
    	 * @name napc_env_isFileSystemAvailable
    	 * @brief Check file system availability.
    	 * @version 1.1.0
    	 * @return Returns `true` if file system functionality is available.
    	 * @changelog 1.1.0 18.03.2022 initial version
    	 * @example
    	 * if (napc_env_isFileSystemAvailable()) {
    	 *     napc_printf("File System is available.\n");
    	 * }
    	 */
    	bool napc_env_isFileSystemAvailable(void) NAPC_FN_WARNUNUSED_RET();
    
    	/*!
    	 * @name napc_env_isEthernetAvailable
    	 * @brief Check ethernet availability.
    	 * @version 1.1.0
    	 * @return Returns `true` if ethernet functionality is available.
    	 * @changelog 1.1.0 18.03.2022 initial version
    	 * @example
    	 * if (napc_env_isEthernetAvailable()) {
    	 *     napc_printf("Ethernet is available.\n");
    	 * }
    	 */
    	bool napc_env_isEthernetAvailable(void) NAPC_FN_WARNUNUSED_RET();
    #endif


/* original: #include <module/app/app.h> */
    #if !defined(NAPC_MODULE_APP_h)
    	#define NAPC_MODULE_APP_h
    

/* original: #include <libnapc.h> */
/* header file already included */
    
    	extern void napc_app_setup(const char *platform);
    	extern bool napc_app_loop(napc_time uptime);
    #endif

	extern void napc_main(const char *platform);

	#if defined(__cplusplus)
		}
	#endif
#endif


#if !defined(NAPC_ALL_TESTS_FILE_h)
    #define NAPC_ALL_TESTS_FILE_h

    #if defined(__cplusplus)
        extern "C" {
    #endif
    void napc_aes__runTests(void);
    void napc_dns__runTests(void);
    void napc_eth__runTests(void);
    void napc_hmac__runTests(void);
    void napc_misc__runTests(void);
    void napc_parser__runTests(void);
    void napc_pool__runTests(void);
    void napc_reader__runTests(void);
    void napc_sha__runTests(void);
    void napc_writer__runTests(void);

    void napc_runAllTests(void);
    #if defined(__cplusplus)
        }
    #endif
#endif
