#ifndef __OBD_UART__
#define __OBD_UART__

#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>

/*============================================================================================*/
/*---参照《obd终端与后视镜通讯协议》--V3.32（更新至2015.04.17）---*/

/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
#define OBD_PROCOTOL_HEAD  0xBB    /*帧头*/
#define OBD_PROCOTOL_TAIL  0xEE    /*帧尾*/
#define OBD_PROCOTOL_ESC	0xAA	/*转义,帧中：AA 0A代表AA；AA 0B代表BB；AA 0E代表EE*/

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
#define OBD_PROCOTOL_COMMAND_TIME  	0x01    /*【OBD模块】向【主控】申请实时时间*/
#define OBD_PROCOTOL_COMMAND_KEY   	0x02    /*【OBD模块】通过【主控】向【服务器】申请身份验证*/
#define OBD_PROCOTOL_COMMAND_UPD	0x07	/*手机APP对终端进行在线升级*/
#define OBD_PROCOTOL_COMMAND_SET   	0x10    /*【主控】设置【OBD模块】工作参数*/
#define OBD_PROCOTOL_COMMAND_ROOT	0x11	/*【主控】向【obd终端】申请高级控制权*/

#define OBD_PROCOTOL_COMMAND_MID	0x13	/*读取12字节MCU ID(机器ID)*/
#define OBD_PROCOTOL_COMMAND_VIN	0x14	/*读取车辆底盘号(VIN)*/
#define OBD_PROCOTOL_COMMAND_PTY	0x15	/*读取OBD协议类型及油耗算法*/
#define	OBD_PROCOTOL_COMMAND_NIV	0x16	/*清除【OBD模块】存储的车辆底盘号(VIN)*/
#define OBD_PROCOTOL_COMMAND_INV	0x17	/*发送车辆底盘号(VIN)给【OBD模块】*/
#define OBD_PROCOTOL_COMMAND_VER	0x18	/*读取【终端】版本号*/

#define OBD_PROCOTOL_COMMAND_SEND	0x20	/*【OBD模块】向【主控】上传事件*/
#define OBD_PROCOTOL_COMMAND_CONT	0x21	/*【主控】通过终端控制车辆*/
#define OBD_PROCOTOL_COMMAND_READ	0x30	/*【主控】读取行程内统计参数*/
#define OBD_PROCOTOL_COMMAND_REAE	0x41	/*【主控】读取车辆运行参数*/
#define OBD_PROCOTOL_COMMAND_REAF	0x42	/*【主控】启动【OBD终端】自动上传车辆运行参数*/
#define OBD_PROCOTOL_COMMAND_FAED	0x43	/*【主控】终止【OBD模块】自动上传车辆运行参数*/
#define OBD_PROCOTOL_COMMAND_RERR	0x50	/*【主控】读取车辆故障码*/

/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
#define OBD_PROCOTOL_VIN_STATUS_KNIL	0X00		/*00:OBD未链接；*/
#define OBD_PROCOTOL_VIN_STATUS_DAER	0X01		/* 01：读不到VIN; */
#define OBD_PROCOTOL_VIN_STATUS_READ	0X03		/*02:读到VIN; */
#define OBD_PROCOTOL_VIN_STATUS_SAVE	0X03		/*03:模块存储的VIN*/

#define OBD_PROCOTOL_RED_ERRCODE	0x00	/*读码（车辆故障码）*/
#define OBD_PROCOTOL_CLR_ERRCODE	0x01	/*清码（车辆故障码）*/

#define OBD_PROCOTOL_ERRTYPE_ENGINE 	0x00	/*0X00：发动机;*/
#define OBD_PROCOTOL_ERRTYPE_GEARBOX	0x01	/*0x01:变速箱;*/
#define OBD_PROCOTOL_ERRTYPE_BRAKE		0x02	/*0x02：刹车;*/
#define OBD_PROCOTOL_ERRTYPE_GASBAG		0x03	/*0x03：气囊;*/
#define OBD_PROCOTOL_ERRTYPE_ISTS		0x04	/*0x04：仪表板;*/
#define OBD_PROCOTOL_ERRTYPE_ABCM		0x05	/*0x05：车身控制;*/
#define OBD_PROCOTOL_ERRTYPE_AIRC		0x06	/*0x06：空调;*/

