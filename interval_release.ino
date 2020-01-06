// GS-interval_reliase
// REQUIRES 6~12V battery or 5V USB battery
// ----------------------------------------------------------------------------------------------------------
// FIRMWARE CHANGE LOG
// (2020. 1. 4) Ver. 0.1 기초 동작 시작
// created by guitar79@naver.com
// CC BY-NC-SA
// ----------------------------------------------------------------------------------------------------------

String firmware_Name = "GS Release" ;
String firmware_Ver = "0.1" ;

void setup() 
  {
    Serial.begin(115200);
    Serial.print(firmware_Name);
    Serial.print(": ");
    Serial.println(firmware_Ver);
    U8G_start();
    pinset();
    draw();
    DelayBegin(); 
  }

void loop() 
  {
    ButtonAction();
  }
