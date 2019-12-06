/*!
 * @file Font.ino
 * @brief U8G2中几种支持字体的显示
 * @n U8G2支持多种字体，本demo只是选取几种字体进行显示
 * @n U8G2字体GitHub连接：https://github.com/olikraus/u8g2/wiki/fntlistall
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


void setup(void){
  u8g2.begin();            //初始化函数
  u8g2.setFontPosTop();   /*使用drawStr显示字符串时，默认标准为显示字符的左下角坐标。
                          本函数的功能可理解为将坐标位置改为显示字符串的左上角为坐标标准。*/
    }

void loop(void){
  u8g2.clearBuffer();            //清除缓存  
  u8g2.setFont(u8g2_font_maniac_tr); //设置“u8g2_font_maniac_tr”为字体 
  u8g2.drawStr(/* x=*/0, /* y=*/5, "DFR123");  //在x=0，y=5的坐标开始绘制字符串“DFR123”  
  u8g2.sendBuffer();          //发送缓存到显示器      
  
  delay(1000);               //等待1000ms
   
  u8g2.clearBuffer();             
  
  u8g2.setFont(u8g2_font_secretaryhand_tf); 
  u8g2.drawStr(0, 0, "DFR123");   
  
  u8g2.setFont(u8g2_font_heavybottom_tr);
  u8g2.drawStr(70, 0, "DFR12");   //drawGlyph(u8g2_uint_t x, u8g2_uint_t y, uint16_t encoding);
  
  u8g2.setFont(u8g2_font_fancypixels_tf);
  u8g2.drawStr(0, 20, "DFR123");  //drawGlyph(u8g2_uint_t x, u8g2_uint_t y, uint16_t encoding);
  
  u8g2.setFont(u8g2_font_fancypixels_tf);
  u8g2.drawStr(70, 20, "DFR123");  //drawGlyph(u8g2_uint_t x, u8g2_uint_t y, uint16_t encoding);
  
  u8g2.sendBuffer();               
  delay(1000); 
}
