
// Open the door
void openDoor() {
  lcd.clear();
  lcd.print("Opening Door...");
  delay(300);
  for (int i = 0; i <= 175; i += 5) {
    doorServo.write(i);
    delay(5);
  }
  lcd.clear();
  lcd.print("Door Opened!");
  delay(2000);
  lcd.clear();
  lcd.print("Enter PIN");
  lcd.setCursor(0, 1);
  lcd.print("to Close.");
}

// Close the door
void closeDoor() {
  lcd.clear();
  lcd.print("Closing Door...");
  delay(300);
  for (int i = 175; i >= 0; i -= 5) {
    doorServo.write(i);
    delay(5);
  }
  lcd.clear();
  lcd.print("Door Locked!");
  delay(1000);
  lcd_display();
}
