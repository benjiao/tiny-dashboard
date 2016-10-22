
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

String line1 = "";
String line2 = "";

void printSerialLine(int line, String content){
  // Clear line
  lcd.setCursor(0, line);
  lcd.print("                ");

  // Display contents
  lcd.setCursor(0, line);
  lcd.print(content);
}

void setup(){
  Serial.begin(9600);
  
  // LCD Setup
  lcd.begin(16, 2);
  printSerialLine(0, "Waiting for");
  printSerialLine(1, "connection...");
}

void loop(){

  while(Serial.available()==0);
  
  // Discard everything until this marker
  Serial.readStringUntil('Clujlusjarr7');

  line1 = Serial.readStringUntil('\n');
  line2 = Serial.readStringUntil('\n');
  printSerialLine(0, line1);
  printSerialLine(1, line2);
}
