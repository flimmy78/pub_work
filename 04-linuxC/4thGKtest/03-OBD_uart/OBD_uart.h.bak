#ifndef __OBD_UART__
#define __OBD_UART__

#include <stdio.h>

#define OBD_UART_PROCOTOL_HEAD  0xBB    /*帧头*/
#define OBD_UART_PROCOTOL_TAIL  0xEE    /*帧尾*/
#define OBD_UART_PROCOTOL_ESC	0xAA	/*转义*/

#define OBD_UART_PROCOTOL_COMMAND_TIME  0x01    /*请求时间*/
#define OBD_UART_PROCOTOL_COMMAND_KEY   0x02    /*请求验证*/
#define OBD_UART_PROCOTOL_COMMAND_SET   0x10    /*参数设置*/
#define OBD_UART_PROCOTOL_COMMAND_MID	0x13	/*读取机器ID*/
#define OBD_UART_PROCOTOL_COMMAND_VIN	0x14	/*读取底盘ID*/
#define OBD_UART_PROCOTOL_COMMAND_PTY	0x15	/*读取OBD协议类型及油耗算法*/
#define	OBD_UART_PROCOTOL_COMMAND_NIV	0x16	/*清除【OBD模块】存储的车辆底盘号(VIN)*/
#define OBD_UART_PROCOTOL_COMMAND_INV	0x17	/*发送车辆底盘号(VIN)给【OBD模块】*/
#define OBD_UART_PROCOTOL_COMMAND_SEND	0x20	/*【OBD模块】向【主控】上传事件*/
#define OBD_UART_PROCOTOL_COMMAND_READ	0x30	/*【主控】读取行程内统计参数*/
#define OBD_UART_PROCOTOL_COMMAND_REAE	0x41	/*【主控】读取车辆运行参数*/

#define OBD_PROCOTOL_PID_AA         0x00    /*恢复出厂设置，以下全部参数恢复默认值*/
#define OBD_PROCOTOL_PID_AB         0x01    /*清除终端中存储的行程和事件数据*/
#define OBD_PROCOTOL_PID_AC         0x04    /*故障码扫描时间间隔（单位：S）*/
#define OBD_PROCOTOL_PID_AD         0x05    /*ACC关闭后等多长时间进入睡眠（单位：S）*/
#define OBD_PROCOTOL_PID_AE         0x10    /*重新进行安装位置校准*/
#define OBD_PROCOTOL_PID_AF         0x11    /*开始在线升级*/
#define OBD_PROCOTOL_PID_AG         0x20    /*油耗修正值，单位为1000分之1*/
#define OBD_PROCOTOL_PID_AH         0x21    /*里程修正值，单位为1000分之1*/
#define OBD_PROCOTOL_PID_AI         0x22    /*实际排量m*/
#define OBD_PROCOTOL_PID_AJ         0x30    /*设置震动唤醒阈值0x03~0x7F阈值越大，终端对震动越不敏感*/
#define OBD_PROCOTOL_PID_AK         0x31    /*急加油阈值调整，公式为:初始阈值X调整值/100*/
#define OBD_PROCOTOL_PID_AL         0x32    /*急刹车阈值调整，公式为:初始阈值X调整值/100*/
#define OBD_PROCOTOL_PID_AM         0x33    /*快速变道阈值调整，公式为:初始阈值X调整值/100*/
#define OBD_PROCOTOL_PID_AN         0x34    /*频繁变道阈值调整，公式为:初始阈值X调整值/100*/
#define OBD_PROCOTOL_PID_AO         0x35    /*前碰撞阈值调整，公式为:初始阈值X调整值/100*/
#define OBD_PROCOTOL_PID_AP         0x36    /*后碰撞阈值调整，公式为:初始阈值X调整值/100*/
#define OBD_PROCOTOL_PID_AQ         0x37    /*左右碰撞阈值调整，公式为:初始阈值X调整值/100*/
#define OBD_PROCOTOL_PID_AR         0x40    /*发动机转速过高报警阈值，高于阈值报警*/
#define OBD_PROCOTOL_PID_AS         0x41    /*水温过高报警阈值，高于阈值报警*/
#define OBD_PROCOTOL_PID_AT         0x42    /*水温过低报警阈值，低于阈值报警*/
#define OBD_PROCOTOL_PID_AW         0x43    /*水温恢复提示阈值，高于阈值提示水温恢复*/
#define OBD_PROCOTOL_PID_AX         0x44    /*车速过高报警阈值，高于阈值报警*/
#define OBD_PROCOTOL_PID_AY         0x45    /*电瓶电压过高报警阈值（乘以10后传输）*/
#define OBD_PROCOTOL_PID_AZ         0x46    /*电瓶电压过低报警阈值（乘以10后传输）*/


#endif
