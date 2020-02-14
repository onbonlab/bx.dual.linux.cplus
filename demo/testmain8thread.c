#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#include <pthread.h>

#include "bx_sdk_dual.h"


int testDynamic5G();
int testDynamic6G();

void *thread_function(void *arg);

char g_sMessage[] = "Hello World";


int main(int argc, char *arg[])
{
	int* p;
	printf("this is sizeof(p)=%d;\n",sizeof(p));


	int nResult = 0;
	pthread_t oThread;
	void *pThread_result = NULL;

	//Create Thread
	nResult = pthread_create(&oThread, NULL, thread_function,(void*)g_sMessage);
	
	if( nResult != 0 )
	{
		perror("Thread cration failed!");
		exit(EXIT_FAILURE);
	}
	
		
	printf("Waiting for thread to finish...\n");
	nResult = pthread_join(oThread,&pThread_result);
	if( nResult != 0 )
	{
		perror("pthread_join failed!");
		exit(EXIT_FAILURE);
	}
	printf("finished pthread_join, it returned %s\n", (char*)pThread_result );


	

	testDynamic5G();

	
	return 0;


}

void *thread_function(void *arg)
{
	printf("thread_function is running. Argument was %s\n", (char*)arg );
	
	int i = 0; 
	while( i++ < 10 )
	{
		sleep(3);
		testDynamic5G();
	}
	
	char sMessRet[] = "Thank you for the cpu time.";
	pthread_exit(sMessRet);
}


int testDynamic6G()
{
Ouint8* pIP = (Ouint8*)"192.168.0.181";
		Ouint32 nPort = 5005;
		E_ScreenColor_G56 color = eSCREEN_COLOR_DOUBLE;

		//先删除所有动态区
		dynamicArea_DelArea_5G(pIP, nPort, 0xff);


		Ouint8 uAreaId = 0;
		Ouint8 RunMode = 0x00;
		/*0x00 动态区运行模式
		0― 动态区数据循环显示。
			1― 动态区数据显示完成后静止显示最后一页数据。
			2― 动态区数据循环显示，超过设定时间后数据仍未更新时不再显示
			3― 动态区数据循环显示，超过设定时间后数据仍未更新时显示Logo 信息, Logo 信息即为动态区域的最后一页信息
			4― 动态区数据顺序显示，显示完最后一页后就不再显示
		*/
		Ouint16 Timeout = 3;		//Timeout 2 动态区数据超时时间，单位为秒
		Ouint8 RelateAllPro = 0;	//RelateAllPro 1 当该字节为 1 时，所有异步节目播放时都允许播放该动态区域；为 0 时，由接下来的规则来决定
		Ouint16 RelateProNum = 0;	//动态区域关联了多少个异步节目一旦关联了某个异步节目，则当该异步节目播放时允许播放该动态区域，否则，不允许播放该动态区域；以下的节目编号个数根据 RelateProNum 的值来确定，当该值为 0 时不发送；
		Ouint16* RelateProSerial = NULL;
		Ouint8 ImmePlay = 1;		//1 是否立即播放该字节为 0 时，该动态区域与异步节目一起播放；该字节为 1 时，异步节目停止播放，仅播放该动态区域该字节; 为 2 时，暂存该动态区域，当播放完节目编号最高的异步节目后播放该动态区域注意：当该字节为 0 时，RelateAllPro 到RelateProSerialN-1 的参数才有效，否则无效当该参数为 1 或 2 时，由于不与异步节目同时播放，为控制该动态区域能及时结束，可选择RunMode 参数为 2 或 4，当然也
		Ouint16 uAreaX = 16;
		Ouint16 uAreaY = 2;
		Ouint16 uWidth = 64;
		Ouint16 uHeight = 30;
		EQareaframeHeader oFrame; oFrame.AreaFFlag = 0;
		//PageStyle begin-------------------------------------------------------------------------------------------------------------------------------------------
		Ouint8 DisplayMode = 3;		//显示方式:  0x00 :随机显示 0x01 :静止显示 0x02 :快速打出 0x03 :向左移动 0x04 :向左连移 0x05 :向上移动 0x06 :向上连移 0x07 :闪烁 ......
		Ouint8 ClearMode = 0;		//退出方式/清屏方式: 每一页的退出方式；
		Ouint8 Speed = 32;			//速度等级
		Ouint16 StayTime = 200;		//停留时间，单位为 10ms
		Ouint8 RepeatTime = 3;
		//PageStyle End.

		//显示内容和字体格式 begin----------------------------------------------
		EQfontData oFont;
		oFont.arrMode = eMULTILINE;
		oFont.fontSize = 10;
		oFont.color = eRED;
		oFont.fontBold = false;
		oFont.fontItalic = false; oFont.tdirection = pNORMAL; oFont.txtSpace = 0; oFont.Halign = 1; oFont.Valign = 2;
		Ouint8* fontName = (Ouint8*)"宋体";
		Ouint8* strAreaTxtContent = (Ouint8*)"5E1动态-图文-文本测试。";// "5代动态区1开始测试，一起来看看吧...会有新发现的。";


															  
		//测试单区域多信息（文本/图片）接口
		DynamicAreaPicInfo_5G oPicInfo;
		oPicInfo.nType = 2;
		oPicInfo.DisplayMode = DisplayMode;
		oPicInfo.ClearMode = ClearMode;
		oPicInfo.Speed = Speed;
		oPicInfo.StayTime = StayTime;
		oPicInfo.RepeatTime = RepeatTime;
		oPicInfo.filePath = (Ouint8*)"K:/onbon/图片测试文件/3232黄.png";


		dynamicArea_DelArea_5G(pIP, nPort, uAreaId);

		uAreaX = 16;
		uAreaY = 0;
		uWidth = 64;
		uHeight = 32;
		dynamicArea_AddAreaWithPic_5G(pIP, nPort, color,
			uAreaId,
			RunMode,
			Timeout,
			RelateAllPro,
			RelateProNum,
			RelateProSerial,
			ImmePlay,
			uAreaX, uAreaY, uWidth, uHeight,
			oFrame,
			//PageStyle begin--------
			DisplayMode,
			ClearMode,
			Speed,
			StayTime,
			RepeatTime,
			//PageStyle End.

			//显示的图片文件所在目录和名称 begin---------
			(Ouint8*)"K:/onbon/图片测试文件/3232c.png"
			//end.
		);
}
		
