//https://wak-tech.com/archives/742

#include "BluetoothSerial.h"
BluetoothSerial SerialBT;

//受け取った信号の格納
String recv;
int i, start_time;
int flag = 1;
//使用するピンのアナログピン番号を指定
const int PinFan = A19; //26pin Channel0

void setup() {
  //Bluetoothの設定
  Serial.begin(115200);
  SerialBT.begin("esp32_kuma");
  
  //pwmの設定．最初の引数がchannel，次が周波数，最後が解像度(ここでは8bit = 256段階)
  ledcSetup(0,12800,8);

  //ピンをチャンネルに接続
  ledcAttachPin(PinFan,0);
}

void loop() {
  static uint8_t fan = 0;
  static int diff = 1;
  ledcWrite(0, fan);
  
  if(Serial.available() > 0){
    recv = Serial.read();
    i = recv.toInt();
  }
  if(i == 1){
    if (fan == 0) {
     diff = 1;
    } else if (fan == 255) {
     diff = -1;
   }
 
    fan += diff;
    SerialBT.println(fan);
  //遅延を遅くすればゆっくり明るさが変わるようになる
    delay(100);
  }
  else if(i == 2){
    fan = 255;
    SerialBT.println(fan);
  }
  else if (i == 0){
    fan = 0; 
    SerialBT.println(fan);
  }
//  if(i == 0){
//    ledcWrite(0,0);
//  } else if(i == 1){
//    //ledcWrite(0,255);   
//    //ledcWrite(0,255);
//    //vTaskDelay(2000);
//    //ledcWrite(0,0);
//    //i = 0;
//    
//    if (flag == 1){
//      //vTaskDelay(2000);
//      start_time = millis();
//      flag = 0;
//      
//      
//    } 
//    ledcWrite(0,255);   
//    if((millis() - start_time) >= 2000 and flag==0){
//      ledcWrite(0,0);
//      i = 0;
//      start_time = 0;
//      flag = 1;
//      //vTaskDelay(1500);
//      
//    }
//    
//  }


  
}
