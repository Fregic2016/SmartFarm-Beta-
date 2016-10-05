
void setup()
{
  Serial.begin(9600);
  pinMode(10, OUTPUT); //10번핀으로 컨트롤
  
  
}
void loop()
{
  int i;
  if(Serial.available())
  {
    i = Serial.read(); // 시리얼포트에서 읽어들이는 값 확인
  }
  if(i == 49)
  {
  digitalWrite(10,1); // 전류 흘려보냄
  }
  if(i== 50){
  digitalWrite(10,0); // 전류 차단함
  }
  Serial.println(i);
  delay(500);
  
  
}

