#include <Arduino.h>

#define LED_RED 2
#define LED_BLUE 4

String inputBuffer = "";
String destino = "";
String processInput(String s);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(LED_RED, OUTPUT);
  pinMode(LED_BLUE, OUTPUT);
  delay(1000); // Wait for Serial to initialize
  Serial.setTimeout(10000);
}

void loop() {
  
    while(Serial.available() > 0) {
      char c = Serial.read();
      c = tolower(c);
      if(c =='\r' || c == '\n') {
        if(inputBuffer.length() > 0) {
          destino = processInput(inputBuffer);

          inputBuffer = "";
        }
      }
      else {
        inputBuffer += c;
      }
      
    }

    if (destino == "blue on") {
      digitalWrite(LED_BLUE, HIGH);
    }
    else if(destino == "blue off") {
      digitalWrite(LED_BLUE, LOW);
    }
    else if(destino == "red on") {
      digitalWrite(LED_RED, HIGH);
    }
    else if(destino == "red off") {
      digitalWrite(LED_RED, LOW);
    }
   

    destino = "";

}
String processInput(String s){
  s.trim();
  Serial.println("Received input: " + s);
  return s;
}
