/*
 * Copyright (c) 2017-2018 Roy Liao <royliao1026@gmail.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */

#ifndef __OASS_TYPES_H__
#define __OASS_TYPES_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif

#define OSS_USHORT_MAX  ((u16)(~0U))
#define OSS_SHORT_MAX   ((s16)(USHORT_MAX>>1))
#define OSS_SHORT_MIN   (-SHORT_MAX - 1)
#define OSS_INT_MAX     ((int)(~0U>>1))
#define OSS_INT_MIN     (-INT_MAX - 1)
#define OSS_UINT_MAX    (~0U)
#define OSS_LONG_MAX    ((long)(~0UL>>1))
#define OSS_LONG_MIN    (-LONG_MAX - 1)
#define OSS_ULONG_MAX   (~0UL)
#define OSS_LLONG_MAX   ((long long)(~0ULL>>1))
#define OSS_LLONG_MIN   (-LLONG_MAX - 1)
#define OSS_ULLONG_MAX  (~0ULL)

#ifndef oss_element
typedef int oss_element;
#endif

/* basic types */
typedef unsigned int oss_uint32;
typedef unsigned long oss_uint64;
typedef int oss_sint32;
typedef long oss_sint64;
typedef unsigned char oss_uint8;
typedef char oss_sint8;
typedef bool oss_bool;

#define OSS_NULL ((void*)0)

/* return value */
typedef enum _OSS_RTN_CODE {

	OSS_RTN_SUCCESS = 0,

	OSS_RTN_FAIL = 1,

	OSS_RTN_INVAILD_PARM = 2,

	OSS_RTN_UNDEFINE = -1

} OSS_RTN_CODE;


#ifdef __cplusplus
}
#endif

#endif /* __OASS_TYPES_H__ */
