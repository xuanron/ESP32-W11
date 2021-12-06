#include <BluetoothSerial.h>
#define led_pin 13
BluetoothSerial BT;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  BT.begin("Galaxy A71");//請改名
  pinMode(led_pin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  while (BT.available()) {
    //讀取藍芽資料
    String BTdata=BT.readString();
    if( BTdata=="LED ON"){
    
      digitalWrite(led_pin,HIGH);
    }
      if( BTdata=="LED OFF"){
     
      digitalWrite(led_pin,LOW);
    }
    
    //顯示在序列視窗
    Serial.println(BTdata);
  }
  delay(1);
}
