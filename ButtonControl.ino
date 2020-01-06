//button pins
#define UPpin A1
#define DOWNpin A2
#define RIGHTpin A3
#define LEFTpin A0

//about button switch
short S[4]={0}; 
short now[4]={1}; 
short was[4]={0};
short run_status = 0;
//설정된 핀번호 풀업저항으로 선언
void pinset() 
  {
    pinMode(UPpin,INPUT_PULLUP);
    pinMode(DOWNpin,INPUT_PULLUP);
    pinMode(RIGHTpin,INPUT_PULLUP);
    pinMode(LEFTpin,INPUT_PULLUP);
  }

void pinset1() 
  {
    pinMode(UPpin,INPUT);
    pinMode(DOWNpin,INPUT);
    pinMode(RIGHTpin,INPUT);
    pinMode(LEFTpin,INPUT);
  }

//버튼이 눌러진 상태 체크
void ButtonJudge()
  {
    now[0] = digitalRead(LEFTpin);
    now[1] = digitalRead(RIGHTpin);
    now[2] = digitalRead(UPpin);
    now[3] = digitalRead(DOWNpin);
    if(now[1] == 1 && run_status == 0) 
      run_status = 1; 
    else if  (now[0] == 1 && run_status == 1) 
      run_status = 0; 
    Serial.print("button status: "); 
    Serial.print(now[0]); 
    Serial.print(now[1]); 
    Serial.print(now[2]); 
    Serial.print(now[3]); 
    Serial.print("    "); 
    Serial.print("run status: "); 
    Serial.println(run_status); 
  }

void ButtonJudge1()
  {
    now[0] = digitalRead(LEFTpin);
    now[1] = digitalRead(RIGHTpin);
    now[2] = digitalRead(UPpin);
    now[3] = digitalRead(DOWNpin);
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
    switch (run_status) 
      {
        case 0:
          WaitForRun();
          break;
        case 1:
          RunRelease();
          break;
        default:
          WaitForRun();
          break;
      }
  }
