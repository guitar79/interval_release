// GS-interval_reliase
// REQUIRES 6~12V betary
// ----------------------------------------------------------------------------------------------------------
// FIRMWARE CHANGE LOG
// (2020. 1. 4) Ver. 0.1 기초 동작 시작
// ----------------------------------------------------------------------------------------------------------
#include <U8glib.h>
U8GLIB_SSD1306_128X64 u8g(U8G_I2C_OPT_NONE|U8G_I2C_OPT_DEV_0);  // I2C / TWI 

// 변수 설정
short subm = 0;
short menu = 1;
short power = 1;

// interval_relaese pins
#define shutter1 5
#define shutter2 6

//button pins
#define UPpin 8
#define DOWNpin 9
#define RIGHTpin 7
#define LEFTpin 10
//about button switch
short S[4]={0}; short now[4]={1}; short was[4]={0};

//
int _resetPosition = 0;

String inputString = "";

short val_shutterspeed_ms = 100;
short val_interval_ms = 100;
int shooting = 0 ;

void setup() {
  Serial.begin(115200);
  Serial.println("GS-interval_release#");
  U8G_start();
  pinMode(LED_BUILTIN, OUTPUT);
  // button pins
  pinMode(UPpin,INPUT_PULLUP);
  pinMode(DOWNpin,INPUT_PULLUP);
  pinMode(RIGHTpin,INPUT_PULLUP);
  pinMode(LEFTpin,INPUT_PULLUP);
  draw();
}

void loop() {
  buttonRead();
  RunRelease(); 
}

void RunRelease() {
  pinMode(shutter1, OUTPUT); pinMode(shutter2, OUTPUT);
  digitalWrite(shutter1, HIGH); digitalWrite(shutter2, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(val_shutterspeed_ms);                       // wait for a second
  digitalWrite(shutter1, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(shutter2, LOW);   // turn the LED on (HIGH is the voltage level)
  delay(val_interval_ms); // wait for a second
  shooting++;
  Serial.print("Shootint #: ");
  Serial.print(shooting);
  Serial.print("    during time : ");
  Serial.println(millis());
}
//Judge buttons
void controljudge(){
  now[0]=digitalRead(UPpin);
  now[1]=digitalRead(DOWNpin);
  now[2]=digitalRead(RIGHTpin);
  now[3]=digitalRead(LEFTpin);
  for(int i=0; i<4; i++)
  {
    if(now[i] != was[i] && now[i] == 0) S[i]=1;
    else S[i] = 0;
    was[i] = now[i];
  }
}

void buttonRead(){
  controljudge();
  if(subm != 2)
    {
      if(S[2]) subm++;
      else if(S[3]) subm = 0;
      
      if(S[0]&&menu>1) menu--;
      else if(S[1]&&menu<2) menu++;
    }
  else
    {
      switch(menu)
    {
      case 1: // SHUTTER SPEED CONTROL
        //ShutterSpeedControl()
        break;
      case 2: // INTERVAL CONTROL
        //IntervalControl();
        break;
      case 3: // REPEAT TIME CONTROL
        //RepeatTimeControl();
        break;
    }
  }
}

void U8G_start()
  {
    u8g.setFont(u8g_font_5x8);
    u8g.setColorIndex(1);
    u8g.setFontPosTop();
  }

void draw()
  {
    u8g.firstPage();   
    do {
            u8g.setFont(u8g_font_unifont); u8g.setFontPosTop();
            u8g.drawStr(20,0,"Setting");
            u8g.drawStr(0,28,"SHUTTER : ");
            u8g.setPrintPos(90,28);
            u8g.print(val_shutterspeed_ms);
            u8g.drawStr(0,50,"INTERVAL:");
            u8g.setPrintPos(90,50);
            u8g.print(val_interval_ms);
        } 
      while( u8g.nextPage() );
  }
