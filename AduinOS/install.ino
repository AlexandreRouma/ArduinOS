String Username;
String Password;
String IP;
String Mac;

void install() {
  install_CreateUser();
  install_network();
  SendEscCode(ESC_RESET);
  ClearScreen();
  CursorPos(0, 0);
  Serial.println(Username);
  Serial.println(Password);
  Serial.println(IP);
  Serial.println(Mac);
  /*
  EEPROM.write(0, 0xDA);
  EEPROM.write(1, 0xB0);
  while (!Serial.available());
  CursorPos(0, SHELL_HEIGHT - 1);
  Serial.write("Please reset Arduino...");
  while (1);
  */
}

void OKNormal(int x, int y){
  CursorPos(x, y);
  SetBackColor(COLOR_WHITE);
  SetForeColor(COLOR_RED);
  Serial.write("  OK  ");
  SetBackColor(COLOR_BLUE);
  SetForeColor(COLOR_WHITE);
  CursorPos(x, y);
}

void OKSelected(int x, int y){
  CursorPos(x, y);
  SetBackColor(COLOR_GREEN);
  SetForeColor(COLOR_RED);
  Serial.write("  OK  ");
  SetBackColor(COLOR_BLUE);
  SetForeColor(COLOR_WHITE);
  CursorPos(x, y);
}
