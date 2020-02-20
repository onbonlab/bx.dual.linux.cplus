#  BX-G5/G6 SDK 动态区接口调用说明C++

## 文档适用者

通过SDK向仰邦控制卡发送显示内容的软件开发者；

本文档主要描述5代控制卡和6代控制卡的动态区的SDK接口使用；



## 动态区接口的使用

### 6代卡动态区接口使用步骤

0.初始化SDK库：linux下不需要此步骤；windows平台需要；只需要初始化一次；

1.配置控制卡IP、端口、屏幕类型：单色、双色、三色

2.配置动态区参数：显示区的位置、大小、内容等

3.配置动态区内显示内容的属性：显示效果（移动速度等）、字体名称和大小等

4.调用发送动态区接口:[bxDual_dynamicArea_AddAreaTxtDetails_6G]()

5.释放SDK库：与初始化SDK库一一对应；linux下不需要；



代码实例：

```c++
/*0.初始化SDK库：linux平台不需要此步骤；windows平台需要；只需要初始化一次；*/
//int nInit = bxDual_InitSdk(); //返回0成功；-1失败；

/*1.配置控制卡IP、端口、屏幕类型：单色、双色、三色*/
	Ouint8* pIP = (Ouint8*)g_IP;//"192.168.0.181";
	Ouint32 nPort = 5005;
	E_ScreenColor_G56 color = eSCREEN_COLOR_DOUBLE;

/*2.配置动态区参数：显示区的位置、大小、内容等*/	
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
		
/*3.配置动态区内显示内容的特性：显示效果（移动速度等）、字体名称和大小等*/         
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

/*4.调用发送动态区接口；*/        
        Ouint8 nAreaID = 0;
        Ouint8 str[] = "汉字测试123456789";
		bxDual_dynamicArea_AddAreaTxtDetails_6G(pIP, 5005, eSCREEN_COLOR_DOUBLE, nAreaID, &aHeader1, &pheader1, (Ouint8*)"./allfonts/1.ttf", (Ouint8*)str);
	}
//"./allfonts/1.ttf"指定了字体文件;也可以直接使用字体名称:"宋体" 作为参数，但要求linux系统正确安装了宋体

/*5.释放SDK库：与初始化SDK库一一对应；linux下不需要*/
	//bxDual_ReleaseSdk();
```



### 动态区涉及的数据结构说明

##### 动态区参数/动态区域属性

```C++
typedef struct
{
Ouint8	AreaType;		//区域类型；动态区时，固定为0x10;
Ouint16	AreaX;			//区域左上角横坐标
Ouint16	AreaY;			//区域左上角纵坐标
Ouint16	AreaWidth;		//区域宽度
Ouint16	AreaHeight;		//区域高度
Ouint8  BackGroundFlag; //是否有背景
Ouint8  Transparency;   //透明度
Ouint8  AreaEqual;      //前景、背景区域大小是否相同

/*下面的这个语音结构体EQSound_6G仅在动态区时使用；图文分区播放语音请使用单独的结构体：EQPicAreaSoundHeader_G6;*/
//使用语音功能时：部分卡需要配置串口为语音模式！！！
//不使用语音时，不需要考虑这个结构
EQSound_6G stSoundData;

}BXareaHeader_G6,EQareaHeader_G6;
```

##### 动态区内显示内容的属性

