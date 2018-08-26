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

#include <oss_common.h>

void *oss_malloc(oss_uint32 length)
{
	OSS_ASSERT(0 != length);
	return malloc(length);
}

void oss_free(oss_uint8 **ptr)
{
	OSS_ASSERT((OSS_NULL != ptr) && (OSS_NULL != *ptr));
	free(*ptr);
	*ptr = OSS_NULL;
}

void *oss_align_malloc(oss_uint32 length, oss_uint32 align)
{
	return malloc(length);
}

void oss_align_free(oss_uint8 **ptr)
{
	free(*ptr);
}
