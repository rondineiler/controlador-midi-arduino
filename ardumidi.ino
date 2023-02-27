// Abaixo as declarações das variaveis
int valPot1 = 0;
int lastValPot1 = 0; 

int valPot2 = 0; 
int lastValPot2 = 0;

int valPot3 = 0;
int lastValPot3 = 0;

byte commandByte;
byte noteByte;
byte velocityByte;


//Carrega a biblioteca LiquidCrystal
#include <LiquidCrystal.h>

//Define os pinos que serão utilizados para ligação ao display
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  Serial.begin(9600);
  //Define o número de colunas e linhas do LCD
  lcd.begin(16, 2);
  //Limpa a tela
  lcd.clear();
  //Posiciona o cursor na coluna 3, linha 0;
  lcd.setCursor(3, 0);
  //Envia o texto entre aspas para o LCD
  lcd.print("CONTROLADOR");
  lcd.setCursor(3, 1);
  lcd.print("ARDUINO");
}

void loop() {
  // abaixo é feito a conversão dos valores 0 a 1023 analogico em midi 0 a 127
  valPot1 = analogRead(0) / 8; // valores de 0 a 127
  valPot2 = analogRead(1) / 8; // valores de 0 a 127
  valPot3 = analogRead(2) / 8; // valores de 0 a 127
  
//abaixo faz o teste se o valor do potenciometro 1 é igual seu ultimo valor
  if(valPot1 != lastValPot1){
    //enviar mensagem midi
    mensagemMIDI(176, 1 , valPot1);
    lastValPot1 = valPot1;
    lcd.clear();
    //Posiciona o cursor na coluna 3, linha 0;
    lcd.setCursor(0, 0);
    lcd.print("Potenciometro 1");
    lcd.setCursor(3, 1);
    lcd.print(lastValPot1);
  }
  //abaixo faz o teste se o valor do potenciometro 2 é igual seu ultimo valor
  if(valPot2 != lastValPot2){
    //enviar mensagem midi
    mensagemMIDI(177, 1 , valPot2);
    lastValPot2 = valPot2;
    lcd.clear();
    //Posiciona o cursor na coluna 3, linha 0;
    lcd.setCursor(0, 0);
    lcd.print("Potenciometro 2");
    lcd.setCursor(3, 1);
    lcd.print(lastValPot2);
  }

  //abaixo faz o teste se o valor do potenciometro 3 é igual seu ultimo valor
  if(valPot3 != lastValPot3){
    //enviar mensagem midi
    mensagemMIDI(178, 1 , valPot3);
    lastValPot3 = valPot3;
    lcd.clear();
    //Posiciona o cursor na coluna 3, linha 0;
    lcd.setCursor(0, 0);
    lcd.print("Potenciometro 3");
    lcd.setCursor(3, 1);
    lcd.print(lastValPot3);
  }
  delay(10);
}

// abaixo o método que atribui a porta serial as infromações midi a serem enviadas
void mensagemMIDI(byte comando, byte data1, byte data2) {
  Serial.write(comando);
  Serial.write(data1);
  Serial.write(data2);
}
