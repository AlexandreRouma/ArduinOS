String Username;
String Password;

void install() {
  install_CreateUser();

  EEPROM.write(0, 0xDA);
  EEPROM.write(1, 0xB0);
  while (!Serial.available());
  CursorPos(0, SHELL_HEIGHT - 1);
  Serial.write("Please reset Arduino...");
  while (1);
}
