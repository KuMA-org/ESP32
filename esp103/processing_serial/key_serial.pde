//processing側のコード
import processing.serial.*;

Serial serial;
String data[];
int a;
void setup() 
{
  printArray(Serial.list());
  //serial = new Serial(this, "COM3", 115200);  
  serial = new Serial(this, Serial.list()[0], 115200); 
  
  serial.bufferUntil('\n');
  //size(300, 300);
  //background(0, 0, 0);
  //serial.write(1);
  
 
}

void draw()
{
  //fill(255);
  //noStroke();
  //rect(0, 0, width, height);
  //fill(0);
  //textSize(height*0.10);
  //textAlign(LEFT);

 
}

void keyPressed() {
  if (key == CODED) {      // コード化されているキーが押された
    if (keyCode == UP) {    // キーコードを判定
        serial.write(1);
       background(255);
    } else if (keyCode == DOWN) {
       serial.write(2);
       background(0);
    }
  }
}
