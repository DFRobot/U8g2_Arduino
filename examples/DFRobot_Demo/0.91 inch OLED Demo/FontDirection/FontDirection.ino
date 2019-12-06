/*!
 * @file FontDirection.ino
 * @brief U8G2字体的旋转显示
 * 
 * @copyright  Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
 * @licence     The MIT License (MIT)
 * @author [Ajax](Ajax.zhong@dfrobot.com)
 * @version  V1.0
 * @date  2019-11-29
 * @get from https://www.dfrobot.com
 * @url https://github.com/DFRobot/
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

const uint8_t col[] U8X8_PROGMEM= {0x00,0xc0,0x00,0x00,0x00,0xe0,0x01,0x00,0x00,0xe0,0x01,0x00,0x00,0xc0,0x00,0x00,
                                         0x00,0xc0,0x00,0x00,0x00,0xc0,0x00,0x00,0x00,0xe0,0x01,0x00,0x00,0xf8,0x07,0x00,
                                         0x06,0xfe,0x1f,0x18,0x07,0xff,0x3f,0x38,0xdf,0xff,0xff,0x3e,0xfa,0xff,0xff,0x17,
                                         0xf0,0xff,0xff,0x03,0xe0,0xff,0xff,0x01,0xe0,0xff,0xff,0x01,0xe0,0xff,0xff,0x01,
                                         0xe0,0xff,0xff,0x01,0x20,0x00,0x00,0x01,0xa0,0xff,0x7f,0x01,0xa0,0x01,0x60,0x01,
                                         0x20,0x07,0x38,0x01,0xe0,0x0c,0xcc,0x01,0xe0,0x39,0xe7,0x01,0xe0,0xe7,0xf9,0x01,
                                         0xc0,0x1f,0xfe,0x00,0x80,0xff,0x7f,0x00,0x00,0xfe,0x1f,0x00,0x00,0xf8,0x07,0x00,
                                         0x00,0xe0,0x01,0x00,0x00,0xc0,0x00,0x00}; // 图片的数据，尺寸为30x30

                                         

void setup() {
  u8g2.begin();  //初始化函数
}

void loop(void)
{ 
    u8g2.clearBuffer();    //清除缓存

    u8g2.drawXBMP( /* x=*/0 , /* y=*/0 , /* width=*/30 , /* height=*/30 , col );     //30,30为图片尺寸，根据你的图片尺寸修改
    
    u8g2.setFont(u8g2_font_pxplusibmvga9_tf);   //选择“u8g2_font_pxplusibmvga9_tf”为字体
    for(int i = 0; i < 4;i++)
    {
      switch(i)
      {
        case 0:
        /*@brief 设置所有字符串或字形的绘制方向setFontDirection(uint8_t dir)
         *@param dir=0，旋转0度
				 dir=1，旋转90度
				 dir=2，旋转180度
				 dir=3，旋转270度
        */
        u8g2.setFontDirection(0);           
        u8g2.drawStr(/* x=*/33, /* y=*/32, "DFR");
        break;
        
        case 1:
        u8g2.setFontDirection(1);
        u8g2.drawStr(66, 7, "DFR");
        break;
        
        case 2:
        u8g2.setFontDirection(2);
        u8g2.drawStr(110, 21, "DFR");
        break;
        
        case 3:
        u8g2.setFontDirection(3);
        u8g2.drawStr(128, 32, "DFR");
        break;
      }
      delay(500);
      u8g2.sendBuffer();//发送缓存数据到显示屏
    }

}
