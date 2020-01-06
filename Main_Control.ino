// interval_relaese pins
#define shutter1 5
#define shutter2 6

//아래 변수로 설정을 합니다.
short val_delay_begin_ms = 1000;  //초기 DELAY 값(ms)
short val_shutterspeed_ms = 100;  //셔터를 누르는 시간 (ms)
short val_interval_ms = 100; //셔터를 누르고 나서 다음 셔터 누를때까지 시간 간격 (ms)
int shooting = 0 ;

void DelayBegin() 
  {
    Serial.print("Delay for beginning #: ");
    Serial.println(val_delay_begin_ms);
    delay(val_delay_begin_ms);                       // wait for a second
  }

void RunRelease() 
  {
    pinMode(shutter1, OUTPUT); pinMode(shutter2, OUTPUT);
    digitalWrite(shutter1, HIGH); digitalWrite(shutter2, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(val_shutterspeed_ms);                       // wait for a second
    digitalWrite(shutter1, LOW); digitalWrite(shutter2, LOW);   // turn the LED on (HIGH is the voltage level)
    delay(val_interval_ms); // wait for a second
    shooting++;
    Serial.print("Shooting #: ");
    Serial.print(shooting);
    Serial.print("    running time : ");
    Serial.println(millis());
  }

void WaitForRun() 
  {
    Serial.print("Shooting #: ");
    Serial.print(shooting);
    Serial.print("    Waiting for running : ");
    Serial.println(millis());
  }
