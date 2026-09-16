#include <WiFi.h>
#include <ThingESP.h>

ThingESP32 thing("Jeeva23", "IoTproject23", "IoTproject");

int LED = 4;
int Motor = 5;
//int Buzzer = D4;


unsigned long previousMillis = 0;
const long INTERVAL = 6000;  

void setup()
{
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  pinMode(Motor, OUTPUT);
  //pinMode(Buzzer, OUTPUT);
  thing.SetWiFi("Kavithaye ", "priyapriya");
  thing.initDevice();
}


String HandleResponse(String query)
{
  if (query == "led on") {
    digitalWrite(LED, 1);
    return "Done: LED Turned ON";
  }

  else if (query == "led off") {
    digitalWrite(LED, 0);
    return "Done: LED Turned OFF";
  }
  

  else if (query == "led status"){ 
    return digitalRead(LED) ? "LED is OFF" : "LED is ON";
  // return "Your query was invalid..";
  }

   else if (query == "motor on") {
    digitalWrite(Motor, 1);
    return "Done: motor Turned ON";
  }

  else if (query == "motor off") {
    digitalWrite(Motor, 0);
    return "Done: motor Turned OFF";
  }
  

  else if (query == "motor status"){ 
    return digitalRead(Motor) ? "motor is OFF" : "motor is ON";
   //return "Your query was invalid..";
  }
  else
  {
    return "Your query was invalid..";
  }

}


void loop()
{
  thing.Handle();

}