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

#ifndef __OASS_COMMON_H__
#define __OASS_COMMON_H__

#include <oss_types.h>

#ifdef __cplusplus
extern "C" {
#endif

#define __OSS_DEBUG__
#define __OSS_ERROR__


#ifdef __OSS_DEBUG__
#define OSS_DEBUG(fmt, args...) printf("[%s:%d] " fmt "\n",   \
		__FUNCTION__, __LINE__ , ## args)
#else
#define OSS_DEBUG(fmt, args...)  do {} while(0)
#endif


#ifdef __OSS_ERROR__
#define OSS_ERROR(fmt, args...) \
	do{\
		printf("###########ERROR INFO:\n");\
		printf("[%s:%s:%d] " fmt "\n",   \
				__FILE__, __FUNCTION__, __LINE__ , ## args);\
	}while(0)
#else
#define OSS_ERROR(fmt, args...)  do {} while(0)
#endif

#ifndef oss_sleep
#define oss_sleep(x)         /* unimplemented */
#endif /* ifndef oss_sleep */

#ifdef __OSS_DEBUG__
#define OSS_ASSERT(expr) \
	if(!(expr)) { \
		printf( "Assertion failed! %s,%s,%s,line=%d\n",\
#expr,__FILE__,__func__,__LINE__); \
		while(1)   \
			oss_sleep(50); \
	}
#else
#define OSS_ASSERT(expr)
#endif

/*
 * dump data
 */
#ifdef __OSS_DEBUG__
#define OSS_DUMP(pmt,addr,len) \
	do  \
	{ \
		oss_uint32 i = 1; \
		oss_uint8 *src_ = addr; \
		for (i = 1; i <= len; i++) \
		{       \
			printf("%s\n",pmt);   \
			printf("0x%x	", *src_++); \
			if(0 == i%16)       \
				printf("\n");   \
		}                   \
	} while (0)
#else
#define OSS_DUMP(pmt,addr, len)  do {} while(0)
#endif

#ifdef __OSS_DEBUG__
#define oss_enter(x)   printf("Enter: %s, %s line %i\n",x,__FILE__,__LINE__)
#define oss_leave(x)   printf("Leave: %s, %s line %i\n",x,__FILE__,__LINE__)
#else
#define oss_enter(x)   do {} while (0)
#define oss_leave(x)   do {} while (0)
#endif

#define oss_static      static

#define oss_inline      inline

#ifndef oss_likely
#define oss_likely(x)    (x)
#endif

#ifndef oss_unlikely
#define oss_unlikely(x) (x)
#endif

#ifndef __oss_unused
#define __oss_unused   __attribute__((unused))
#endif

#ifndef __oss_weak
#define __oss_weak   __attribute__((weak))
#endif

#ifndef __oss_aligned
#define __oss_aligned(x)   __attribute__((aligned(x)))
#endif

#ifndef __oss_packed
#define __oss_packed   __attribute__((packed))
#endif

#ifndef __maybe_unused
#define __maybe_unused      /* unimplemented */
#endif

#define OSSS_IS_ALIGNED(x, a)        (((x) & ((typeof(x))(a) - 1)) == 0)

#define OSS_ARRAY_SIZE(x) (sizeof(x)/sizeof(x[0]))

#ifdef __GNUC__
#define oss_typeof(x) (__typeof__(x))
#else
#define oss_typeof(x)
#endif

/*
 * Define ALIASNAME as a alias for NAME.
 */
#define oss_alias(name, aliasname) _oss_alias (name, aliasname)
#define _oss_alias(name, aliasname) \
	extern __typeof (name) aliasname __attribute__ ((alias (#name)));

void *oss_malloc(oss_uint32 length);

void oss_free(oss_uint8 **ptr);

/*
 * @Brief: allocate @length bytes,and return @align bytes align address
 *
 *
 * @Parameter[in]      length                = Need to allocate size
 *
 * @Parameter[in]      align                 = Need to align size
 *
 * @Return             @align align address  = Allocate success
 *
 * @Return             NULL                  = Allocate failed
 *
 */
void *oss_align_malloc(oss_uint32 length, oss_uint32 align);

/*
 * @Brief: free allocated buffer malloced by @oss_align_malloc
 *
 *
 * @Parameter[in]      **ptr                 = Need to free buffer address
 *
 * @Return             No return
 *
 */
void oss_align_free(oss_uint8 **ptr);


#ifdef __cplusplus
}
#endif

#endif
