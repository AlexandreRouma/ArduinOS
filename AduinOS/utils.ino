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

int CountChar(String str, char c){
  int rtn = 0;
  for (int i = 0; i < str.length(); i++){
    if (str.charAt(i) == c){
      rtn++;
    }
  }
  return rtn;
}

String GetElement(String data, char separator, int index){
  int found = 0;
  int strIndex[] = {0, -1};
  int maxIndex = data.length()-1;

  for(int i=0; i<=maxIndex && found<=index; i++){
    if(data.charAt(i)==separator || i==maxIndex){
        found++;
        strIndex[0] = strIndex[1]+1;
        strIndex[1] = (i == maxIndex) ? i+1 : i;
    }
  }

  return found>index ? data.substring(strIndex[0], strIndex[1]) : "";
}
