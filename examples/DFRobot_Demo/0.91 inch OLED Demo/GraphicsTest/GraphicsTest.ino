/*

  GraphicsTest.ino

  Universal 8bit Graphics Library (https://github.com/olikraus/u8g2/)

  Copyright (c) 2016, olikraus@gmail.com
  All rights reserved.

  Modify by [Ajax](Ajax.zhong@dfrobot.com)
  url https://github.com/DFRobot/U8g2_Arduino
  2019-11-29

*/
#include <Arduino.h>
#include <U8g2lib.h>

#include <Wire.h>


/*
  U8g2lib Example Overview:
    Frame Buffer Examples: clearBuffer/sendBuffer. Fast, but may not work with all Arduino boards because of RAM consumption
    Page Buffer Examples: firstPage/nextPage. Less RAM usage, should work with all Arduino boards.
    U8x8 Text Only Example: No RAM usage, direct communication with display controller. No graphics, 8x8 Text only.
    
*/

// Please UNCOMMENT one of the contructor lines below
// U8g2 Contructor List (Frame Buffer)
// The complete list is available here: https://github.com/olikraus/u8g2/wiki/u8g2setupcpp
// Please update the pin numbers according to your setup. Use U8X8_PIN_NONE if the reset pin is not connected

U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE); //  M0/ESP32/ESP8266/mega2560/Uno/Leonardo

void u8g2_prepare(void) {
  u8g2.setFont(u8g2_font_6x10_tf);	//设置字体为"u8g2_font_6x10_tf"
  u8g2.setFontRefHeightExtendedText();//Ascent will be the largest ascent of "A", "1" or "(" of the current font. Descent will be the descent of "g" or "(" of the current font.
  u8g2.setDrawColor(1);		//定义所有绘图功能的位值（颜色索引）。所有绘图功能都会将显示存储器更改为该位值。默认值为1。
  u8g2.setFontPosTop();	/*使用drawStr显示字符串时，默认标准为显示字符的左下角坐标。
                          本函数的功能可理解为将坐标位置改为显示字符串的左上角为坐标标准。*/
  u8g2.setFontDirection(0);	//设置屏幕方向：0--为正常显示
}

void u8g2_box_title(uint8_t a) {
  u8g2.drawStr( 10+a*2, 5, "U8g2");
  u8g2.drawStr( 10, 20, "GraphicsTest");
  u8g2.drawFrame(0,0,u8g2.getDisplayWidth(),u8g2.getDisplayHeight() );//在坐标为(0,0)的位置开始绘制一个宽度w和高度h的空框
}

void u8g2_box_frame(uint8_t a) {
  u8g2.drawStr(0,0,"drawBox-drawFrame");
  u8g2.drawBox(5+a,9,50,10); //在坐标为(5+a,9)的位置开始绘制一个宽度w和高度h的实心框
  u8g2.drawFrame(5+a,20,50,10);
}

void u8g2_circle_disc(uint8_t a){
  u8g2.drawStr(0,0,"drawDisc-drawCircle");
  u8g2.drawCircle(10+a,20,10);  //在位置(10+a,20)绘制一个半径为10的实心圆
  u8g2.drawDisc(118-a,20,10);   //在位置(118-a,20)绘制一个半径为10的空心圆
}

void u8g2_RBox_RFrame(uint8_t a){
  u8g2.drawStr(0,0,"drawRBox-drawRFrame");
  u8g2.drawRBox(5+a,9,30,20,a+1);   //在位置(5+a,9)开始绘制宽度为40，高度为30一个具有半径为a+1的圆形边缘的框（空心）。
  u8g2.drawRFrame(90-a,9,30,20,a+1);  //在位置(90-a,9)开始绘制宽度为25，高度为40一个具有半径为a+1的圆形边缘的框（实心）。
}

