#include <DHT11.h>    //라이브러리 불러옴
int pin=2;            //디지털 2에 연결
DHT11 dht11(pin);        
void setup()
{
   Serial.begin(9600); 
}
 
void loop()
{
  int err;
  float temp, humi;
  if((err=dht11.read(humi, temp))==0) //온도, 습도 읽어와서 표시
  {
    Serial.print("temperature:");
    Serial.print(temp);
    Serial.print(" humidity:");
    Serial.print(humi);
    Serial.println();
  }
  else                                //에러일 경우 처리 (이 명령문 쓰지 않으면 컴파일 x)
  {
    Serial.println();
    Serial.print("Error No :");
    Serial.print(err);
    Serial.println();    
  }
  delay(1000);                        //1초마다 측정
}

