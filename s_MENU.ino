String ssid     = "old SSID";
String password = "old pwd";
String key      = "old key";

void setup() {
  delay(10);
  Serial.begin(115200);
  Serial.println("\033[2J\033[1;1H"); // clr scrn
  delay(500);
}

void loop() {
  Serial.println(" *** MENU ***");
  Serial.println(" 1. Change password.");
  Serial.println(" 2. Change SSID.");
  Serial.println(" 3. Change API key.");
  Serial.println(" 4. Show all values.");
  Serial.println(" 5. Restart module.");

  String tmp_st = read_serial();
  int temp_i = tmp_st.toInt();

  switch ( temp_i ) {
    case 1:
      Serial.println("\033[2J\033[1;1H"); // clr scrn
      input_prompt(password, "password", 8);
      break;
    case 2:
      Serial.println("\033[2J\033[1;1H"); // clr scrn
      input_prompt(ssid, "SSID", 4);
      break;
    case 3:
      Serial.println("\033[2J\033[1;1H"); // clr scrn
      input_prompt(key, "API key", 12);
      break;
    case 4:
      Serial.println("\033[2J\033[1;1H"); // clr scrn
      Serial.print("SSID: ");
      Serial.println(ssid);
      Serial.print("Password: ");
      Serial.println(password);
      Serial.print("API key: ");
      Serial.println(key);
      Serial.println();
      break;
    case 5:
      Serial.println("\033[2J\033[1;1H"); // clr scrn
      ESP.reset();
      break;
    default:
      Serial.println("\033[2J\033[1;1H"); // clr scrn
      Serial.println();
      Serial.print(temp_i);
      Serial.println(" is not a valid selection.");
      Serial.println();
      delay(5000);
      break;
  }
}


// reads serial port and returns string
String read_serial() {
  String s_str = "";
  int s_chr = -1;
  delay(50);

  while ( true ) {
    s_chr = Serial.read();
    delay(10);
    if ( s_chr < 0 ) {
      continue;
    }
    if ( s_chr == 13 ) {
      return s_str;
    } else {
      s_str += char( s_chr );
      Serial.write(s_chr);
    }
  }
}

// propts vor user input and cheks length
void input_prompt(String& inpt_st, String inpt_nm, int inpt_ln) {
  Serial.print("Enter ");
  Serial.print(inpt_nm);
  Serial.print(": ");
  String tmp_val = read_serial();
  Serial.println();
  if (tmp_val.length() >= inpt_ln ) {
    inpt_st = tmp_val;
    Serial.println("\033[2J\033[1;1H"); // clr scrn
    Serial.print("New value of ");
    Serial.print(inpt_nm);
    Serial.print(" is: ");
    Serial.println(inpt_st);
  } else {
    Serial.print("Value of ");
    Serial.print(inpt_nm);
    Serial.println(" did NOT change. Value must be at leaset ");
    Serial.print(inpt_ln);
    Serial.println(" character long.");
  }
}

