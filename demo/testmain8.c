#include <stdio.h>

#include "bx_dual_sdk.h"
#include "bx_sdk_dual.h"


int testDynamic5G();
int testDynamic6G();
char g_IP[16]={'\0'};

int main(int argc, char *arg[])
{
	int* p;
	printf("this is sizeof(p)=%d;\n",sizeof(p));
	printf("argc=%d;",argc);
	printf("arg[0]=%s;\n", arg[0]);
	
	if( argc > 1 )
	{
		printf("arg[1]=%s;\n", arg[1]);
		sprintf( g_IP, "%s", arg[1] );
	}


	testDynamic6G();
	
	return 0;
}

int testDynamic6G()
{
	Ouint8* pIP = (Ouint8*)g_IP;//"192.168.0.181";
	Ouint32 nPort = 5005;
	E_ScreenColor_G56 color = eSCREEN_COLOR_DOUBLE;

	//先删除所有动态区
	bxDual_dynamicArea_DelArea_5G(pIP, nPort, 0xff);


	Ouint8 nAreaID = 0;
	//从6代的节目测试用例拷贝过来的：
	{
		EQareaHeader_G6 aHeader1;
		aHeader1.AreaType = 0x00;
		aHeader1.AreaX = 0;// 16;
		aHeader1.AreaY = 0;
		aHeader1.AreaWidth = 64;
		aHeader1.AreaHeight = 32;
		aHeader1.BackGroundFlag = 0x00;
		aHeader1.Transparency = 101;
		aHeader1.AreaEqual = 0x00;
		//aHeader1.SoundFlag = 0x00;


		//在已添加的区域中添加文本
		//	Ouint8 str[] = "led";
		Ouint8 str[] = "汉字测试123456789";
		EQpageHeader_G6 pheader1;
		pheader1.PageStyle = 0x00;
		pheader1.DisplayMode = 0x04;
		pheader1.ClearMode = 0x01;
		pheader1.Speed = 10;
		pheader1.StayTime = 500;
		pheader1.RepeatTime = 1;
		pheader1.ValidLen = 128;
		pheader1.CartoonFrameRate = 0x00;
		pheader1.BackNotValidFlag = 0x00;
		pheader1.arrMode = eMULTILINE;//eSINGLELINE;//
		pheader1.fontSize = 12;
		pheader1.color = 0xff00ff;
		pheader1.fontBold = false;
		pheader1.fontItalic = false;
		pheader1.tdirection = pNORMAL;
		pheader1.txtSpace = 0;
		pheader1.Valign = 2;
		pheader1.Halign = 3;

		dynamicArea_AddAreaTxtDetails_6G(pIP, 5005, eSCREEN_COLOR_DOUBLE, nAreaID, &aHeader1, &pheader1, (Ouint8*)"./allfonts/1.ttf", (Ouint8*)str);
	}

}
		
int testDynamic5G()
{
Ouint8* pIP = (Ouint8*)g_IP;//"192.168.0.181";
		Ouint32 nPort = 5005;
		E_ScreenColor_G56 color = eSCREEN_COLOR_DOUBLE;

		//先删除所有动态区
		bxDual_dynamicArea_DelArea_5G(pIP, nPort, 0xff);


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



		bxDual_dynamicArea_DelArea_5G(pIP, nPort, uAreaId);



		DisplayMode = 0x02;
		uAreaX = 16;
		uAreaY = 16;
		uWidth = 64;
		uHeight = 16;
		oFont.arrMode = eSINGLELINE; oFont.fontSize = 10;
		fontName = (Ouint8*)"./allfonts/1.ttf";
		strAreaTxtContent = (Ouint8*)"5代动态区2中华人民共和国70周年纪念，一起迎接这一伟大时刻的到来！";

		bxDual_dynamicArea_AddAreaWithTxt_5G(pIP, nPort, color,
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

