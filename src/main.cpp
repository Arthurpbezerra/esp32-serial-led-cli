#include <Arduino.h>
#include "app/app_state.h"
#include "cli/cli.h"
#include "app/pins.h"

static AppState appState;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(LED_RED, OUTPUT);
  pinMode(LED_BLUE, OUTPUT);
  delay(1000); // Wait for Serial to initialize
  Serial.setTimeout(10000);
  appState.bootMs = millis();
}

void loop() {
  cliPoll(appState);
}