// Rows 
#define R1 2
#define R2 3
#define R3 4
#define R4 5
#define R5 6
#define R6 7
#define R7 8
#define R8 9
//Columns
#define C1 10
#define C2 11
#define C3 12
#define C4 13
#define C5 A0
#define C6 A1
#define C7 A2
#define C8 A3

int buttonPin = A5;

 
int One [8] [8] ={
  {0,0,0,1,0,0,0,0},
  {0,0,1,1,0,0,0,0},
  {0,0,0,1,0,0,0,0},
  {0,0,0,1,0,0,0,0},
  {0,0,0,1,0,0,0,0},
  {0,0,0,1,0,0,0,0},
  {0,0,0,1,0,0,0,0},
  {0,0,1,1,1,0,0,0},
  };
 
int Two [8] [8] ={
  {0,0,1,1,1,0,0,0},
  {0,1,0,0,0,1,0,0},
  {0,0,0,0,0,1,0,0},
  {0,0,0,0,0,1,0,0},
  {0,0,0,0,1,0,0,0},
  {0,0,0,1,0,0,0,0},
  {0,0,1,0,0,0,0,0},
  {0,1,1,1,1,1,0,0},
  };
 
int Three [8] [8] ={
  {0,0,1,1,1,0,0,0},
  {0,1,0,0,0,1,0,0},
  {0,0,0,0,0,1,0,0},
  {0,0,0,1,1,0,0,0},
  {0,0,0,0,0,1,0,0},
  {0,0,0,0,0,1,0,0},
  {0,1,0,0,0,1,0,0},
  {0,0,1,1,1,0,0,0},
  };
 
  int Four [8] [8] ={
  {0,0,0,0,0,1,0,0},
  {0,0,0,0,1,1,0,0},
  {0,0,0,1,0,1,0,0},
  {0,0,1,0,0,1,0,0},
  {0,1,0,0,0,1,0,0},
  {0,1,1,1,1,1,0,0},
  {0,0,0,0,0,1,0,0},
  {0,0,0,0,0,1,0,0},
  };
 
int Five [8] [8] ={
  {0,1,1,1,1,1,0,0},
  {0,1,0,0,0,0,0,0},
  {0,1,0,0,0,0,0,0},
  {0,1,1,1,1,0,0,0},
  {0,0,0,0,0,1,0,0},
  {0,0,0,0,0,1,0,0},
  {0,1,0,0,0,1,0,0},
  {0,0,1,1,1,0,0,0},
  };
 
int Six [8] [8] ={
  {0,0,1,1,1,0,0,0},
  {0,1,0,0,0,1,0,0},
  {0,1,0,0,0,0,0,0},
  {0,1,1,1,1,0,0,0},
  {0,1,0,0,0,1,0,0},
  {0,1,0,0,0,1,0,0},
  {0,1,0,0,0,1,0,0},
  {0,0,1,1,1,0,0,0},
  };

int Smile [8] [8] ={
  {0,0,0,0,0,0,0,0},
  {0,0,1,0,0,1,0,0},
  {0,0,1,0,0,1,0,0},
  {0,0,1,0,0,1,0,0},
  {0,0,0,0,0,0,0,0},
  {0,1,0,0,0,0,1,0},
  {0,0,1,1,1,1,0,0},
  {0,0,0,0,0,0,0,0},
  };

int P [8] [8] ={
  {0,0,0,0,0,0,0,0},
  {0,1,1,1,1,1,0,0},
  {0,1,1,0,0,1,1,0},
  {0,1,1,0,0,1,1,0},
  {0,1,1,0,0,1,1,0},
  {0,1,1,1,1,1,0,0},
  {0,1,1,0,0,0,0,0},
  {0,1,1,0,0,0,0,0},
  };

int L [8] [8] ={
  {0,0,0,0,0,0,0,0},
  {0,1,1,0,0,0,0,0},
  {0,1,1,0,0,0,0,0},
  {0,1,1,0,0,0,0,0},
  {0,1,1,0,0,0,0,0},
  {0,1,1,0,0,0,0,0},
  {0,1,1,0,0,0,0,0},
  {0,1,1,1,1,1,1,0},
  };

int T [8] [8] ={
  {0,0,0,0,0,0,0,0},
  {0,1,1,1,1,1,1,0},
  {0,1,0,1,1,0,1,0},
  {0,0,0,1,1,0,0,0},
  {0,0,0,1,1,0,0,0},
  {0,0,0,1,1,0,0,0},
  {0,0,0,1,1,0,0,0},
  {0,0,0,1,1,0,0,0},
  };
 
