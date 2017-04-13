/*******************************************************************
 *   > File Name: dbg.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: Thu 13 Apr 2017 09:52:07 AM CST
 ******************************************************************/
/*printf*/
#include <stdio.h> 
#ifdef MYDEBUG 
#define DEBUG(arg...) {\
    printf("[debug]:%s:%s:%d ---->",__FILE__,__FUNCTION__,__LINE__);\
    printf(arg);fflush(stdout);} 
#else 
#define DEBUG(arg...) {} 
#endif 

#if (0)
调用实例： 
DEBUG("my debug......\n"); 
DEBUG("the a is %d\n",a); 
#endif

/*printf*/
#ifdef DEBUG 
#define D_STR(_STR_) printf("f:%s(l:%d)%s\n",__FILE__,__LINE__,_STR_); 
#define D_LINE printf("f:%s(l:%d)-fn:%s\n",__FILE__,__LINE__,__FUNCTION__); 
#define D_CHAR(_CHAR_) printf("f:%s(l:%d)%d\n",__FILE__,__LINE__,_CHAR_); 
#define D_HEX(_HEX_) printf("f:%s(l:%d)[%x]\n",__FILE__,__LINE__,_HEX_); 
#else 
#define D_STR(_STR_) ; 
#define D_LINE ; 
#define D_CHAR(_CHAR_) ; 
#define D_HEX(_HEX_) ; 
#endif 

/*vfprintf*/
static void fprint_message_to_stdout(const char *format, va_list arg_ptr) 
{ 
    (void) vfprintf(stdout, format, arg_ptr); 
}
