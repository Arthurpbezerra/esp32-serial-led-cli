#include <Arduino.h>

#define LED_RED 2
#define LED_BLUE 4


void processInput(char* s);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(LED_RED, OUTPUT);
  pinMode(LED_BLUE, OUTPUT);
  delay(1000); // Wait for Serial to initialize
  Serial.setTimeout(10000);
}

void loop() {
  static char buffer[32];
  static int pos = 0;
    while(Serial.available() > 0) {
      char c = Serial.read();

      if(c =='\r' || c == '\n') {
        if(pos > 0) {
          buffer[pos] = '\0'; 
          processInput(buffer);

          pos = 0;
        }
      }
      else if (pos <sizeof(buffer) - 1) {
        buffer[pos] = tolower(c);
        pos++;
      }
      
    }


}
void processInput(char* s){
  char* device = strtok(s, " ");
  char* action = strtok(NULL, " ");
  int pin = -1;
  if (strcmp(device, "blue") == 0) {
    pin = LED_BLUE;
  } else if (strcmp(device, "red") == 0) {
    pin = LED_RED;
  } 
  if (pin != -1) {
    if(strcmp(action,"on") == 0){
      digitalWrite(pin,HIGH);
      Serial.printf("Led %s ligada\r\n",device);
    }
    else if(strcmp(action,"off") == 0){
      digitalWrite(pin,LOW);
      Serial.printf("Led %s desligada\r\n",device);
    }
    else {
      Serial.println("Action nao reconhecida");
    }
  }
  else {
      Serial.println("Dispositivo nao reconhecido");
    }
  
}
