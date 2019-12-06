/*!
 * @file Font.ino
 * @brief U8G2中支持的几种字体显示
 * @n U8G2支持多种字体，此demo只是选取几种字体进行显示
 * @n U8G2字体GitHub连接：https://github.com/olikraus/u8g2/wiki/fntlistall
 * 
 * @copyright  Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
 * @licence     The MIT License (MIT)
 * @author [Ivey](Ivey.lu@dfrobot.com)
 * @version  V1.0
 * @date  2019-11-29
 * @get from https://www.dfrobot.com
 * @url https://github.com/DFRobot/U8g2_Arduino
*/

#include <Arduino.h>
#include <U8g2lib.h>

#include <SPI.h>
#include <Wire.h>

/*
 *IIC构造函数
 *@param 指定大局显示的基本布局：	U8G2_R0 不旋转，横向，绘制方向从左到右
									U8G2_R1 顺时针旋转90度，绘制方向从上到下
									U8G2_R2 顺时针旋转180度，绘制方向从右到左
									U8G2_R3 顺时针旋转270度，绘制方向从下到上
									U8G2_MIRROR 正常显示镜像内容（v2.6.x版本以上使用)   注意:U8G2_MIRROR需要与setFlipMode（）配搭使用.
 *@param reset：U8x8_PIN_NONE 表示引脚为空，不会使用复位引脚
 *SPI构造函数
 *@param  cs 按引脚接上即可（引脚可自己选择）
 *@param  dc 按引脚接上即可（引脚可自己选择）
 *
*/
U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);    //  M0/ESP32/ESP8266/mega2560/Uno/Leonardo
//U8G2_SSD1306_128X64_NONAME_1_4W_HW_SPI u8g2(U8G2_R0, /* cs=*/ 10, /* dc=*/ 9);

void setup(void)
{
  u8g2.begin();       //初始化函数
  u8g2.setFontPosTop();  /*使用drawStr显示字符串时，默认标准为显示字符的左下角坐标。
                          本函数的功能可理解为将坐标位置改为显示字符串的左上角为坐标标准。*/
}


void draw(int a )
{
   switch(a)
   {
     case 0: 
     u8g2.setFont(u8g2_font_bubble_tr   );    //设置字体集，字体为“u8g2_font_bubble_tr”。
     u8g2.drawStr(/* x=*/0,/* y=*/0, "DFR123");       //在x=0，y=0的坐标开始绘制字符串“DFR123”
     u8g2.setFont(u8g2_font_lucasarts_scumm_subtitle_o_tf     );
     u8g2.drawStr(0, 25, "DFR123");  
     u8g2.setFont(u8g2_font_HelvetiPixelOutline_tr     );
     u8g2.drawStr(0, 45, "DFR123"); 
     break;            
     case 1: 
     u8g2.setFont(u8g2_font_tenstamps_mr    );
     u8g2.drawStr(0,0, "DFR123");  
     u8g2.setFont(u8g2_font_jinxedwizards_tr      );
     u8g2.drawStr(56, 16, "DFR123");  
     u8g2.setFont(u8g2_font_secretaryhand_tr      );
     u8g2.drawStr(0, 32, "DFR123"); 
     u8g2.setFont(u8g2_font_freedoomr10_mu       );
     u8g2.drawStr(56, 48, "DFR123"); 
     break;                     
   }	   
}

 void loop()
{
  for( int i = 0; i <2 ; i++)
  {
   /*
	* firstPage方法会把当前页码位置变成0
	* 修改内容处于firstPage和nextPage之间，每次都是重新渲染所有内容
	* 该方法消耗的ram空间，比sendBuffer消耗的ram空间要少
   */ 
    u8g2.firstPage();   
    do
	  {
		  draw(i);
	  } while( u8g2.nextPage() );
	  delay(2000);
  }
}
