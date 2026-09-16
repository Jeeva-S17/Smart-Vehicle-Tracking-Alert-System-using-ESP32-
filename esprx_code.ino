#include <HardwareSerial.h>

HardwareSerial ArduinoSerial(2);
HardwareSerial GSM(1);

String phoneNumber = "+918807271185";

bool smsSent = false;

void setup() {

  Serial.begin(115200);

 
  ArduinoSerial.begin(9600, SERIAL_8N1, 16, 17);

  
  GSM.begin(9600, SERIAL_8N1, 4, 5);

  delay(5000);

  GSM.println("AT");
  delay(1000);

  GSM.println("AT+CMGF=1");
  delay(1000);

  Serial.println("ESP32 Ready...");
}

void loop() {

  if (ArduinoSerial.available()) {

    String data = ArduinoSerial.readStringUntil('\n');
    data.trim();

    int comma = data.indexOf(',');

    if (comma > 0) {

      int pir = data.substring(0, comma).toInt();
      int heart = data.substring(comma + 1).toInt();

      Serial.print("PIR : ");
      Serial.println(pir);

      Serial.print("Heart : ");
      Serial.println(heart);

      
      if (pir == 1 && !smsSent) {

        sendSMS(heart);
        smsSent = true;
      }

      
      if (pir == 0) {
        smsSent = false;
      }
    }
  }
}

void sendSMS(int heart) {

  GSM.println("AT+CMGF=1");
  delay(1000);

  GSM.print("AT+CMGS=\"");
  GSM.print(phoneNumber);
  GSM.println("\"");

  delay(2000);

  GSM.println("***** ALERT *****");
  GSM.println("Motion Detected");
  GSM.print("Heart Value : ");
  GSM.println(heart);

  delay(1000);

  GSM.write(26);     

  delay(5000);

  Serial.println("SMS Sent Successfully");
}