#include"rfid1.h"
RFID1 rfid;
uchar serNum[5];
uchar serNum2[5];
#include<Servo.h>
Servo myservo;

void setup() {
  Serial.begin(9600);
  rfid.begin(7, 5, 4, 3, 6, 2);
  delay(100);
  rfid.init();
  myservo.attach(9);
  myservo.write(0);
  delay(1000);
}

void loop() {
  uchar status;
  uchar str[MAX_LEN];

  status = rfid.request(PICC_REQIDL, str);
  if (status != MI_OK)
  {
    return;
  }
  rfid.showCardType(str);
  status = rfid.anticoll(str);
  if (status == MI_OK)
  {
    Serial.print("The card's number is:");
    memcpy(serNum, str, 5); //5这个数字是最大识别用户数量
    rfid.showCardID(serNum);
    Serial.println();
    Serial.println();
  }
  delay(100);
  rfid.halt();
  uchar*id = serNum;
  if (id[0] == 0x59 && id[1] == 0x07 && id[2] == 0x2F && id[3] == 0xB7 )
  {
    myservo.write(0);
    delay(100);
    myservo.write(90);
    delay(8000);
    myservo.write(0);
  }
  else if (id[0] == 0x9A && id[1] == 0x58 && id[2] == 0xF9 && id[3] == 0xBF )
  {
    myservo.write(0);
    delay(100);
    myservo.write(90);
    delay(8000);
    myservo.write(0);
  }
  else if (id[0] == 0x8C && id[1] == 0x79 && id[2] == 0x4C && id[3] == 0x18 )
  {
    myservo.write(0);
    delay(100);
    myservo.write(90);
    delay(8000);
    myservo.write(0);
  }
  else if (id[0] == 0x59 && id[1] == 0x9E && id[2] == 0x35 && id[3] == 0xB2 )
  {
    myservo.write(0);
    delay(100);
    myservo.write(90);
    delay(8000);
    myservo.write(0);
  }
  else if (id[0] == 0x03 && id[1] == 0x1F && id[2] == 0x3B && id[3] == 0x02 )
  {
    myservo.write(0);
    delay(100);
    myservo.write(90);
    delay(8000);
    myservo.write(0);
  }
  serNum[0] = serNum2[0];
  serNum[1] = serNum2[1];
}
