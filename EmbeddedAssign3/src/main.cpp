#include <Arduino.h>
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define WIDTH   128   // OLED display width, in pixels
#define HEIGHT  64    // OLED display height, in pixels


// 构造对象
Adafruit_SSD1306  OLED(WIDTH, HEIGHT, &Wire,-1);

void setup() {
  Serial.begin(115200);
  //SDA，SCL引脚
  Wire.begin(13,18);
  //OLED初始化
  OLED.begin(SSD1306_SWITCHCAPVCC,0x3C);
  // OLED清除显示
  OLED.clearDisplay();
  // 设置光标位置
  OLED.setCursor(1, 1);
  // 设置文本颜色
  OLED.setTextColor(SSD1306_WHITE);
  // 设置字体大小
  OLED.setTextSize(2);
  // 显示字符
  OLED.println("Lars you are no good alone");

  // 显示内容
  OLED.display();
}

void loop() {
  // put your main code here, to run repeatedly:
}
