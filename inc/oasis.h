#ifndef __OASIS_H__
#define __OASIS_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef __OASIS_DEBUG__
#define OASIS_DEBUG(fmt, args...) printf("[%s:%d] " fmt "\n",   \
                                   __FUNCTION__, __LINE__ , ## args)
#else
#define OASIS_DEBUG(fmt, args...)  do {} while(0)
#endif


#ifdef __OASIS_ERROR__
#define OASIS_ERROR(fmt, args...) \
    do{\
        printf("###########ERROR INFO:\n");\
        printf("[%s:%s:%d] " fmt "\n",   \
               __FILE__, __FUNCTION__, __LINE__ , ## args);\
    }while(0)
#else
#define OASIS_ERROR(fmt, args...)  do {} while(0)
#endif

/*
 * information of enter function
 */
#ifdef __OASIS_DEBUG__
#define OASIS_ENTER(x)   printf("Enter: %s, %s line %i\n",x,__FILE__,__LINE__)
#define OASIS_LEAVE(x)   printf("Leave: %s, %s line %i\n",x,__FILE__,__LINE__)

#else
#define OASIS_ENTER(x)   do {} while (0)
#define OASIS_LEAVE(x)   do {} while (0)

#endif

#define STATIC      static

#define INLINE      inline

#ifndef LIKELY
#define LIKELY(x)    (x)
#endif
#ifndef UNLIKELY
#define UNLIKELY(x) (x)
#endif

#ifndef __used
#define __used          /* unimplemented */
#endif

#ifndef __maybe_unused
#define __maybe_unused      /* unimplemented */
#endif

#ifndef noinline
#define noinline
#endif


#ifndef MIN
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#endif

#ifndef MAX
#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#endif

#ifdef __cplusplus
}
#endif

#endif /* ifndef __OASIS_H__ */
