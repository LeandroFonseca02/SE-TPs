/*
  Trabalho de Sistemas Embebidos - ISMAT 22-23
  TP1 - Parte 1
  
  Leandro Fonseca
  Pedro Pinto
  Tiago Caetano
*/

int firstSeg[7] = {0,1,2,3,4,5,6};
int secSeg[7] = {7,8,9,10,11,12,13};
byte firstButton = 14;
byte secButton = 15;

int addButtonState = 0;
int confirmButtonState = 0;

int counter = 0;
int firstNum = 0;
int secNum = 0;

void printNumber(int seg[7], int number){

  switch(number) {
    case 0:
      printZero(seg);
      break;

    case 1:
      printOne(seg);
      break;

    case 2:
      printTwo(seg);
      break;

    case 3:
      printThree(seg);
      break;

    case 4:
      printFour(seg);
      break;

    case 5:
      printFive(seg);
      break;

    case 6:
      printSix(seg);
      break;

    case 7:
      printSeven(seg);
      break;

    case 8:
      printEight(seg);
      break;

    case 9:
      printNine(seg);
      break;
  
    default:
      printH(seg);
      break;
  }
}

void printZero(int seg[7]){
  resetSeg(seg);
  for(int i = 0; i < 6; i++){
    digitalWrite(seg[i],0);
  }
}

void printOne(int seg[7]){
  resetSeg(seg);
  digitalWrite(seg[1],0);
  digitalWrite(seg[2],0);
}

void printTwo(int seg[7]){
  resetSeg(seg);
  for(int i = 0; i < 7; i++){
    if(i != 2 && i != 5){
      digitalWrite(seg[i],0);
    }
  }
}

void printThree(int seg[7]){
  resetSeg(seg);
  for(int i = 0; i < 7; i++){
    if(i != 4 && i != 5){
      digitalWrite(seg[i],0);
    }
  }
}

void printFour(int seg[7]){
  resetSeg(seg);
  for(int i = 0; i < 7; i++){
    if(i != 0 && i != 3 && i != 4){
      digitalWrite(seg[i],0);
    }
  }
}

void printFive(int seg[7]){
  resetSeg(seg);
  for(int i = 0; i < 7; i++){
    if(i != 1 && i != 4){
      digitalWrite(seg[i],0);
    }
  }
}

void printSix(int seg[7]){
  resetSeg(seg);
  for(int i = 0; i < 7; i++){
    if(i != 1){
      digitalWrite(seg[i],0);
    }
  }
}

void printSeven(int seg[7]){
  resetSeg(seg);
  for(int i = 0; i < 3; i++){
    digitalWrite(seg[i],0);
  }
}

void printEight(int seg[7]){
  resetSeg(seg);
  for(int i = 0; i < 7; i++){
    digitalWrite(seg[i],0);
  }
}

void printNine(int seg[7]){
  resetSeg(seg);
  for(int i = 0; i < 7; i++){
    if(i != 4){
      digitalWrite(seg[i],0);
    }
  }
}

void printH(int seg[7]){
  resetSeg(seg);
  for(int i = 0; i < 7; i++){
    if(i != 0 && i != 3){
      digitalWrite(seg[i],0);
    }
  }
}

void resetSeg(int seg[7]){
  for(int i = 0; i < 7; i++){
      digitalWrite(seg[i], 1);
    }
}

void setupSeg(int seg[7]){
    for(int i = 0; i < 7; i++){
      pinMode(seg[i], OUTPUT);
    }
}

int chooseNumber(int seg[7], int addButton, int confirmButton){
  int number = 0;
  confirmButtonState = digitalRead(confirmButton);
  
  while(!confirmButtonState == LOW){
    confirmButtonState = digitalRead(secButton);
    addButtonState = digitalRead(addButton);

    if(addButtonState == LOW){
      number++;
    }

    if(number >= 10){
      number = 0;
    } 
    printNumber(seg,number);
    delay(350);
  }
  return number;
}

void printResult(int resultNumber, int seg[7], int seg2[7], int confirmButton){
  confirmButtonState = digitalRead(secButton);
  
  int unit=resultNumber%10;
  int dec=resultNumber/10;
  
  if(dec == 0){
    resetSeg(seg);
  }else{
    printNumber(seg,dec);
  }
  
  printNumber(seg2,unit);
  
  while(!confirmButtonState == LOW){
    confirmButtonState = digitalRead(secButton);
  }
  
}

void addNumbers(int firstSeg[7], int secSeg[7], int addButton, int confirmButton){
  resetSeg(secSeg);
  int firstNum = chooseNumber(firstSeg,addButton,confirmButton);
  int secNum = chooseNumber(secSeg,addButton,confirmButton);
  printResult(firstNum+secNum,firstSeg,secSeg,confirmButton);
}


void setup() {
  setupSeg(firstSeg);
  setupSeg(secSeg);
  pinMode(firstButton,INPUT_PULLUP);
  pinMode(secButton,INPUT_PULLUP);
}

void loop() {
  addNumbers(firstSeg,secSeg,firstButton,secButton);
}
