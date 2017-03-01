#ifndef __RTC8563T_H__
#define __RTC8563T_H__
#include <linux/rtc.h>

#define INRTCDEV    "/dev/rtc0"
#define EXRTCDEV    "/dev/"

typedef void*           PVOID;
typedef float           float32;
typedef signed char     INT8;
typedef signed char *   PINT8;
typedef unsigned char   UINT8;
typedef unsigned char * PUINT8;
typedef signed short    INT16;
typedef signed short *  PINT16;
typedef unsigned short  UINT16;
typedef unsigned short* PUINT16;
typedef signed int      INT32;
typedef signed int *    PINT32;
typedef unsigned int    UINT32;
typedef unsigned int *  PUINT32;

typedef struct rtc_time RTC_TIME;


#endif
