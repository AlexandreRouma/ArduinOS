String Prompt(String cl, int XPos, char pcar, int ll) {
  Serial.print(cl);
  boolean Prompting = true;
  String data;
  int MinXPos = XPos;
  while (Prompting) {
    if (Serial.available()) {
      char c = Serial.read();
      switch (c) {
        case '\x0D':
          Prompting = false;
          return data;
          break;
        case '\x7F':
          if (XPos > MinXPos) {
            data = data.substring(0, data.length() - 1);
            Serial.write('\x7F');
            XPos--;
          }
          break;
        default:
          if (data.length() < ll or ll == 0) {
            if (pcar == 0) {
              Serial.write(c);
            }
            else {
              Serial.write(pcar);
            }
            data = data + c;
            XPos++;
            break;
          }
      }
    }
  }
  return "";
}
