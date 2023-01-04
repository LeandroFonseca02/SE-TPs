const int buzzer = A2;

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

int firstButton = A0;
int secButton = A1;

int startRoleTime;
int sec = 0, min = 0;

int addButtonState = 0;
int confirmButtonState = 0;

int display[4] = {0,0,0,0};
int * tempo;


#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978
#define REST      0


// change this to make the song slower or faster
int tempoBuz = 140;

// notes of the moledy followed by the duration.
// a 4 means a quarter note, 8 an eighteenth , 16 sixteenth, so on
// !!negative numbers are used to represent dotted notes,
// so -4 means a dotted quarter note, that is, a quarter plus an eighteenth!!
int melody[] = {
  
  // Dart Vader theme (Imperial March) - Star wars 
  // Score available at https://musescore.com/user/202909/scores/1141521
  // The tenor saxophone part was used
  
  NOTE_AS4,8, NOTE_AS4,8, NOTE_AS4,8,//1
  NOTE_F5,2, NOTE_C6,2,
  NOTE_AS5,8, NOTE_A5,8, NOTE_G5,8, NOTE_F6,2, NOTE_C6,4,  
  NOTE_AS5,8, NOTE_A5,8, NOTE_G5,8, NOTE_F6,2, NOTE_C6,4,  
  NOTE_AS5,8, NOTE_A5,8, NOTE_AS5,8, NOTE_G5,2, NOTE_C5,8, NOTE_C5,8, NOTE_C5,8,
  NOTE_F5,2, NOTE_C6,2,
  NOTE_AS5,8, NOTE_A5,8, NOTE_G5,8, NOTE_F6,2, NOTE_C6,4,  
  
  NOTE_AS5,8, NOTE_A5,8, NOTE_G5,8, NOTE_F6,2, NOTE_C6,4, //8  
  NOTE_AS5,8, NOTE_A5,8, NOTE_AS5,8, NOTE_G5,2, NOTE_C5,-8, NOTE_C5,16, 
  NOTE_D5,-4, NOTE_D5,8, NOTE_AS5,8, NOTE_A5,8, NOTE_G5,8, NOTE_F5,8,
  NOTE_F5,8, NOTE_G5,8, NOTE_A5,8, NOTE_G5,4, NOTE_D5,8, NOTE_E5,4,NOTE_C5,-8, NOTE_C5,16,
  NOTE_D5,-4, NOTE_D5,8, NOTE_AS5,8, NOTE_A5,8, NOTE_G5,8, NOTE_F5,8,
  
  NOTE_C6,-8, NOTE_G5,16, NOTE_G5,2, REST,8, NOTE_C5,8,//13
  NOTE_D5,-4, NOTE_D5,8, NOTE_AS5,8, NOTE_A5,8, NOTE_G5,8, NOTE_F5,8,
  NOTE_F5,8, NOTE_G5,8, NOTE_A5,8, NOTE_G5,4, NOTE_D5,8, NOTE_E5,4,NOTE_C6,-8, NOTE_C6,16,
  NOTE_F6,4, NOTE_DS6,8, NOTE_CS6,4, NOTE_C6,8, NOTE_AS5,4, NOTE_GS5,8, NOTE_G5,4, NOTE_F5,8,
  NOTE_C6,1
  
};

// sizeof gives the number of bytes, each int value is composed of two bytes (16 bits)
// there are two values per note (pitch and duration), so for each note there are four bytes
int notes = sizeof(melody) / sizeof(melody[0]) / 2;

// this calculates the duration of a whole note in ms
int wholenote = (60000 * 4) / tempoBuz;

int divider = 0, noteDuration = 0;


//Funções de exibição dos números no display de 7 segmentos
void zero() { //Função para escrever o nº zero
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, HIGH);
}
void um() { //Função para escrever o nº um
  digitalWrite(a, HIGH);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
}

void dois() { //Função para escrever o nº dois
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, HIGH);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, HIGH);
  digitalWrite(g, LOW);
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

void printDigits(int digit, int number){
 switch (digit){
   
  case 0:
    printFirstDisplay(number);
    break;
  case 1:
    printSecondDisplay(number);
    break;
  case 2:
    printThirdDisplay(number);
    break;
  case 3:
    printFourthDisplay(number);
    break;
 }
 cleanAllDisplay();
}

int * chooseTime(int addButton, int confirmButton){

  for(int i = 0; i < 4; i++){
    confirmButtonState = digitalRead(confirmButton);

    while(!confirmButtonState == LOW){
      confirmButtonState = digitalRead(confirmButton);
      addButtonState = digitalRead(addButton);

      if(addButtonState == LOW){
        display[i]++;
      }

      if(display[i] >= 10){
        display[i] = 0;
      }

      printDigits(i, display[i]);
      delay(70);
    }
      delay(300);
  }
  
  return display;
}


void verificaTempo(int temp[4], int actualTime){
  
    while(compareTo(temp, min, sec) != 1){
       actualTime = millis();
      Serial.print( (min/10));
      Serial.print(( min%10) );
      Serial.print(  (sec/10) );
      Serial.print((sec%10));
      Serial.println();
      time(1000, actualTime);
    }

  Serial.print("buz");

  for (int thisNote = 0; thisNote < notes * 2; thisNote = thisNote + 2) {

    // calculates the duration of each note
    divider = melody[thisNote + 1];
    if (divider > 0) {
      // regular note, just proceed
      noteDuration = (wholenote) / divider;
    } else if (divider < 0) {
      // dotted notes are represented with negative durations!!
      noteDuration = (wholenote) / abs(divider);
      noteDuration *= 1.5; // increases the duration in half for dotted notes
    }

    // we only play the note for 90% of the duration, leaving 10% as a pause
    tone(buzzer, melody[thisNote], noteDuration * 0.9);

    // Wait for the specief duration before playing the next note.
    delay(noteDuration);

    // stop the waveform generation before the next note.
    noTone(buzzer);
  }
}

int compareTo(int temp[4], int min, int sec){
  if((temp[0] == min/10) && (temp[1] == min%10) && (temp[2] == sec/10) && (temp[3] == sec%10)){
    return 1;
  }

  return 0;
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


  pinMode(firstButton, INPUT_PULLUP);
  pinMode(secButton, INPUT_PULLUP);
  pinMode(buzzer, OUTPUT);

  Serial.begin(9600);

  Serial.print(millis());
}

void loop() {
  int actualTime = millis();

  tempo = chooseTime(firstButton, secButton);
  verificaTempo(tempo, actualTime);
}