void setup() {
  pinMode(R1, OUTPUT);
  pinMode(R2, OUTPUT);
  pinMode(R3, OUTPUT);
  pinMode(R4, OUTPUT);
  pinMode(R5, OUTPUT);
  pinMode(R6, OUTPUT);
  pinMode(R7, OUTPUT);
  pinMode(R8, OUTPUT);
  pinMode(C1, OUTPUT);
  pinMode(C2, OUTPUT);
  pinMode(C3, OUTPUT);
  pinMode(C4, OUTPUT);
  pinMode(C5, OUTPUT);
  pinMode(C6, OUTPUT);
  pinMode(C7, OUTPUT);
  pinMode(C8, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  Serial.begin(9600);
  randomSeed(analogRead(0)); 
}
 
 
void SelectRow(int row){
  if (row==1) digitalWrite(R1,LOW); else digitalWrite(R1,HIGH);
  if (row==2) digitalWrite(R2,LOW); else digitalWrite(R2,HIGH);
  if (row==3) digitalWrite(R3,LOW); else digitalWrite(R3,HIGH);
  if (row==4) digitalWrite(R4,LOW); else digitalWrite(R4,HIGH);
  if (row==5) digitalWrite(R5,LOW); else digitalWrite(R5,HIGH);
  if (row==6) digitalWrite(R6,LOW); else digitalWrite(R6,HIGH);
  if (row==7) digitalWrite(R7,LOW); else digitalWrite(R7,HIGH);
  if (row==8) digitalWrite(R8,LOW); else digitalWrite(R8,HIGH);
}
 
void Set_LED_in_Active_Row(int column, int state){
  if (column==1) digitalWrite(C1,state); 
  if (column==2) digitalWrite(C2,state); 
  if (column==3) digitalWrite(C3,state); 
  if (column==4) digitalWrite(C4,state); 
  if (column==5) digitalWrite(C5,state); 
  if (column==6) digitalWrite(C6,state); 
  if (column==7) digitalWrite(C7,state); 
  if (column==8) digitalWrite(C8,state); 
}
 
void printMatrix(int drawing[8][8]){
  for (int j=0;j<8;j++){
    SelectRow(j+1);
      for (int i=0;i<8;i++){
        Set_LED_in_Active_Row(i+1 ,drawing[j][i]);
      }
      delay(1);
    }
}
 
void printNumber(int number){
  switch(number){
      case 1:
          printMatrix(One);
          break;
      case 2:
          printMatrix(Two);
          break;
      case 3:
          printMatrix(Three);
          break;
      case 4:
          printMatrix(Four);
          break;
      case 5:
          printMatrix(Five);
          break;
      case 6:
          printMatrix(Six);
          break;
      default:
      	break;
  }
}
 
void displayNumber(int number, int milliSecDisplayed){
  int timeNow = millis();
  int prevTime = millis();
  
  while(timeNow < (prevTime + milliSecDisplayed)){
      timeNow = millis();
      printNumber(number);
    }
}

int rollDice(int rollingTime, int speedTime){
  int startRoleTime = millis();
  int actualTime = millis();
  int number = random(1,7);
  int counter = 1;
  
  while(actualTime < (startRoleTime + rollingTime)){
    actualTime = millis();
    displayNumber(counter,speedTime);

    counter++;

    if(counter > 6){
      counter = 1;
    }
  }

  while(counter != number){
    displayNumber(counter,speedTime);
	counter++;

    if(counter > 6){
      counter = 1;
    }
  }
  
  return number;
  
}

void buttonConfirmation(int buttonPin){
  int buttonState = digitalRead(buttonPin);
  while(!buttonState == LOW){
  	buttonState = digitalRead(buttonPin);
  }

  delay(500);
}

void printMatrixUntilButtonPressed(int drawing[8][8], int buttonPin){
  int buttonState = digitalRead(buttonPin);
  while(!buttonState == LOW){
      buttonState = digitalRead(buttonPin);
      printMatrix(drawing);
    }
    delay(500);
}

void printMatrixNumberUntilButtonPressed(int number, int buttonPin){
  int buttonState = digitalRead(buttonPin);   
  while(!buttonState == LOW){
      buttonState = digitalRead(buttonPin);
      printNumber(number);
    }
    delay(500);
}


void loop() {
  int number = rollDice(1400,100);
  Serial.print("Numero do dado: ");
  Serial.println(number);
  printMatrixNumberUntilButtonPressed(number, buttonPin);

  Serial.println("Smile");
  printMatrixUntilButtonPressed(Smile,buttonPin);
  Serial.println("L");
  printMatrixUntilButtonPressed(L,buttonPin);
  Serial.println("P");
  printMatrixUntilButtonPressed(P,buttonPin);
  Serial.println("T");
  printMatrixUntilButtonPressed(T,buttonPin);

}
 
