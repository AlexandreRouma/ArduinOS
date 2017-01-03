void SendEscCode(String code) {
  Serial.print("\x1B[");
  Serial.print(code);
}

void FillScreen(String color) {
  SetBackColor(COLOR_BLUE);
  for (int i = 0; i < SHELL_WIDTH * SHELL_HEIGHT; i++) {
    Serial.write(' ');
  }
}

void FillRect(int xx, int yy, int w, int h, String color) {
  SetBackColor(color);
  for (int y = yy; y <= h + yy; y++) {
    CursorPos(xx, y);
    for (int x = xx; x <= w + xx; x++) {
      Serial.write(' ');
    }
  }
}

void ClearScreen() {
  SendEscCode(ESC_CLR_SCREEN);
}

void SetForeColor(String color) {
  Serial.print("\x1B[3");
  Serial.print(color);
}

void SetBackColor(String color) {
  Serial.print("\x1B[4");
  Serial.print(color);
}

void ClearLine(int l) {
  Serial.print("\x1B[");
  Serial.print(l);
  Serial.print("K");
}

void ScrollUP(int n) {
  Serial.print("\x1B[");
  Serial.print(n);
  Serial.print("S");
}

void ScrollDown(int n) {
  Serial.print("\x1B[");
  Serial.print(n);
  Serial.print("T");
}

void CursorUP(int n) {
  Serial.print("\x1B[");
  Serial.print(n);
  Serial.print("A");
}

void CursorDOWN(int n) {
  Serial.print("\x1B[");
  Serial.print(n);
  Serial.print("B");
}

void CursorFORWOARD(int n) {
  Serial.print("\x1B[");
  Serial.print(n);
  Serial.print("C");
}

void CursorBACK(int n) {
  Serial.print("\x1B[");
  Serial.print(n);
  Serial.print("D");
}

void CursorPos(int x, int y) {
  Serial.print("\x1B[");
  Serial.print(y);
  Serial.print(";");
  Serial.print(x);
  Serial.print("H");
}