int testDynamic5G()
{
Ouint8* pIP = (Ouint8*)"192.168.0.182";
		Ouint32 nPort = 5005;
		E_ScreenColor_G56 color = eSCREEN_COLOR_DOUBLE;

		//先删除所有动态区
		dynamicArea_DelArea_5G(pIP, nPort, 0xff);


		Ouint8 uAreaId = 0;
		Ouint8 RunMode = 0x00;
		/*0x00 动态区运行模式
		0― 动态区数据循环显示。
			1― 动态区数据显示完成后静止显示最后一页数据。
			2― 动态区数据循环显示，超过设定时间后数据仍未更新时不再显示
			3― 动态区数据循环显示，超过设定时间后数据仍未更新时显示Logo 信息, Logo 信息即为动态区域的最后一页信息
			4― 动态区数据顺序显示，显示完最后一页后就不再显示
		*/
		Ouint16 Timeout = 3;		//Timeout 2 动态区数据超时时间，单位为秒
		Ouint8 RelateAllPro = 0;	//RelateAllPro 1 当该字节为 1 时，所有异步节目播放时都允许播放该动态区域；为 0 时，由接下来的规则来决定
		Ouint16 RelateProNum = 0;	//动态区域关联了多少个异步节目一旦关联了某个异步节目，则当该异步节目播放时允许播放该动态区域，否则，不允许播放该动态区域；以下的节目编号个数根据 RelateProNum 的值来确定，当该值为 0 时不发送；
		Ouint16* RelateProSerial = NULL;
		Ouint8 ImmePlay = 1;		//1 是否立即播放该字节为 0 时，该动态区域与异步节目一起播放；该字节为 1 时，异步节目停止播放，仅播放该动态区域该字节; 为 2 时，暂存该动态区域，当播放完节目编号最高的异步节目后播放该动态区域注意：当该字节为 0 时，RelateAllPro 到RelateProSerialN-1 的参数才有效，否则无效当该参数为 1 或 2 时，由于不与异步节目同时播放，为控制该动态区域能及时结束，可选择RunMode 参数为 2 或 4，当然也
		Ouint16 uAreaX = 16;
		Ouint16 uAreaY = 2;
		Ouint16 uWidth = 64;
		Ouint16 uHeight = 30;
		EQareaframeHeader oFrame; oFrame.AreaFFlag = 0;
		//PageStyle begin-------------------------------------------------------------------------------------------------------------------------------------------
		Ouint8 DisplayMode = 3;		//显示方式:  0x00 :随机显示 0x01 :静止显示 0x02 :快速打出 0x03 :向左移动 0x04 :向左连移 0x05 :向上移动 0x06 :向上连移 0x07 :闪烁 ......
		Ouint8 ClearMode = 0;		//退出方式/清屏方式: 每一页的退出方式；
		Ouint8 Speed = 32;			//速度等级
		Ouint16 StayTime = 200;		//停留时间，单位为 10ms
		Ouint8 RepeatTime = 3;
		//PageStyle End.

		//显示内容和字体格式 begin----------------------------------------------
		EQfontData oFont;
		oFont.arrMode = eMULTILINE;
		oFont.fontSize = 10;
		oFont.color = eRED;
		oFont.fontBold = false;
		oFont.fontItalic = false; oFont.tdirection = pNORMAL; oFont.txtSpace = 0; oFont.Halign = 1; oFont.Valign = 2;
		Ouint8* fontName = (Ouint8*)"宋体";
		Ouint8* strAreaTxtContent = (Ouint8*)"5E1动态-图文-文本测试。";// "5代动态区1开始测试，一起来看看吧...会有新发现的。";



		dynamicArea_DelArea_5G(pIP, nPort, uAreaId);



		DisplayMode = 0x02;
		uAreaX = 16;
		uAreaY = 16;
		uWidth = 64;
		uHeight = 16;
		oFont.arrMode = eSINGLELINE; oFont.fontSize = 10;
		fontName = (Ouint8*)"./allfonts/1.ttf";
		strAreaTxtContent = (Ouint8*)"5代动态区2中华人民共和国70周年纪念，一起迎接这一伟大时刻的到来！";

		dynamicArea_AddAreaWithTxt_5G(pIP, nPort, color,
			uAreaId,
			RunMode,
			Timeout,
			RelateAllPro,
			RelateProNum,
			RelateProSerial,
			ImmePlay,
			uAreaX, uAreaY, uWidth, uHeight,
			oFrame,
			//PageStyle begin--------
			DisplayMode,
			ClearMode,
			Speed,
			StayTime,
			RepeatTime,
			//PageStyle End.

			//显示内容和字体格式 begin---------
			oFont,
			fontName,
			strAreaTxtContent
			//end.
		);
}