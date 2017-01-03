//Putty Start Command: -serial COM15 -sercfg 115200,8,n,1,N

#include <EEPROM.h>
#include "esc_codes.h"

#define IOR             true  // Allways show install at startup
#define BAUD_RATE       115200  // Serial Baud Rate
#define SHELL_WIDTH     80      // Width of the shell
#define SHELL_HEIGHT    25      // Height of the shell

void setup() {
  Serial.begin(BAUD_RATE);
  SendEscCode(ESC_RESET);
  ClearScreen();
  CursorPos(0, 0);
  shell("", "");
  while (1);
  if (EEPROM.read(0) != 0xDA or EEPROM.read(1) != 0xB0 or IOR) {
    install();
  }
}

void loop() {
  ClearScreen();
  SetBackColor(COLOR_BLACK);
  CursorPos(28, 0);
  SetForeColor(COLOR_GREEN);
  Serial.print("INSTALLED SUCCESSFULLY");
  while (1);
}
