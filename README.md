# BX-G5/G6 C++ SDK 

## 文档适用者

通过仰邦SDK对仰邦控制卡向LED显示屏发布显示内容的软件开发者；

SDK中包含较多可调用的函数接口；

本文档主要讨论发布显示内容的相关SDK接口



## 软件开发环境

x86_64 GNU/Linux

(GNU libc) 2.17及以上版本

SDK相关依赖库

onbon SDK



## 适用控制卡类型

仰邦5代、6代单双色图文控制卡;



# 发布内容的二种接口

节目接口和动态区接口：

需要频繁更新的显示内容，使用动态区接口来发送；反之，不需要频繁更新的显示内容，推荐使用节目接口来实现。

节目和动态区的内在区别：

节目：节目内容可以长期保存在控制卡的可记忆可擦除Flash中，所以控制卡掉电后，再重启，节目内容仍可以重新显示；但是Flash擦写次数是有限制的。

动态区：动态区内容保存在掉电后不保存数据的RAM中，所以显示内容掉电不保存，即再次对控制卡上电后，动态区的内容就没有了。但是RAM对于刷新次数没有限制，主要应用于更新频次高，更新速度比较快的场合。



## 动态区接口的使用

### 6代卡动态区的使用：

#### 一、动态区的发布

步骤：

1.配置控制卡IP及端口

2.配置屏幕类型：单色、双色、三色

3.配置动态区参数：显示区的位置、大小、内容等

4.配置动态区内显示内容的特性：显示效果（移动速度等）、字体名称和大小等

5.调用发送动态区接口；



代码实例：

```c++
/*1.配置控制卡IP及端口*/
	Ouint8* pIP = (Ouint8*)g_IP;//"192.168.0.181";
	Ouint32 nPort = 5005;

/*2.配置屏幕类型：单色、双色、三色*/
	E_ScreenColor_G56 color = eSCREEN_COLOR_DOUBLE;

/*3.配置动态区参数：显示区的位置、大小、内容等*/	
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
		
/*4.配置动态区内显示内容的特性：显示效果（移动速度等）、字体名称和大小等*/         	            		EQpageHeader_G6 pheader1;
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

/*5.调用发送动态区接口；*/        
        Ouint8 nAreaID = 0;
        Ouint8 str[] = "汉字测试123456789";
		dynamicArea_AddAreaTxtDetails_6G(pIP, 5005, eSCREEN_COLOR_DOUBLE, nAreaID, &aHeader1, &pheader1, (Ouint8*)"./allfonts/1.ttf", (Ouint8*)str);
	}
```



#### 二、动态区的删除

删除所有动态区：

```c++

```

删除指定动态区：

```c++

```







