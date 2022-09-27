//processing側のコード
import processing.serial.*;

Serial serial;
String data[];
int a;
void setup() 
{
  serial = new Serial(this, "COM2", 115200);  
  serial.bufferUntil('\n');
  size(300, 300);
  background(0, 0, 0);
  serial.write(1);
 
}

void draw()
{
  fill(255);
  noStroke();
  rect(0, 0, width, height);
  fill(0);
  textSize(height*0.10);
  textAlign(LEFT);

 
}
void loop(){
   
}
//void serialEvent(Serial port)
//{
//  // シリアルポートからデータを受け取ったら
//  if (port.available() >=1) 
//  {
//    a = serial.read();
//    print(a);
//  }
//}
//void keyPressed() {
//  //if (key == CODED) {      // コード化されているキーが押された
//    if (keyCode == UP) {    // キーコードを判定
//       serial.write(1);
//    } else if (keyCode == '2') {
//       serial.write(2);
//    }
//  }
//}