#define OBD_PROCOTOL_PID_PA         0x00    /*恢复出厂设置，以下全部参数恢复默认值*/
#define OBD_PROCOTOL_PID_PB         0x01    /*清除终端中存储的行程和事件数据*/
#define OBD_PROCOTOL_PID_PC         0x04    /*故障码扫描时间间隔（单位：S）*/
#define OBD_PROCOTOL_PID_PD         0x05    /*ACC关闭后等多长时间进入睡眠（单位：S）*/
#define OBD_PROCOTOL_PID_PE         0x10    /*重新进行安装位置校准*/
#define OBD_PROCOTOL_PID_PF         0x11    /*开始在线升级*/
#define OBD_PROCOTOL_PID_PG         0x20    /*油耗修正值，单位为1000分之1*/
#define OBD_PROCOTOL_PID_PH         0x21    /*里程修正值，单位为1000分之1*/
#define OBD_PROCOTOL_PID_PI         0x22    /*实际排量m*/
#define OBD_PROCOTOL_PID_PJ         0x30    /*设置震动唤醒阈值0x03~0x7F阈值越大，终端对震动越不敏感*/
#define OBD_PROCOTOL_PID_PK         0x31    /*急加油阈值调整，公式为:初始阈值X调整值/100*/
#define OBD_PROCOTOL_PID_PL         0x32    /*急刹车阈值调整，公式为:初始阈值X调整值/100*/
#define OBD_PROCOTOL_PID_PM         0x33    /*快速变道阈值调整，公式为:初始阈值X调整值/100*/
#define OBD_PROCOTOL_PID_PN         0x34    /*频繁变道阈值调整，公式为:初始阈值X调整值/100*/
#define OBD_PROCOTOL_PID_PO         0x35    /*前碰撞阈值调整，公式为:初始阈值X调整值/100*/
#define OBD_PROCOTOL_PID_PP         0x36    /*后碰撞阈值调整，公式为:初始阈值X调整值/100*/
#define OBD_PROCOTOL_PID_PQ         0x37    /*左右碰撞阈值调整，公式为:初始阈值X调整值/100*/
#define OBD_PROCOTOL_PID_PR         0x40    /*发动机转速过高报警阈值，高于阈值报警*/
#define OBD_PROCOTOL_PID_PS         0x41    /*水温过高报警阈值，高于阈值报警*/
#define OBD_PROCOTOL_PID_PT         0x42    /*水温过低报警阈值，低于阈值报警*/
#define OBD_PROCOTOL_PID_PW         0x43    /*水温恢复提示阈值，高于阈值提示水温恢复*/
#define OBD_PROCOTOL_PID_PX         0x44    /*车速过高报警阈值，高于阈值报警*/
#define OBD_PROCOTOL_PID_PY         0x45    /*电瓶电压过高报警阈值（乘以10后传输）*/
#define OBD_PROCOTOL_PID_PZ         0x46    /*电瓶电压过低报警阈值（乘以10后传输）*/

#define OBD_PROCOTOL_TID_TA			0x01	/*行程开始*/
#define OBD_PROTOCOL_TID_TB			0x02	/*行程结束*/
#define OBD_PROCOTOL_TID_TC			0x03	/*水平校准进行中*/
#define	OBD_PROCOTOL_TID_TD			0x04	/*水平校准完成*/
#define OBD_PROCOTOL_TID_TE			0x05	/*方向校准进行中*/
#define OBD_PROCOTOL_TID_TF			0x06	/*方向校准完成*/	
#define OBD_PROCOTOL_TID_TG         0x07	/*安装位置移动*/
#define OBD_PROCOTOL_TID_TH         0x10	/*急刹车*/
#define OBD_PROCOTOL_TID_TI         0x11	/*急加油*/
#define OBD_PROTOCOL_TID_TJ         0x12	/*快速变道*/
#define OBD_PROCOTOL_TID_TK         0x13	/*弯道加速*/
#define	OBD_PROCOTOL_TID_TL         0x14	/*`碰撞*/
#define OBD_PROCOTOL_TID_TM         0x15	/*频繁变道*/
#define OBD_PROCOTOL_TID_TN         0x16	/*乱路高速行驶*/
#define OBD_PROCOTOL_TID_TO         0x17	/*急转弯*/
#define OBD_PROCOTOL_TID_TP         0x18	/*翻车*/
#define OBD_PROCOTOL_TID_TQ         0x19	/*异常震动*/
#define OBD_PROTOCOL_TID_TR         0x20	/*车门异常状态提醒*/
#define OBD_PROCOTOL_TID_TS         0x21	/*胎压和手刹异常状态提醒*/
#define	OBD_PROCOTOL_TID_TT         0x30	/*超速报警*/
#define OBD_PROCOTOL_TID_TU         0x31	/*水温报警*/
#define OBD_PROCOTOL_TID_TV         0x32	/*转速报警*/
#define OBD_PROCOTOL_TID_TW         0x33	/*电平电压报警*/
#define OBD_PROCOTOL_TID_TX         0x34	/*故障报警*/

		/*--------标示要执行的动作编号--------*/
#define OBD_PROCOTOL_CID_CA			0X0001	/*1：启动发动机*/
#define OBD_PROCOTOL_CID_CB			0x0002	/*2：车门锁*/
#define OBD_PROCOTOL_CID_CC			0x0004	/*4：尾箱锁*/
#define OBD_PROCOTOL_CID_CD			0x0008	/*8：前右车窗*/
#define OBD_PROCOTOL_CID_CE			0x0010	/*16：前左车窗*/
#define OBD_PROCOTOL_CID_CF			0x0020	/*32：后右车窗*/
#define OBD_PROCOTOL_CID_CG			0x0040	/*64：后左车窗*/
#define OBD_PROCOTOL_CID_CH			0x0080	/*128：双闪灯*/
#define OBD_PROCOTOL_CID_CI			0x0100	/*256：鸣笛*/
/*============================================================================================*/

typedef struct _FDS
{
    int FD_0;   /*串口设备文件描述符*/
    int FD_1;   /*SD卡文件描述符*/
    int FD_2;
}FDS,* P_FDS;


int GK_SetPthreadStackSize(pthread_attr_t* attr, int stacksize);
void* Uart_ReadPthread(void* arg);  /*读线程执行函数*/
void* Uart_WritePthread(void* arg); /*写线程执行函数*/
int Uart_StartService(void);        /*串口服务函数*/


#endif
