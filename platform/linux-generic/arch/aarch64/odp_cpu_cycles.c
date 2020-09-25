/* Copyright (c) 2020, Arm Limited
 * All rights reserved.
 *
 * SPDX-License-Identifier:     BSD-3-Clause
 */

#include <stdint.h>

#include <odp/api/cpu.h>
#include <odp_init_internal.h>
#include <odp/api/abi/cpu_rdtsc.h>

uint64_t odp_cpu_cycles(void)
{
	return _odp_cpu_rdtsc();
}

uint64_t odp_cpu_cycles_max(void)
{
	return UINT64_MAX;
}

uint64_t odp_cpu_cycles_resolution(void)
{
	return 1;
}

int _odp_cpu_cycles_init_global(void)
{
	return 0;
}