```C++
typedef struct
{
Ouint8   PageStyle;			//数据页类型
Ouint8   DisplayMode;		//显示方式:0x00 –随机显示; 0x01–静止显示; 0x02–快速打出; 0x03–向左移动; 0x04 –向左连移； 0x05 –向上移动； 0x06 –向上连移；...0x25 –向右移动  0x26 –向右连移  0x27 –向下移动  0x28 –向下连移 其它参考6代卡动态区协议文档
Ouint8   ClearMode;			//退出方式/清屏方式
Ouint8   Speed;				//速度等级
Ouint16  StayTime;			//停留时间
Ouint8   RepeatTime;		//重复次数
Ouint16  ValidLen;			//此字段只在左移右移方式下有效
Ouint8   CartoonFrameRate;  //特技为动画方式时，该值代表其帧率
Ouint8   BackNotValidFlag;  //背景无效标志
//字体信息----------------------------------------------------------------------------
E_arrMode arrMode;			//排列方式--单行多行
Ouint16  fontSize;			//字体大小
Ouint32  color;				//字体颜色 E_Color_G56此通过此枚举值可以直接配置七彩色，如果大于枚举范围使用RGB888模式
Obool    fontBold;			//是否为粗体
Obool    fontItalic;		//是否为斜体
E_txtDirection tdirection;	//文字方向
Ouint16   txtSpace;			//文字间隔    
Ouint8 Halign; //横向对齐方式（0系统自适应、1左对齐、2居中、3右对齐）
Ouint8 Valign; //纵向对齐方式（0系统自适应、1上对齐、2居中、3下对齐）
//字体信息 结束
}BXpageHeader_G6,EQpageHeader_G6;
```



### 动态区的删除

删除指定动态区：

```c++
	/*配置控制卡IP及端口*/
	Ouint8* pIP = (Ouint8*)g_IP;//"192.168.0.181";
	Ouint32 nPort = 5005;		

	/*指定要删除的动态区ID*/
	const Oint8 cnst_nAreaCount = 4;
	Oint8 pAreaID[cnst_nAreaCount];
	pAreaID[0] = 0;
	pAreaID[1] = 1;
	pAreaID[2] = 2;
	pAreaID[3] = 3;
	/*调用删除动态区的接口*/
	bxDual_dynamicArea_DelAreas_6G(pIP, 5005, cnst_nAreaCount, pAreaID);
```

删除所有动态区：

```c++
	/*配置控制卡IP及端口*/
	Ouint8* pIP = (Ouint8*)g_IP;//"192.168.0.181";
	Ouint32 nPort = 5005;		

	/*动态区ID==0xff时，表示要删除所有动态区*/
	Oint8 nAllID = 0xff;

	/*调用删除动态区的接口*/
	/*与指定删除动态区的接口相比，此接口函数名称中是DelArea，而不是DelAreas*/
	bxDual_dynamicArea_DelArea_6G(pIP, 5005, cnst_nAreaCount, nAllID);
```



### 5代卡的动态区使用步骤

#### 5代卡动态区接口

1. 增加一条文本信息到指定的动态区

2. 增加一个图片到指定的动态区

3. 增加多条信息（文本/图片）到指定的动态区，并可以关联这个动态区到指定的节目

4. 删除动态区

   - 删除单个动态区

   - 删除多个动态区



#### 动态区调用步骤

以 增加一条文本信息到指定的动态区 为例：

##### 步骤：

###### 0.初始化SDK库：linux下不需要此步骤；windows平台需要；只需要初始化一次；

###### 1.调用函数：bxDual_dynamicArea_AddAreaWithTxt_5G；

- 配置控制卡IP、端口号、屏幕颜色类型
- 配置动态区属性：动态区ID、动态区显示的起始坐标和宽高、运行模式、是否关联节目
- 配置动态区内第一屏内容的属性（页属性）：显示方式（快速打出、左移，上移等）
- 配置显示文本的字体属性：字体名称、字体大小等
- 调用发送动态区接口函数bxDual_dynamicArea_AddAreaWithTxt_5G

###### 2.释放SDK库：与初始化SDK库一一对应；linux下不需要；



##### 代码示例：

- 配置控制卡IP、端口号、屏幕颜色类型

  ```
  //InitSdk(); //linux不需要初始化
  
  	Ouint8* pIP = (Ouint8*)"192.168.0.199";
  	Ouint32 nPort = 5005;
  	E_ScreenColor_G56 color = E_ScreenColor_G56::eSCREEN_COLOR_SINGLE;
  ```

