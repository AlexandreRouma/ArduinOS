void install_network() {
  SendEscCode(ESC_RESET);
  ClearScreen();
  CursorPos(0, 0);
  SetBackColor(COLOR_BLUE);
  FillScreen(COLOR_BLUE);
  CursorPos(33, 0);
  Serial.println("ArduinOS Setup");
  FillRect(21, 9, 40, 9, COLOR_BLACK);
  FillRect(20, 8, 40, 9, COLOR_RED);
  SetForeColor(COLOR_RED);
  SetBackColor(COLOR_WHITE);
  CursorPos(30, 8);
  Serial.write(" Network configuration ");
  SetForeColor(COLOR_WHITE);
  SetBackColor(COLOR_RED);
  CursorPos(21, 10);
  Serial.write("IP:");
  CursorPos(21, 12);
  Serial.write("Mac:");
  OKNormal();
  CursorPos(31, 10);
  Serial.write("               ");
  CursorPos(31, 12);
  Serial.write("                   ");
  CursorPos(31, 10);
  int _ipCXPos = 31;
  int _macCXPos = 31;
  int SMenu = 0;
  boolean InMenu = true;
  String _ip;
  String _mac;
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
            CursorPos(31 + _ip.length(), 10);
            break;
          case 1:
            CursorPos(31 + _mac.length(), 12);
            break;
          case 2:
            OKSelected();
            break;
        }
      }
      else if (data == KEY_ARROW_DOWN or data == KEY_ENTER) {
        if (SMenu < 2) {
          SMenu++;
        }
        else {
          if (data == KEY_ENTER){
            if (_ip.length() > 0 and _mac.length() == 17 and CountChar(_mac,':')){
              IP = _ip;
              Mac = _mac;
              return;
            }
            else {
              CursorPos(0,SHELL_HEIGHT - 1);
              if (_ip.length() == 0){
                Prompt("Please fill in IP",0,'\x07',0);
              }
              else {
                Prompt("Invalid mac",0,'\x07',0);
              }
              ClearLine(2);
            }
          }
        }
        switch (SMenu) {
          case 0:
            CursorPos(31 + _ip.length(), 10);
            break;
          case 1:
            CursorPos(31 + _mac.length(), 12);
            break;
          case 2:
            OKSelected();
            break;
        }
      }
      else if (data == KEY_ARROW_LEFT) {
        
      }
      else if (data == KEY_ARROW_RIGHT) {

      }
      else if (data == "\x7F") {
        switch (SMenu) {
          case 0:
            if (_ipCXPos > 31) {
              _ip = _ip.substring(0, _ip.length() - 1);
              _ipCXPos--;
              Serial.print(data);
            }
            break;
          case 1:
            if (_macCXPos > 31) {
              _mac = _mac.substring(0, _mac.length() - 1);
              _macCXPos--;
              Serial.print(data);
            }
            break;
        }
      }
      else {
        switch (SMenu) {
          case 0:
            if (_ipCXPos < 46) {
              _ip = _ip + data;
              _ipCXPos++;
              Serial.print(data);
            }
            break;
          case 1:
            if (_macCXPos < 48) {
              _mac = _mac + data;
              _macCXPos++;
              Serial.print(data);
            }
            break;
        }
      }
    }
  }
}