void u8g2_Hline(uint8_t a){
  u8g2.drawStr(0,0,"drawHLine");
  u8g2.drawHLine(1,10,40+a*5); //在坐标为（1，10）画一条射线
  u8g2.drawHLine(10,20,40+a*5);
  u8g2.drawHLine(20,30,40+a*5);
}

void u8g2_line(uint8_t a){
  u8g2.drawStr(0,0,"drawLine");
  u8g2.drawLine(10+a,10,80-a,32); //在两点之间画一条线。（参数为两点坐标）
  u8g2.drawLine(10+a*2,10,80-a*2,32);
  u8g2.drawLine(10+a*3,10,80-a*3,32);
  u8g2.drawLine(10+a*4,10,80-a*4,32);
}

void u8g2_triangle(uint8_t a) {
  uint16_t offset = a;
  u8g2.drawStr( 0, 0, "drawTriangle");
  u8g2.drawTriangle(14,7, 45,30, 10,40);  //绘制一个三角形（实心多边形）。（参数为三角形三个顶点坐标）
  u8g2.drawTriangle(14+offset,7-offset, 45+offset,30-offset, 57+offset,10-offset);
  u8g2.drawTriangle(57+offset*2,10, 45+offset*2,30, 86+offset*2,53);
  u8g2.drawTriangle(10+offset,40+offset, 45+offset,30+offset, 86+offset,53+offset);
}

void u8g2_ascii_1() {
  char s[2] = " ";
  uint8_t x, y;
  u8g2.drawStr( 0, 0, "ASCII page 1");
  for( y = 0; y < 2; y++ ) {
    for( x = 0; x < 16; x++ ) {
      s[0] = y*16 + x + 32;
      u8g2.drawStr(x*7, y*10+10, s);
    }
  }
}

void u8g2_ascii_2() {
  char s[2] = " ";
  uint8_t x, y;
  u8g2.drawStr( 0, 0, "ASCII page 2");
  for( y = 0; y < 2; y++ ) {
    for( x = 0; x < 16; x++ ) {
      s[0] = y*16 + x + 160;
      u8g2.drawStr(x*7, y*10+10, s);
    }
  }
}

void u8g2_extra_page(uint8_t a)
{
  u8g2.drawStr( 0, 0, "Unicode");
  u8g2.setFont(u8g2_font_unifont_t_symbols);
  u8g2.setFontPosTop();
  u8g2.drawUTF8(0, 9, "☀ ☁");//在位置(0,24)开始绘制一个编码为UTF-8的字符串图标
  switch(a) {
    case 0:
    case 1:
    case 2:
    case 3:
      u8g2.drawUTF8(a*3, 20, "☂");
      break;
    case 4:
    case 5:
    case 6:
    case 7:
      u8g2.drawUTF8(a*3, 20, "☔");
      break;
  }
}

void u8g2_xor(uint8_t a) {
  uint8_t i;
  u8g2.drawStr( 0, 0, "XOR");
  u8g2.setFontMode(1);
  u8g2.setDrawColor(2);
  for( i = 0; i < 5; i++)
  {
    u8g2.drawBox(10+i*16, 18, 21,10);
  }
  u8g2.drawStr( 5+a, 19, "XOR XOR XOR XOR");
}

/*
 *这是一个图形转换成位图的数据，用于使用drawXBMP()显示
*/
#define cross_width 24
#define cross_height 24
static const unsigned char cross_bits[] U8X8_PROGMEM  = {
  0x00, 0x18, 0x00, 0x00, 0x24, 0x00, 0x00, 0x24, 0x00, 0x00, 0x42, 0x00, 
  0x00, 0x42, 0x00, 0x00, 0x42, 0x00, 0x00, 0x81, 0x00, 0x00, 0x81, 0x00, 
  0xC0, 0x00, 0x03, 0x38, 0x3C, 0x1C, 0x06, 0x42, 0x60, 0x01, 0x42, 0x80, 
  0x01, 0x42, 0x80, 0x06, 0x42, 0x60, 0x38, 0x3C, 0x1C, 0xC0, 0x00, 0x03, 
  0x00, 0x81, 0x00, 0x00, 0x81, 0x00, 0x00, 0x42, 0x00, 0x00, 0x42, 0x00, 
  0x00, 0x42, 0x00, 0x00, 0x24, 0x00, 0x00, 0x24, 0x00, 0x00, 0x18, 0x00, };

