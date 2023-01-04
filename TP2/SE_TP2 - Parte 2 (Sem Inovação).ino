int a = 3; //Pino 11 do display
int b = 8; //Pino 7 do display
int c = 7; //Pino 4 do display
int d = 6; //Pino 2 do display
int e = 5; //Pino 1 do display
int f = 4; //Pino 10 do display
int g = 2; //Pino 5 do display
int dp = 1; //Pino 3 do display

int d1 = 10; //Pino 6 do display
int d2 = 11; //Pino 8 do display
int d3 = 12; //Pino 9 do display
int d4 = 13; //Pino 12 do display
int startRoleTime;
int sec = 0, min = 0;

//Funções de exibição dos números no display de 7 segmentos
void zero() { //Função para escrever o nº zero
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, HIGH);
 // digitalWrite(dp, LOW);
}
void um() { //Função para escrever o nº um
  digitalWrite(a, HIGH);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
  //digitalWrite(dp, LOW);
}

void dois() { //Função para escrever o nº dois
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, HIGH);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, HIGH);
  digitalWrite(g, LOW);
 // digitalWrite(dp, LOW);
}

void tres() { //Função para escrever o nº três
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, LOW);
}

void quatro() { //Função para escrever o nº quatro
  digitalWrite(a, HIGH);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
}

void cinco() { //Função para escrever o nº cinco
  digitalWrite(a, LOW);
  digitalWrite(b, HIGH);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, HIGH);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
}

void seis() { //Função para escrever o nº seis
  digitalWrite(a, LOW);
  digitalWrite(b, HIGH);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
}

void sete() { //Função para escrever o nº sete
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
}

void oito() { //Função para escrever o nº oito
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
}

void nove() { //Função para escrever o nº nove
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, HIGH);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
}

void pontos() { //Função para escrever ....
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
  digitalWrite(dp, HIGH);
}

void setup() {
  startRoleTime = millis();
  //Configura todos os pinos como saída (OUTPUT)
  pinMode(d1, OUTPUT); //Dígitos
  pinMode(d2, OUTPUT);
  pinMode(d3, OUTPUT);
  pinMode(d4, OUTPUT);

  pinMode(a, OUTPUT); //Segmentos
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(dp, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  int actualTime = millis();
  time(1000, actualTime);  
}

void printFirstDisplay(int value){
  digitalWrite(d1, HIGH);
  number(value);
  delay(2);
}

void printSecondDisplay(int value){
  digitalWrite(d2, HIGH);
  number(value);
  digitalWrite(dp, LOW);
  delay(2);
}

void printThirdDisplay(int value){
  digitalWrite(d3, HIGH);
  number(value);
  delay(2);
}

void printFourthDisplay(int value){
  digitalWrite(d4, HIGH);
  number(value);
  delay(2);
}

void cleanAllDisplay(){
  digitalWrite(d1, LOW);
  digitalWrite(d2, LOW);
  digitalWrite(d3, LOW);
  digitalWrite(d4, LOW);
  pontos();
  //digitalWrite(dp, HIGH);
}

void time(int numb, int tim){
   //Serial.println(actualTime);
   int tempo=millis();
  
  while(tempo - tim <= numb ){
    tempo=millis();

    printFirstDisplay(min / 10);
    cleanAllDisplay();
    printSecondDisplay(min % 10);
    cleanAllDisplay();
    printThirdDisplay(sec / 10);
    cleanAllDisplay();
    printFourthDisplay(sec % 10);
    cleanAllDisplay();
  }
   sec++;
      
    if(sec == 60){
      sec = 0;
      min++;
    }

    if(min == 60)
      min=0;
}

void number(int value){
  switch(value){
    case 0:
      zero();
      break;
    case 1:
      um();
      break;
    case 2:
      dois();
      break;
    case 3:
      tres();
      break;
    case 4:
      quatro();
      break;
    case 5:
      cinco();
      break;
    case 6:
      seis();
      break;
    case 7:
      sete();
      break;
    case 8:
      oito();
      break;
    case 9:
      nove();
      break;
  }  
}
