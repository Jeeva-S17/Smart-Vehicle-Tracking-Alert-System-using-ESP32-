#include <WiFi.h>
#include <ThingSpeak.h>
#include <HardwareSerial.h>

HardwareSerial ArduinoSerial(2);
HardwareSerial GSM(1);

const char* ssid = "AdventureLearning_5G";
const char* password = "Adv@cbe123";

unsigned long channelID = 3421631;
const char* writeAPIKey = "1F9ZUFA1W3BXRRPY";

WiFiClient client;

String phoneNumber = "+918807271185";

bool smsSent = false;

void setup() {

  Serial.begin(115200);

  ArduinoSerial.begin(9600, SERIAL_8N1, 16, 17);   
  GSM.begin(9600, SERIAL_8N1, 4, 5);               

  delay(3000);

  GSM.println("AT");
  delay(1000);
  GSM.println("AT+CMGF=1");
  delay(1000);

  WiFi.begin(ssid, password);

  Serial.print("Connecting WiFi");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nWiFi Connected");

  ThingSpeak.begin(client);
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

        GSM.println("AT+CMGF=1");
        delay(1000);

        GSM.print("AT+CMGS=\"");
        GSM.print(phoneNumber);
        GSM.println("\"");

        delay(2000);

        GSM.println("ALERT");
        GSM.println("Motion Detected");
        GSM.print("Heart Value : ");
        GSM.println(heart);

        GSM.write(26);

        delay(5000);

        smsSent = true;
      }

      if (pir == 0)
        smsSent = false;

      ThingSpeak.setField(1, pir);
      ThingSpeak.setField(2, heart);
      ThingSpeak.setField(3, smsSent ? 1 : 0);

      int x = ThingSpeak.writeFields(channelID, writeAPIKey);

      if (x == 200)
        Serial.println("ThingSpeak Updated");
      else
        Serial.println("Upload Failed");

      delay(16000);   
    }
  }
}