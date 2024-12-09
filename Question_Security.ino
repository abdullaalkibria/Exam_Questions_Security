#include <Servo.h>
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>

// Declare global variables and objects
Servo doorServo;
LiquidCrystal_I2C lcd(0x27, 16, 2); // I2C LCD initialization (Address 0x27 or 0x3F, 16 columns and 2 rows)
String generatedUnlockCode, generatedLockCode, enteredPIN = "";
bool doorOpenStatus = false;
bool newAttempt = true;
int attempts = 0;
String authorizedNumber = "+8801518469198"; // Replace with your number

// Keypad configuration
const byte ROWS = 4; // Four rows
const byte COLS = 4; // Four columns
char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
byte rowPins[ROWS] = { 4, 5, 6, 7 };
byte colPins[COLS] = { 8, 9, A2, A7 };
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

void setup() {
  randomSeed(analogRead(A0));  // Use noise from an unconnected analog pin to initialize the random seed
  Serial.begin(9600); // Use hardware Serial for SIM800L
  doorServo.attach(10); // Attach servo to digital pin 10
  doorServo.write(0);

  // Initialize LCD, Serial, and Servo
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Initializing...");
  delay(1000);
  lcd.clear();
  lcd.print("System Ready!");
  delay(2000);
  lcd_display();
}

// Main loop
void loop() {
  char key = keypad.getKey();
  if (key) {
    handleKeyPress(key);
  }
}

// Handle keypress logic
void handleKeyPress(char key) {
  if (key == '0') {
    sendPIN();
  } else if (key == '#') {
    validatePIN();
  } else {
    collectPIN(key);
  }
}