- 配置动态区属性：动态区ID、动态区显示的起始坐标和宽高、运行模式、是否关联节目

  ```
  Ouint8 uAreaId = 0;  //动态区ID
  	Ouint8 RunMode = 0x00;
  	/*0x00 动态区运行模式
  	0— 动态区数据循环显示。
  	1— 动态区数据显示完成后静止显示最后一页数据。
  	2— 动态区数据循环显示，超过设定时间后数据仍未更新时不再显示
  	3— 动态区数据循环显示，超过设定时间后数据仍未更新时显示Logo 信息, Logo 信息即为动态区域的最后一页信息
  	4— 动态区数据顺序显示，显示完最后一页后就不再显示
  	*/
  	Ouint16 Timeout = 3;	//Timeout 2 动态区数据超时时间，单位为秒
  	Ouint8 RelateAllPro = 0;//RelateAllPro 1 当该字节为 1 时，所有异步节目播放时都允许播放该动态区域；为 0 时，由接下来的规则来决定
  	Ouint16 RelateProNum = 0;//动态区域关联了多少个异步节目一旦关联了某个异步节目，则当该异步节目播放时允许播放该动态区域，否则，不允许播放该动态区域；以下的节目编号个数根据 RelateProNum 的值来确定，当该值为 0 时不发送；
  	Ouint16* RelateProSerial = NULL;
  	Ouint8 ImmePlay = 1;	//1 是否立即播放该字节为 0 时，该动态区域与异步节目一起播放；该字节为 1 时，异步节目停止播放，仅播放该动态区域该字节; 为 2 时，暂存该动态区域，当播放完节目编号最高的异步节目后播放该动态区域注意：当该字节为 0 时，RelateAllPro 到RelateProSerialN-1 的参数才有效，否则无效当该参数为 1 或 2 时，由于不与异步节目同时播放，为控制该动态区域能及时结束，可选择RunMode 参数为 2 或 4
  	Ouint16 uAreaX = 16;
  	Ouint16 uAreaY = 2;
  	Ouint16 uWidth = 64;
  	Ouint16 uHeight = 30;
  	EQareaframeHeader oFrame; oFrame.AreaFFlag = 0;
  ```

- 配置动态区内第一屏内容的属性（页属性）：显示方式（快速打出、左移，上移等）

  ```
      //PageStyle begin-------------------------------
  	Ouint8 DisplayMode = 3;		//显示方式:  0x00 –随机显示 0x01 –静止显示 0x02 –快速打出 0x03 –向左移动 0x04 –向左连移 0x05 –向上移动 0x06 –向上连移 0x07 –闪烁......
  	Ouint8 ClearMode = 0;		//退出方式/清屏方式: 每一页的退出方式；
  	Ouint8 Speed = 32;			//速度等级
  	Ouint16 StayTime = 200;		//停留时间，单位为 10ms
  	Ouint8 RepeatTime = 3;
  	//PageStyle End.
  ```

- 配置显示文本的字体属性：字体名称、字体大小等

  ```
  //显示内容和字体格式 begin----------------------------------------------
  	EQfontData oFont;
  	oFont.arrMode = eMULTILINE;
  	oFont.fontSize = 10;
  	oFont.color = eRED;
  	oFont.fontBold = false;
  	oFont.fontItalic = false; oFont.tdirection = pNORMAL;
  	oFont.txtSpace = 0; oFont.Halign = 1; oFont.Valign = 2;
  	Ouint8* fontName = (Ouint8*)"宋体";
  	Ouint8* strAreaTxtContent = (Ouint8*)"5E1动态-图文-文本测试。";// "5代动态区1开始测试，一起来看看吧...会有新发现的。";
  ```

- 调用发送动态区接口函数bxDual_dynamicArea_AddAreaWithTxt_5G

```c++

/*
功能说明：增加一条文件信息到指定的动态区，并可以关联这个动态区到指定的节目；
参数说明：strAreaTxtContent - 动态区域内要显示的文本内容
*/
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
```

