#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);


int ldr = A0;//Atribui A0 a variável ldr
int valorldr = 0;//Declara a variável valorldr como inteiro


void setup() {
  lcd.init();
  lcd.clear();
  lcd.backlight();

  pinMode(6, OUTPUT);
  pinMode(ldr, INPUT);//Define ldr (pino analógico A0) como saída
  Serial.begin(9600);//Inicialização da comunicação serial, com taxa de transferência em bits por segundo de 9600
   //digitalWrite(6, 1);
}

void loop()
{
  
  lcd.setCursor(2,0);
  lcd.print("Luminosidade: ");

    valorldr=analogRead(ldr);//Lê o valor do sensor ldr e armazena na variável valorldr

    lcd.setCursor(2,1);
    lcd.print(valorldr);

    Serial.println(valorldr);

    digitalWrite(6, 0);
    if(valorldr<=600){
      digitalWrite(6, 1);
    }
    else
       digitalWrite(6, 0);
}
