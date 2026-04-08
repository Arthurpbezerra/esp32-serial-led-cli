#include "cli.h"
#include "commands.h"
#include <ctype.h>

void cliPoll(AppState& app) {
  static char buffer[32];
  static int pos = 0;

  while (Serial.available() > 0) {
    char c = Serial.read();

    if (c == '\r' || c == '\n') {
      if (pos > 0) {
        buffer[pos] = '\0';
        executeCommand(buffer, app);
        pos = 0;
      }
    } else if (pos < sizeof(buffer) - 1) {
      buffer[pos] = (char)tolower((unsigned char)c);
      pos++;
    }
  }
}
