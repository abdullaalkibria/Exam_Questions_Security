// Send SMS via GSM module
void sendSMS(String unlockPIN, String lockPIN) {
  String message;
  Serial.println("AT+CMGF=1");  // Configuring TEXT mode
  delay(500);
  Serial.println("AT+CMGS=\"" + authorizedNumber + "\"");
  delay(500);

  if (unlockPIN == "**") {
    message = "LOCK PIN: " + lockPIN;
    Serial.print(message);
    Serial.write(26);  // ASCII code for CTRL+Z
  } else {
    message = "UNLOCK PIN: " + unlockPIN + "\nLOCK PIN: " + lockPIN;
    Serial.print(message);
    Serial.write(26);  // ASCII code for CTRL+Z
  }
  delay(500);
}

// Send alert SMS after 3 invalid attempts
void sendAlertSMS() {
  Serial.println("AT+CMGF=1");
  delay(500);
  Serial.println("AT+CMGS=\"" + authorizedNumber + "\"");
  delay(500);
  String message = "ALERT!\n3 incorrect attempts.";
  Serial.print(message);
  Serial.write(26);
  delay(500);
}
// Send PIN via SMS
void sendPIN() {
  if (newAttempt) {
    newAttempt = false;
  } else {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Already Sent PIN");
    lcd.setCursor(0, 1);
    lcd.print("Check the message!");
    enteredPIN = "";  // Reset entered PIN
    delay(3000);
    lcd.clear();
    lcd.print("Enter PIN!");
    return;
  }

  lcd.clear();
  lcd.print("Processing...");
  if (doorOpenStatus == true) {
    generatedLockCode = generateCode();
    sendSMS("**", generatedLockCode);
  } else {
    generatedUnlockCode = generateCode();
    generatedLockCode = generateCode();
    sendSMS(generatedUnlockCode, generatedLockCode);
  }

  lcd.clear();
  lcd.print("PIN Sent!");
  delay(2000);
  lcd.clear();
  lcd.print("Enter PIN!");
}