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
