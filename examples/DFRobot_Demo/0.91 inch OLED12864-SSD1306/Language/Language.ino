/*!
 * @file Font.ino
 * @brief U8G2中支持多种语言的显示
 * @n U8G2支持多种语言，此demo展示了中、英、韩、日四国语言。
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
U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);  //  M0/ESP32/ESP8266/mega2560/Uno/Leonardo
//U8G2_SSD1306_128X64_NONAME_1_4W_HW_SPI u8g2(U8G2_R0, /* cs=*/ 10, /* dc=*/ 9);



void setup(void) {
  u8g2.begin();    //初始化函数
  u8g2.enableUTF8Print();		// 为Arduino print（）函数启用UTF8支持
}

void loop(void) 
{
  /*字库占用的内存较大，谨慎使用。若只需显示固定几个字，可自行获得汉字编码，
  通过drawXBM的方法去显示。或者使用内存更大的主控*/
  u8g2.setFont(u8g2_font_unifont_t_chinese2);  //对“你好世界”的所有字形使用chinese2
  //u8g2.setFont(u8g2_font_b10_t_japanese1);  // 日语中已经包含了所有“こんにちは世界”的字形1：Lerning 1-6级
  //u8g2.setFont(u8g2_font_unifont_t_korean1);  // 日语中已经包含了所有“안녕하세요세계”的字形：Lerning 1-2级
  u8g2.setFontDirection(0);   //设置字体方向，旋转0度,正常方向显示
  /*
   * firstPage方法会把当前页码位置变成0
   * 修改内容处于firstPage和nextPage之间，每次都是重新渲染所有内容
   * 该方法消耗的ram空间，比sendBuffer消耗的ram空间要少
  */ 
  u8g2.firstPage();
  do {
    u8g2.setCursor(/* x=*/0, /* y=*/15);    //定义打印功能的光标,打印 功能的任何输出都将在此位置开始
    u8g2.print("Hello World!");
    u8g2.setCursor(0, 30);
    u8g2.print("你好世界");		// Chinese "Hello World" 
    //u8g2.print("こんにちは世界");		// Japanese "Hello World" 
    //u8g2.print("안녕하세요 세계");   // Korean "Hello World" 
  } while ( u8g2.nextPage() );
  delay(1000);
}
