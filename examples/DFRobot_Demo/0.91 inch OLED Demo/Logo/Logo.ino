/*!
 * @file Logo.ino
 * @brief 用U8G2在屏幕中显示一个单色图片
 * @n U8G2字体GitHub连接：https://github.com/olikraus/u8g2/wiki/fntlistall
 * 
 * @copyright  Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
 * @licence     The MIT License (MIT)
 * @author [Ajax](Ajax.zhong@dfrobot.com)
 * @version  V1.0
 * @date  2019-11-29
 * @get from https://www.dfrobot.com
 * @url https://github.com/DFRobot/U8g2_Arduino
*/

#include <Arduino.h>
#include <U8g2lib.h>

#include <Wire.h>

/*
 *IIC构造函数
 *@param 指定大局显示的基本布局：	U8G2_R0 不旋转，横向，绘制方向从左到右
									U8G2_R1 顺时针旋转90度，绘制方向从上到下
									U8G2_R2 顺时针旋转180度，绘制方向从右到左
									U8G2_R3 顺时针旋转270度，绘制方向从下到上
									U8G2_MIRROR 正常显示镜像内容（v2.6.x版本以上使用)   注意:U8G2_MIRROR需要与setFlipMode（）配搭使用.
 *@param reset：U8x8_PIN_NONE 表示引脚为空，不会使用复位引脚
 *
*/
U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);  //  M0/ESP32/ESP8266/mega2560/Uno/Leonardo

//下面的数组图片的数据  width:30,height:30
const unsigned char col[] U8X8_PROGMEM= {0x00,0xc0,0x00,0x00,0x00,0xe0,0x01,0x00,0x00,0xe0,0x01,0x00,0x00,0xc0,0x00,0x00,
                                         0x00,0xc0,0x00,0x00,0x00,0xc0,0x00,0x00,0x00,0xe0,0x01,0x00,0x00,0xf8,0x07,0x00,
                                         0x06,0xfe,0x1f,0x18,0x07,0xff,0x3f,0x38,0xdf,0xff,0xff,0x3e,0xfa,0xff,0xff,0x17,
                                         0xf0,0xff,0xff,0x03,0xe0,0xff,0xff,0x01,0xe0,0xff,0xff,0x01,0xe0,0xff,0xff,0x01,
                                         0xe0,0xff,0xff,0x01,0x20,0x00,0x00,0x01,0xa0,0xff,0x7f,0x01,0xa0,0x01,0x60,0x01,
                                         0x20,0x07,0x38,0x01,0xe0,0x0c,0xcc,0x01,0xe0,0x39,0xe7,0x01,0xe0,0xe7,0xf9,0x01,
                                         0xc0,0x1f,0xfe,0x00,0x80,0xff,0x7f,0x00,0x00,0xfe,0x1f,0x00,0x00,0xf8,0x07,0x00,
                                         0x00,0xe0,0x01,0x00,0x00,0xc0,0x00,0x00}; 

                                         
void setup(void) {
  u8g2.begin();  //初始化函数
}

 

void loop(void) {

  u8g2.clearBuffer();           // 清空显示设备内部缓冲区
//  u8g2.drawBox(0,0,128,32);  //画一个全屏显示
//  u8g2.sendBuffer();        // 显示缓冲区内容
//  
//  delay(2000);

  u8g2.clearBuffer(); 
  u8g2.drawXBMP( /* x=*/0 , /* y=*/0 , /* width=*/30 , /* height=*/30 , col );     //30,30为图片尺寸，根据你的图片尺寸修改
  u8g2.setFont(u8g2_font_ncenB14_tr);    //设置字体
  u8g2.drawStr(32,30,"DFRobot");        //绘制字符串
  u8g2.sendBuffer();        // 显示缓冲区内容
  
  delay(2000);  
}
