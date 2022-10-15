#include <LiquidCrystal.h>
#define kirmizi 8
#define sari 7
#define yesil 6  
int LM35_Pini = A0;
LiquidCrystal LCD_Ekran(12, 11, 5, 4, 3, 2);
void setup() 
{
  pinMode(kirmizi, OUTPUT);
  pinMode(sari, OUTPUT);
  pinMode(yesil, OUTPUT);
  digitalWrite(kirmizi,LOW);
  digitalWrite(sari,LOW);
  digitalWrite(yesil,LOW);
  LCD_Ekran.begin(16, 2);
  analogReference(INTERNAL);
  LCD_Ekran.print("Ortam Sicakligi");
} 
void loop()
{
  int sicaklikVoltaji = analogRead(LM35_Pini);
  float sicaklikDerecesi = sicaklikVoltaji / 9.31; 
  if (sicaklikDerecesi<15)
  {
    digitalWrite(kirmizi,LOW);
    digitalWrite(sari,LOW);
    digitalWrite(yesil,HIGH);
  }else if(sicaklikDerecesi>=15 and sicaklikDerecesi<=25)
  {
    digitalWrite(kirmizi,LOW);
    digitalWrite(sari,HIGH);
    digitalWrite(yesil,LOW);
  }else
  {
    digitalWrite(kirmizi,HIGH);
    digitalWrite(sari,LOW);
    digitalWrite(yesil,LOW);
  }
  LCD_Ekran.setCursor(0, 1);
  LCD_Ekran.print(sicaklikDerecesi);
  LCD_Ekran.setCursor(6,1);
  LCD_Ekran.print("\337C");
  delay(1000);
}
