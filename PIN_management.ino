void lcd_display() {
  lcd.clear();
  lcd.print("Enter ZERO(0)");
  lcd.setCursor(0, 1);
  lcd.print("to get PIN");
}

// Validate entered PIN
void validatePIN() {
  if (enteredPIN == generatedUnlockCode) {
    if (!doorOpenStatus) {
      delay(1000);
      openDoor();
      doorOpenStatus = true;
      generatedUnlockCode = "";
    } else {
      lcd.clear();
      lcd.print("Door stil OPENED");
      delay(2000);
      lcd.clear();
      lcd.print("Enter PIN");
      lcd.setCursor(0, 1);
      lcd.print("to Close.");
    }
  } else if (enteredPIN == generatedLockCode) {
    if (doorOpenStatus) {
      delay(1000);
      closeDoor();
      doorOpenStatus = false;
      generatedLockCode = "";
      newAttempt = true;
    } else {
      lcd.clear();
      lcd.print("Door stil LOCKED");
      lcd_display();
    }
  } else {
    handleInvalidPIN();
  }
  enteredPIN = "";  // Reset entered PIN
}

// Collect digits of the PIN
void collectPIN(char key) {
  enteredPIN += key;
  lcd.clear();
  lcd.print("Enter PIN: ");
  lcd.setCursor(0, 1);
  for (int i = 0; i < enteredPIN.length(); i++) {
    lcd.print("*");  // Masked PIN
  }
}

// Handle invalid PIN attempts
void handleInvalidPIN() {
  attempts++;
  newAttempt = true;
  if (attempts >= 3) {
    lockSystem();
  } else {
    lcd.clear();
    lcd.print("Wrong PIN!");
    lcd.setCursor(0, 1);
    lcd.print("Attempt: " + String(attempts));
    delay(2000);
    lcd_display();
  }
}

// Lock system after 3 invalid attempts
void lockSystem() {
  lcd.clear();
  lcd.print("Access Denied!");
  delay(2000);
  lcd.clear();
  lcd.print("Locking System");
  lcd.setCursor(0, 1);
  lcd.print("Hold 1 Min");
  sendAlertSMS();
  attempts = 0;
  delay(60000);  // Lock for 1 minute
  lcd_display();
}
