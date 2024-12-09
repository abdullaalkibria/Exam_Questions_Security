// Generate a 4-digit random code
String generateCode() {
  String code = "";
  int validNumbers[] = {2, 3, 5, 6, 8, 9};
  for (int i = 0; i < 4; i++) {
    int index = random(0, 6);
    code += String(validNumbers[index]);
  }
  return code;
}
