#include "commands.h"
#include <string.h>
#include "app/pins.h"

static int resolveLedPin(const char* device) {
    if (strcmp(device, "red") == 0) return LED_RED;
    if (strcmp(device, "blue") == 0) return LED_BLUE;
    return -1;
}
void executeCommand(char* line, AppState& app) {
  (void)app;
  char* device = strtok(line, " ");
  
  if(device == nullptr){
    return;
  }
  if(strcmp(device,"help") == 0){
    Serial.println("Comandos:");
    Serial.println("  help              lista esta ajuda");
    Serial.println("  uptime            Mostra tempo desde boot");
    Serial.println("  status            estado dos LEDs (red/blue)");
    Serial.println("  red on|off        controla LED vermelho");
    Serial.println("  blue on|off       controla LED azul");
    return;
  }
  if(strcmp(device,"uptime") == 0){
    uint32_t now = millis();

    Serial.printf("Uptime: %lu",(now - app.bootMs)/1000);
    return;
  }

  if (strcmp(device, "status") == 0) {
    Serial.printf("Status atual:\r\nLed 1: %s\r\nLed 2: %s\r\n", app.redOn ? "ON" : "OFF", app.blueOn ? "ON" : "OFF");
    return;
  }

  int pin = resolveLedPin(device);
  if (pin == -1) {
    Serial.println("Dispositivo nao reconhecido");
    return;
  }

  char* action = strtok(NULL, " ");
  if (action == nullptr){
    Serial.println("Uso: <red|blue> <on|off>");
    return;
  }

  if (strcmp(action, "on") == 0){
    digitalWrite(pin, HIGH);
    if (pin == LED_RED) app.redOn = true;
    if (pin == LED_BLUE) app.blueOn = true;
    Serial.printf("Led %s ligada\r\n", device);
  } else if (strcmp(action, "off") == 0) {
      digitalWrite(pin, LOW);
      if (pin == LED_RED) app.redOn = false;
      if (pin == LED_BLUE) app.blueOn = false;
      Serial.printf("Led %s desligada\r\n", device);
    } else {
      Serial.println("Action nao reconhecida");
    }
  
}