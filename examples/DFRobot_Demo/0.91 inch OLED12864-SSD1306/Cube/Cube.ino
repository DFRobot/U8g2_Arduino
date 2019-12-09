/*!
 * @file Cube.ino
 * @brief 旋转的三维立体图形
 * @n 这是一个简单的旋转四面体
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
U8G2_SSD1306_128X64_NONAME_1_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);  //  M0/ESP32/ESP8266/mega2560/Uno/Leonardo
//U8G2_SSD1306_128X64_NONAME_1_4W_HW_SPI u8g2(U8G2_R0, /* cs=*/ 10, /* dc=*/ 9);


//二维数组，里面存储了四面体所有顶点的坐标
double tetrahedron[4][3] = {{0,30,-30},{-30,-30,-30},{30,-30,-30},{0,0,30}};
void setup(void) {
  u8g2.begin();  
}

void loop(void) {
  u8g2.firstPage();
  do {
  //将四面体里面相对应的点连接到一起
  u8g2.drawLine(OxyzToOu(tetrahedron[0][0], tetrahedron[0][2]), OxyzToOv(tetrahedron[0][1], tetrahedron[0][2]), OxyzToOu(tetrahedron[1][0], tetrahedron[1][2]), OxyzToOv(tetrahedron[1][1], tetrahedron[1][2]));
  u8g2.drawLine(OxyzToOu(tetrahedron[1][0], tetrahedron[1][2]), OxyzToOv(tetrahedron[1][1], tetrahedron[1][2]), OxyzToOu(tetrahedron[2][0], tetrahedron[2][2]), OxyzToOv(tetrahedron[2][1], tetrahedron[2][2]));
  u8g2.drawLine(OxyzToOu(tetrahedron[0][0], tetrahedron[0][2]), OxyzToOv(tetrahedron[0][1], tetrahedron[0][2]), OxyzToOu(tetrahedron[2][0], tetrahedron[2][2]), OxyzToOv(tetrahedron[2][1], tetrahedron[2][2]));
  u8g2.drawLine(OxyzToOu(tetrahedron[0][0], tetrahedron[0][2]), OxyzToOv(tetrahedron[0][1], tetrahedron[0][2]), OxyzToOu(tetrahedron[3][0], tetrahedron[3][2]), OxyzToOv(tetrahedron[3][1], tetrahedron[3][2]));
  u8g2.drawLine(OxyzToOu(tetrahedron[1][0], tetrahedron[1][2]), OxyzToOv(tetrahedron[1][1], tetrahedron[1][2]), OxyzToOu(tetrahedron[3][0], tetrahedron[3][2]), OxyzToOv(tetrahedron[3][1], tetrahedron[3][2]));
  u8g2.drawLine(OxyzToOu(tetrahedron[2][0], tetrahedron[2][2]), OxyzToOv(tetrahedron[2][1], tetrahedron[2][2]), OxyzToOu(tetrahedron[3][0], tetrahedron[3][2]), OxyzToOv(tetrahedron[3][1], tetrahedron[3][2]));
  // 旋转0.1度
  rotate(0.1);
  
  } while ( u8g2.nextPage() );
  //delay(50);
}
/*！
 * @brief 将三维坐标系Oxyz里的xz转化为二维坐标系Ouv里面的 u坐标
 * @param 三维坐标系Oxyz里的x坐标    
 * @param 三维坐标系Oxyz里的z坐标
 * @return 二维坐标系Ouv里面的 u坐标
 */
int OxyzToOu(double x,double z){
   
   return (int)((x + 64) - z*0.35);
}


/*！
 * @brief 将三维坐标系Oxyz里的yz转化为二维坐标系Ouv里面的 v坐标
 * @param 三维坐标系Oxyz里的y坐标    
 * @param 三维坐标系Oxyz里的z坐标
 * @return 二维坐标系Ouv里面的v坐标
 */ 
int OxyzToOv(double y,double z){
    return (int)((y + 35) - z*0.35);
}


/*!
 * @brief  将整个三维图形的所有点的坐标绕 Z轴旋转
 * @param  angle 表示要旋转的角度
 *     
 *  z旋转(z不变)
    x3 = x2 * cosb - y1 * sinb
    y3 = y1 * cosb + x2 * sinb
    z3 = z2
 */
void rotate(double angle)
{
  double rad, cosa, sina, Xn, Yn;
 
  rad = angle * PI / 180;
  cosa = cos(rad);
  sina = sin(rad);
  for (int i = 0; i < 4; i++)
  {
    Xn = (tetrahedron[i][0] * cosa) - (tetrahedron[i][1] * sina);
    Yn = (tetrahedron[i][0] * sina) + (tetrahedron[i][1] * cosa);

    //将已经转化好的的坐标存入坐标数组
    //由于是绕Z轴旋转，所以点 z 轴的坐标不变
    tetrahedron[i][0] = Xn;
    tetrahedron[i][1] = Yn;
  }
}
