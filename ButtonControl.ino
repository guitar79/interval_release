//button pins
#define UPpin 7
#define DOWNpin 8
#define RIGHTpin 9
#define LEFTpin 10

//about button switch
short S[4]={0}; 
short now[4]={1}; 
short was[4]={0};

//설정된 핀번호 풀업저항으로 선언
void pinset() 
  {
    pinMode(UPpin,INPUT_PULLUP);
    pinMode(DOWNpin,INPUT_PULLUP);
    pinMode(RIGHTpin,INPUT_PULLUP);
    pinMode(LEFTpin,INPUT_PULLUP);
  }

//버튼이 눌러진 상태 체크
void ButtonJudge()
  {
    now[0] = digitalRead(UPpin);
    now[1] = digitalRead(DOWNpin);
    now[2] = digitalRead(RIGHTpin);
    now[3] = digitalRead(LEFTpin);
    for(int i=0; i<4; i++)
      {
        if(now[i] != was[i] && now[i] == 0) 
          S[i] = 1; 
        else 
          S[i] = 0;
          was[i] = now[i];
      }
    Serial.print(now[0]); 
    Serial.print(now[1]); 
    Serial.print(now[2]); 
    Serial.print(now[3]); 
    Serial.print("    "); 
    Serial.print(S[0]); 
    Serial.print(S[1]); 
    Serial.print(S[2]); 
    Serial.println(S[3]);
  }

void ButtonAction()
  {
    ButtonJudge();
    if(S[2]) 
      RunRelease();
    else if(S[3]) 
      WaitForRun();
  }
