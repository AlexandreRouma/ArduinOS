void install_CreateUser() {
MenuStart:
  SendEscCode(ESC_RESET);
  ClearScreen();
  CursorPos(0, 0);
  SetBackColor(COLOR_BLUE);
  FillScreen(COLOR_BLUE);
  CursorPos(33, 0);
  Serial.println("ArduinOS Setup");

  // >-- Create User Menu --<

  FillRect(21, 9, 40, 9, COLOR_BLACK);
  FillRect(20, 8, 40, 9, COLOR_RED);
  SetForeColor(COLOR_RED);
  SetBackColor(COLOR_WHITE);
  CursorPos(34, 8);
  Serial.write(" Create user ");
  SetForeColor(COLOR_WHITE);
  SetBackColor(COLOR_RED);
  CursorPos(21, 10);
  Serial.write("Username:");
  CursorPos(21, 12);
  Serial.write("Password:");
  CursorPos(21, 14);
  Serial.write("Confirme:");
  CursorPos(37, 16);
  SetBackColor(COLOR_WHITE);
  SetForeColor(COLOR_RED);
  Serial.write("  OK  ");
  SetBackColor(COLOR_BLUE);
  SetForeColor(COLOR_WHITE);
  CursorPos(31, 10);
  Serial.write("               ");
  CursorPos(31, 12);
  Serial.write("               ");
  CursorPos(31, 14);
  Serial.write("               ");
  CursorPos(31, 10);
  int _usernameCXPos = 31;
  int _passwordCXPos = 31;
  int ConfirmeCXPos = 31;
  int SMenu = 0;
  boolean InMenu = true;
  String _username;
  String _password;
  String Confirme;
  while (InMenu) {
    if (Serial.available()) {
      String data;
      while (Serial.available()) {
        char c = Serial.read();
        data = data + c;
      }
      if (data == KEY_ARROW_UP) {
        if (SMenu > 0) {
          SMenu--;
        }
        switch (SMenu) {
          case 0:
            CursorPos(31 + _username.length(), 10);
            break;
          case 1:
            CursorPos(31 + _password.length(), 12);
            break;
          case 2:
            CursorPos(31 + Confirme.length(), 14);
            break;
        }
      }
      else if (data == KEY_ARROW_DOWN or data == KEY_ENTER) {
        if (SMenu < 2) {
          SMenu++;
        }
        switch (SMenu) {
          case 0:
            CursorPos(31 + _username.length(), 10);
            break;
          case 1:
            CursorPos(31 + _password.length(), 12);
            break;
          case 2:
            CursorPos(31 + Confirme.length(), 14);
            break;
        }
      }
      else if (data == KEY_ARROW_LEFT) {
        Serial.print(_username);
        Serial.print(" - ");
        Serial.print(_password);
      }
      else if (data == KEY_ARROW_RIGHT) {

      }
      else if (data == "\x7F") {
        switch (SMenu) {
          case 0:
            if (_usernameCXPos > 31) {
              _username = _username.substring(0, _username.length() - 1);
              _usernameCXPos--;
              Serial.print(data);
            }
            break;
          case 1:
            if (_passwordCXPos > 31) {
              _password = _password.substring(0, _password.length() - 1);
              _passwordCXPos--;
              Serial.print(data);
            }
            break;
          case 2:
            if (ConfirmeCXPos > 31) {
              Confirme = Confirme.substring(0, Confirme.length() - 1);
              ConfirmeCXPos--;
              Serial.print(data);
            }
            break;
        }
      }
      else {
        switch (SMenu) {
          case 0:
            if (_usernameCXPos < 46) {
              _username = _username + data;
              _usernameCXPos++;
              Serial.print(data);
            }
            break;
          case 1:
            if (_passwordCXPos < 46) {
              _password = _password + data;
              _passwordCXPos++;
              Serial.print("*");
            }
            break;
          case 2:
            if (ConfirmeCXPos < 46) {
              Confirme = Confirme + data;
              ConfirmeCXPos++;
              Serial.print("*");
            }
            break;
        }
        /*
          for (int i = 0; i < data.length(); i++){
          Serial.print(data.charAt(i),DEC);
          Serial.print("-");
          }
        */
      }
    }
  }
}
