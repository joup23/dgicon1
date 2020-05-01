
// 업로드시 RX, TX핀을 제거하고 업로드

void setup() {
  pinMode(LED_BUILTIN, OUTPUT); //led1번 지정
  pinMode(2, OUTPUT);           //led2번 지정

//Begin Serial Monitor
  Serial.begin(9600); //블루투스 시리얼
  Serial.write("ESP8266 DEMO");
  Serial.println();            


  
}


void loop() {

  static boolean flag = true;


  if (Serial.available()) {     //수신된 데이터가 있다면
    char br = Serial.read();  //수신된 데이터를 읽어와 br이라는 변수에 저장


  switch(br){
      case '1' :  //br이 1이면 3초동안 0.5초 간격으로 led 2번이 깜빡임
        for(int i=0;i<3;i++){
        digitalWrite(2, HIGH);
        digitalWrite(LED_BUILTIN, LOW);
        delay(500);
        digitalWrite(2, HIGH);
        digitalWrite(LED_BUILTIN, HIGH);
        delay(500);
      }
      break;

      case '2' :     //br이 2이면 led 1번이 3초동안 깜빡인 다음 led 2번이 3초동안 깜빡임 
        for(int i=0;i<3;i++){
        digitalWrite(2, HIGH);
        digitalWrite(LED_BUILTIN, LOW);
        delay(3000);
        digitalWrite(2, HIGH);
        digitalWrite(LED_BUILTIN, HIGH);
        delay(3000);
      }
      break;

      case '3' :    //br이 3이면 led2번에 불이 들어옴
        digitalWrite(2, HIGH);
        digitalWrite(LED_BUILTIN, LOW);
        delay(30);
      break;

      case '4' :    
      {
        switch(flag){      
        case true:
          digitalWrite(2, HIGH);
          digitalWrite(LED_BUILTIN, LOW);
          flag=false;
          break;
        case false:
          digitalWrite(2, HIGH);
          digitalWrite(LED_BUILTIN, HIGH);
           flag=true;
           break;
      }
      break;
      }
      
      case '5' :      
        for(int i=0;i<3;i++){
        digitalWrite(2, HIGH);
        digitalWrite(LED_BUILTIN, LOW);
        delay(500);
        digitalWrite(2, LOW);
        digitalWrite(LED_BUILTIN, HIGH);
        delay(500);
      }
      digitalWrite(2, HIGH);
      digitalWrite(LED_BUILTIN, HIGH);
      break;
  
        case 'a' :
        digitalWrite(2, HIGH);
        digitalWrite(LED_BUILTIN, HIGH);
        break;
    }

  }

}
