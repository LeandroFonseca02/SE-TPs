#include <wiringPi.h>
#include <wiringShift.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define btnStonePin 4
#define btnPaperPin 5
#define btnScissorPin 6
#define dataPin 0
#define latchPin 2
#define clockPin 3

unsigned char tesoura[] = {0x0, 0x81, 0x42, 0x24, 0x18, 0x5a, 0xa5, 0x42};
unsigned char papel[] = {0x8, 0x1c, 0x3e, 0x7f, 0xfe, 0x7c, 0x38, 0x10};
unsigned char pedra[] = {0x0, 0x0, 0x0, 0x3c, 0x42, 0x62, 0x1c, 0x0};
unsigned char loss[] = {
        0x00,0x000,0x00,0x00,0x00,0x00,0x00,0x00,
        0x00, 0x06,  0x06,  0x06, 0x06, 0x06, 0x06, 0x7e,
        0x00, 0x3c, 0x66, 0x66, 0x66, 0x66, 0x66, 0x3c,
        0x00, 0x3c, 0x66, 0x06, 0x3c, 0x60, 0x66, 0x3c,
        0x00, 0x3c, 0x66, 0x06, 0x3c, 0x60, 0x66, 0x3c,
        0x00,0x000,0x00,0x00,0x00,0x00,0x00,0x00
};

unsigned char countdown[] = {
        0x00,0x000,0x00,0x00,0x00,0x00,0x00,0x00,
        0x18,0x18,0x1c,0x18,0x18,0x18,0x7e, 0x00,
        0x3c,0x66,0x60,0x30,0x0c,0x06,0x7e, 0x00,
        0x3c, 0x66, 0x60, 0x38, 0x60, 0x66, 0x3c, 0x00,
        0x00,0x000,0x00,0x00,0x00,0x00,0x00,0x00
};

unsigned char tie[] = {
        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
        0x00, 0x7e,0x5a,0x18,0x18,0x18,0x18,0x18,
        0x00,0x3c,0x18,0x18,0x18,0x18,0x18,0x3c,
        0x00,0x7e, 0x06, 0x06, 0x3e, 0x06, 0x06, 0x7e,
        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
};

unsigned char win[] = {
        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
        0x00,0xc3,0xc3,0xc3,0xdb,0xff,0xe7,0xc3,
        0x00,0x3c,0x18,0x18,0x18,0x18,0x18,0x3c,
        0x00,0xc6, 0xce, 0xde, 0xf6, 0xe6, 0xc6, 0xc6,
        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
};

void _shiftOut(int dPin, int cPin, int order, int val) {
    int i;
    for (i = 0; i < 8; i++) {
        digitalWrite(cPin, LOW);
        if (order == LSBFIRST) {
            digitalWrite(dPin, ((0x01 & (val >> i)) == 0x01) ? HIGH : LOW);
            delayMicroseconds(10);
        } else {//if(order == MSBFIRST){
            digitalWrite(dPin, ((0x80 & (val << i)) == 0x80) ? HIGH : LOW);
            delayMicroseconds(10);
        }
        digitalWrite(cPin, HIGH);
        delayMicroseconds(10);
    }
}

void printResult(unsigned char *arr){
    for (int k = 0; k < (sizeof(arr)*10); k++) { //sizeof(data) total number of "0-F" columns

        for (int j = 0; j < 10; j++) { //times of repeated displaying LEDMatrix in every frame, the bigger the “j”, the longer the display time
            int x = 0x80;

            for (int i = k; i < 8 + k; i++) {//Set the column information to start from the first column
                digitalWrite(latchPin, LOW);
                _shiftOut(dataPin, clockPin, MSBFIRST, arr[i]);
                _shiftOut(dataPin, clockPin, MSBFIRST, ~x);
                digitalWrite(latchPin, HIGH);
                x >>= 1;
                delay(1);
            }
        }
    }
}

void printStatic(unsigned char *arr){
    for (int j = 0; j < 150; j++) { //Repeat enough times to display the smiling face a period of time
        int x = 0x80;

        for (int i = 0; i < 8; i++) {
            digitalWrite(latchPin, LOW);
            _shiftOut(dataPin, clockPin, MSBFIRST,arr[i]);// first shift data of line information to the first stage 74HC959 information to the first stage 74HC959
            _shiftOut(dataPin, clockPin, MSBFIRST, ~x);//then shift data of column information to the second stage 74HC959
            digitalWrite(latchPin, HIGH);//Output data of two stage 74HC595 at the same time
            x >>= 1;
//display the next column
            delay(1);
        }
    }
}

int game(char you, char computer)
{
    // If both the user and computer
    // has chose the same thing
    if (you == computer)
        return -1;

    // If user's choice is stone and
    // computer's choice is paper
    if (you == 's' && computer == 'p')
        return 0;

        // If user's choice is paper and
        // computer's choice is stone
    else if (you == 'p' && computer == 's') return 1;

    // If user's choice is stone and
    // computer's choice is scissor
    if (you == 's' && computer == 'z')
        return 1;

        // If user's choice is scissor and
        // computer's choice is stone
    else if (you == 'z' && computer == 's')
        return 0;

    // If user's choice is paper and
    // computer's choice is scissor
    if (you == 'p' && computer == 'z')
        return 0;

        // If user's choice is scissor and
        // computer's choice is paper
    else if (you == 'z' && computer == 'p')
        return 1;
}


int main(void) {
    int i, j, k;
    unsigned char x;
    srand(time(0));

    printf("Program is starting ...\n");
    wiringPiSetup();
    pinMode(btnStonePin, INPUT);
    pinMode(btnPaperPin, INPUT);
    pinMode(btnScissorPin, INPUT);
    pullUpDnControl(btnStonePin, PUD_UP);
    pullUpDnControl(btnPaperPin, PUD_UP);
    pullUpDnControl(btnScissorPin, PUD_UP);

    while (1) {
        printf("\n\nJogo a começar...\n");
        int btnFlag = 0;
        char chrPlayerPlay;
        char chrBotPlay;
        while (btnFlag == 0){
            if(digitalRead(btnStonePin) == 0){
                printf("O Jogador jogou Pedra\n");
                chrPlayerPlay = 's';
                btnFlag = 1;
                break;
            }
            if(digitalRead(btnPaperPin) == 0){
                printf("O Jogador jogou Papel\n");
                chrPlayerPlay = 'p';
                btnFlag = 1;
                break;
            }
            if(digitalRead(btnScissorPin) == 0){
                printf("O Jogador jogou Tesoura\n");
                chrPlayerPlay = 'z';
                btnFlag = 1;
                break;
            }
        }

        printResult(countdown);

        int intBotPlay = (rand() % (3)) + 1;

        switch (intBotPlay) {
            case 1:
                printf("O Bot jogou Pedra\n");
                printStatic(pedra);
                chrBotPlay = 's';
                break;
            case 2:
                printf("O Bot jogou Papel\n");
                printStatic(papel);
                chrBotPlay = 'p';
                break;
            case 3:
                printf("O Bot jogou Tesoura\n");
                printStatic(tesoura);
                chrBotPlay = 'z';
                break;
        }

        int result = game(chrPlayerPlay,chrBotPlay);

        if (result == -1) {
            printf("\nEmpate!\n");
            printResult(tie);
        }
        else if (result == 1) {
            printf("\nJogador Ganhou!\n");
            printResult(win);
        }
        else {
            printf("\nBot Ganhou!\n");
            printResult(loss);
        }
        delay(1000);
    }

    return 0;
}
