# U8g2_Arduino: Arduino Monochrome Graphics Library

![https://raw.githubusercontent.com/wiki/olikraus/u8g2/img/uc1701_dogs102_uno_board_320.jpg](https://raw.githubusercontent.com/wiki/olikraus/u8g2/img/uc1701_dogs102_uno_board_320.jpg) 

U8glib V2 library for Arduino

Description: https://github.com/olikraus/u8g2/wiki

Issue Tracker: https://github.com/olikraus/u8g2/issues

Download (2.26.14): https://github.com/olikraus/U8g2_Arduino/archive/master.zip

## U8g2_Arduino:单色图像显示库
* `U8g2_Arduino`是一个功能强大的单色图像显示库，提供了通用的基础显示（点、线、圆等）、各种常用的图标、好看的字体等。DFRobot基于自身产品，对`U8g2_Arduino`进行了修改：
    1. 增加了DFRobot_Demo文件夹，提供了产品的特色Demo。
    1. 对所有Demo的实体化函数进行了删减。


## 功能列表
`U8g2_Arduino`集成了大量的功能组件。可以实现丰富的单色显示效果。

`U8g2_Arduino` API接口函数：https://github.com/olikraus/u8g2/wiki/u8g2reference#updatedisplayarea=%E5%BA%93%E6%96%87%E4%BB%B6

`U8g2_Arduino` 字体参数列表：https://github.com/olikraus/u8g2/wiki/fntlistall

## U8g2_Arduino兼容性
`U8g2_Arduino`可以支持多种MCU，下表可以查看支持的MCU型号。

主控          |     Uno      |   Leonardo    |     FireBeetleESP32     |    FireBeetleESP8266    |     m0         |     BK7251      
-----------  | :----------: |  :----------: |  :----------: |  :----------: | :------------: |   ------------
U8g2_Arduino |      √       |       √       |      √        |       √       |       √        |  


## U8g2_Arduino支持屏幕
 
`U8g2_Arduino`目前支持多种的显示驱动IC和分辨率，下表查看目前可用的驱动和屏幕。U8g2_Arduino根据产品会进行实时更新。<br>

* SSD1306 0.91" OLED-A<br>
[产品图片]
* SSD1306 0.91" OLED-B<br>
[产品图片]
* SSD1306 0.96" OLED<br>
[产品图片]


## 安装U8g2_Arduino固件
`U8g2_Arduino`可以满足不同软件开发水平的人使用。对于初学者，您只需有Arduino基础，就可以进行丰富多样的显示。`U8g2_Arduino` API接口函数链接可以帮助你学习。

1. 下载Arduino IDE<br>
1. 从github下载`U8g2_Arduino`代码<br>
1. 使用Arduino IDE从下载的文件中打开“GraphicsTest.ino”<br>
1. 连接您的Arduino Uno开发板<br>
1. 选择工具>板子：Arduino Uno和工具>端口：选择你的Arduino开发板<br>
1. 单击“验证”，然后将软件“上传”到您的开发板上



## 常见问题

1、问：为什么有的示例程序在Arduino UNO/Leonardo上运行不了？
    
 * 答：因为Arduino UNO/Leonardo内存大小，无法存储下整个程序；您可以换一个内存较大的主控，如Firebettle-ESP32等。我们在每一个ino的头文件都有对应的说明，大家可以详细阅读。<br>

2、问：为什么Language.ino中韩文不能正常显示？

*  答：这是由于Arduino编码的原因，如果Arduino IDE是utf8编码，就不会有这个问题。虽然在示例程序中不能正常显示，但是上传代码后，屏幕正常显示。
