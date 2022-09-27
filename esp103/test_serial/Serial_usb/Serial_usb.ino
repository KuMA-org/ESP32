
#include "BluetoothSerial.h"
BluetoothSerial SerialBT;
String recv;
int i, start_time;
int flag = 1;

int a, give;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  SerialBT.begin("esp32_kuma");


}

void loop() {
  if (Serial.available() > 0) {
    recv = Serial.read();
    i = recv.toInt();
    
  }
  // put your main code here, to run repeatedly:
  //  Serial.write(10);
  // if (Serial.available() >=1)
  //  {
  //    a = Serial.read();
  //    Serial.print(a);
  //    give = a - 5;
  //    Serial.write(give);

  //  }
//    if (i == 10){
//      SerialBT.print("きじゃや\n");
//      
//    }
    SerialBT.print(i);
//  SerialBT.print("きじゃや\n");
  
  delay(500);

}
