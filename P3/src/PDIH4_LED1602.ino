#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

byte exclamacion[] = {
  0x00,
  0x04,
  0x00,
  0x00,
  0x04,
  0x04,
  0x04,
  0x04
};



byte smile[] = {
  0x00,
  0x00,
  0x0A,
  0x00,
  0x11,
  0x0E,
  0x00,
  0x00
};
void setup() {
  lcd.begin(16, 2);
  lcd.createChar(0, exclamacion);
  lcd.createChar(1, smile);
  lcd.home();
  lcd.write(byte(0));

  lcd.print("Hola, mundo!");
  lcd.write(byte(1));
}

void loop() {
  lcd.setCursor(0, 1);

  lcd.print("Contador:");
  lcd.print(millis() / 1000);
}
