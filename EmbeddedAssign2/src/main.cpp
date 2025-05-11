#include <Arduino.h>

// 定义LED引脚
const int led1Pin = 23;
const int led2Pin = 12;

void setup() {
  // 初始化串口通信，波特率为9600
  Serial.begin(9600);
  // 设置LED引脚为输出模式
  pinMode(led1Pin, OUTPUT);  
  pinMode(led2Pin, OUTPUT);
  // 初始时关闭所有LED灯
  digitalWrite(led1Pin, LOW);
  digitalWrite(led2Pin, LOW);
}

void loop() {
  if (Serial.available() > 0) {
    // 读取串口接收到的字符串
    String command = Serial.readStringUntil('\n');
    // 去除字符串首尾的空白字符
    command.trim();

    if (command == "1") {
      // 点亮LED1
      digitalWrite(led1Pin, HIGH);
      Serial.println("LED1亮");
    } else if (command == "2") {
      // 点亮LED2
      digitalWrite(led2Pin, HIGH);
      Serial.println("LED2亮");
    } else if (command == "3") {
      // 关闭LED1
      digitalWrite(led1Pin, LOW);
      Serial.println("LED1灭");
    } else if (command == "4") {
      // 关闭LED2
      digitalWrite(led2Pin, LOW);
      Serial.println("LED2灭");
    } else {
      // 无效指令，不执行动作
      Serial.println("无效指令");
    }
  }
}    