#define cross_fill_width 24
#define cross_fill_height 24
static const unsigned char cross_fill_bits[] U8X8_PROGMEM  = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x00, 0x18, 0x64, 0x00, 0x26, 
  0x84, 0x00, 0x21, 0x08, 0x81, 0x10, 0x08, 0x42, 0x10, 0x10, 0x3C, 0x08, 
  0x20, 0x00, 0x04, 0x40, 0x00, 0x02, 0x80, 0x00, 0x01, 0x80, 0x18, 0x01, 
  0x80, 0x18, 0x01, 0x80, 0x00, 0x01, 0x40, 0x00, 0x02, 0x20, 0x00, 0x04, 
  0x10, 0x3C, 0x08, 0x08, 0x42, 0x10, 0x08, 0x81, 0x10, 0x84, 0x00, 0x21, 
  0x64, 0x00, 0x26, 0x18, 0x00, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, };

#define cross_block_width 14
#define cross_block_height 14
static const unsigned char cross_block_bits[] U8X8_PROGMEM  = {
  0xFF, 0x3F, 0x01, 0x20, 0x01, 0x20, 0x01, 0x20, 0x01, 0x20, 0x01, 0x20, 
  0xC1, 0x20, 0xC1, 0x20, 0x01, 0x20, 0x01, 0x20, 0x01, 0x20, 0x01, 0x20, 
  0x01, 0x20, 0xFF, 0x3F, };

void u8g2_bitmap_overlay(uint8_t a) {
  uint8_t frame_size = 28;

  u8g2.drawStr(0, 0, "Bitmap overlay");

  u8g2.drawStr(0, frame_size + 12, "Solid / transparent");
  u8g2.setBitmapMode(false /* solid */);
  u8g2.drawFrame(0, 10, frame_size, frame_size);
  u8g2.drawXBMP(2, 12, cross_width, cross_height, cross_bits);
  if(a & 4)
    u8g2.drawXBMP(7, 17, cross_block_width, cross_block_height, cross_block_bits);//绘制位图

  u8g2.setBitmapMode(true /* transparent*/);
  u8g2.drawFrame(frame_size + 5, 10, frame_size, frame_size);
  u8g2.drawXBMP(frame_size + 7, 12, cross_width, cross_height, cross_bits);
  if(a & 4)
    u8g2.drawXBMP(frame_size + 12, 17, cross_block_width, cross_block_height, cross_block_bits);
}

uint8_t draw_state = 0;

void draw(void) {
  u8g2_prepare();
  switch(draw_state >> 3) {
    case 0: u8g2_box_title(draw_state&7); break;
    case 1: u8g2_box_frame(draw_state&7); break;
    case 2: u8g2_circle_disc(draw_state&7); break;
    case 3: u8g2_RBox_RFrame(draw_state&7); break;
    case 4: u8g2_Hline(draw_state&7); break;
    case 5: u8g2_line(draw_state&7); break;
    case 6: u8g2_triangle(draw_state&7); break;
    case 7: u8g2_ascii_1(); break;
    case 8: u8g2_ascii_2(); break;
    case 9: u8g2_extra_page(draw_state&7); break;
    case 10: u8g2_xor(draw_state&7); break;
    case 11: u8g2_bitmap_overlay(draw_state&7); break;
  }
}

void setup(void) {
  u8g2.begin();
}

void loop(void) {
  // picture loop  
  u8g2.firstPage();  
  do {
    draw();
  } while( u8g2.nextPage() );
  
  // increase the state
  draw_state++;
  if ( draw_state >= 14*8 )
    draw_state = 0;

  // delay between each page
  delay(150);

}
