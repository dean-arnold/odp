/* Copyright (c) 2020, Arm Limited
 * All rights reserved.
 *
 * SPDX-License-Identifier:     BSD-3-Clause
 */

#ifndef ODP_ARCH_CPU_RDTSC_H_
#define ODP_ARCH_CPU_RDTSC_H_

#include <stdint.h>

static inline uint64_t _odp_cpu_rdtsc(void)
{
	uint64_t cntvct;

	/*
	 * To be consistent with other architectures, do not issue a
	 * serializing instruction, e.g. ISB, before reading this
	 * sys reg.
	 */

	/* Memory clobber to minimize optimization around load from sys reg. */
	__asm__ volatile("mrs %0, cntvct_el0" : "=r"(cntvct) : : "memory");

	return cntvct;
}

#endif
