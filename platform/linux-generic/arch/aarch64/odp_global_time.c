/* Copyright (c) 2015-2018, Linaro Limited
 * All rights reserved.
 *
 * SPDX-License-Identifier:     BSD-3-Clause
 */

#include <odp_posix_extensions.h>

#include <time.h>

#include <odp_debug_internal.h>
#include <odp/api/abi/cpu_time.h>
#include <odp/api/abi/cpu_rdtsc.h>

#include <odp/visibility_begin.h>

uint64_t _odp_cpu_global_time(void)
{
	return _odp_cpu_rdtsc();
}

#include <odp/visibility_end.h>

int _odp_cpu_has_global_time(void)
{
	uint64_t hz = _odp_cpu_global_time_freq();

	/*
	 * The system counter portion of the architected timer must
	 * provide a uniform view of system time to all processing
	 * elements in the system. This should hold true even for
	 * heterogeneous SoCs.
	 *
	 * Determine whether the system has 'global time' by checking
	 * whether a read of the architected timer frequency sys reg
	 * returns a sane value. Sane is considered to be within
	 * 1MHz and 6GHz (1us and .1667ns period).
	 */
	return hz >= 1000000 && hz <= 6000000000;
}

uint64_t _odp_cpu_global_time_freq(void)
{
	uint64_t cntfrq;

	__asm__ volatile("mrs %0, cntfrq_el0" : "=r"(cntfrq) : : );

	return cntfrq;
}
