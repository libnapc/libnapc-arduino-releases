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
 * @name HRTimer:intro
 * @brief High-resolution timer
 */
#if !defined(NAPC_MODULE_HRTIMER_h)
	#define NAPC_MODULE_HRTIMER_h

	#include <libnapc.h>
	#include <napc-magic/napc-magic.h>

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
