boolean ShellRunning = true;

void shell(String user, String pass) {
  //Serial.println(SplitString("echo I LIKE TURTLES",' ')[2]);
  SendEscCode(ESC_RESET);
  ClearScreen();
  CursorPos(0, 0);
  if (user == "" and pass == "") {
    user = Prompt("Username: ", 0, 0, 0);
    Serial.println("");
    pass = Prompt("Password: ", 0, '*', 0);
    Serial.println("");
    Session(user, "arduino");
  }
  else {
    Session(user, "arduino");
  }
}

void Session(String u, String cn) {
  SetForeColor(COLOR_CYAN);
  Serial.println("-- ArduinOS Shell --");
  Serial.println();
  int XPos = u.length() + cn.length() + 2;

  while (ShellRunning) {
    Printcmd(u, cn);
    String command = Prompt("", 0, 0, 0);
    Serial.println("");
    RunCommand(command, u);
    command = "";
  }
}

int RunCommand(String cmd, String u) {
  if (cmd == "") {

  }
  else if (cmd == "install") {
    install();
  }
  else if (cmd == "exit") {
    ShellRunning = false;
  }
  else if (cmd == "help") {
    ShowHelp();
  }
  else if (cmd.startsWith("echo")) {
    Serial.println(cmd.substring(5, cmd.length()));
  }
  else {
    SetForeColor(COLOR_RED);
    Serial.print("Command not found: '");
    Serial.print(cmd);
    Serial.println("'");
  }
  return 0;
}

void Printcmd(String u, String cn) {
  SetForeColor(COLOR_YELLOW);
  Serial.print(u);
  SetForeColor(COLOR_WHITE);
  Serial.print("@");
  SetForeColor(COLOR_MAGENTA);
  Serial.print(cn);
  Serial.print("# ");
  SetForeColor(COLOR_WHITE);
}

