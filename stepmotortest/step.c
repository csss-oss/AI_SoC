#include <stdio.h>
#include <wiringPi.h>
#include <string.h>

#define ORANGE 21
#define YELLOW 22
#define PINK 23
#define BLUE 24
#define RED 25

void step_wave(int step) //4스텝
{
    switch(step)
    {
        case 0:
            digitalWrite(ORANGE, 1);
            digitalWrite(YELLOW, 0);
            digitalWrite(PINK,   0);
            digitalWrite(BLUE,   0);
            break;
        case 1:
            digitalWrite(ORANGE, 0);
            digitalWrite(YELLOW, 1);
            digitalWrite(PINK,   0);
            digitalWrite(BLUE,   0);
            break;
        case 2:
            digitalWrite(ORANGE, 0);
            digitalWrite(YELLOW, 0);
            digitalWrite(PINK,   1);
            digitalWrite(BLUE,   0);
            break;
         case 3:
            digitalWrite(ORANGE, 0);
            digitalWrite(YELLOW, 0);
            digitalWrite(PINK,   0);
            digitalWrite(BLUE,   1);
            break;
         default:
            break;   
    }
 

}
void reverse_step_wave(int step) //4스텝
{
    switch(step)
    {
        case 3:
            digitalWrite(ORANGE, 1);
            digitalWrite(YELLOW, 0);
            digitalWrite(PINK,   0);
            digitalWrite(BLUE,   0);
            break;
        case 2:
            digitalWrite(ORANGE, 0);
            digitalWrite(YELLOW, 1);
            digitalWrite(PINK,   0);
            digitalWrite(BLUE,   0);
            break;
        case 1:
            digitalWrite(ORANGE, 0);
            digitalWrite(YELLOW, 0);
            digitalWrite(PINK,   1);
            digitalWrite(BLUE,   0);
            break;
         case 0:
            digitalWrite(ORANGE, 0);
            digitalWrite(YELLOW, 0);
            digitalWrite(PINK,   0);
            digitalWrite(BLUE,   1);
            break;
         default:
            break;   
    }
 
}
void step_wave_full(int step)
{
    switch(step)
    {
        case 0:
            digitalWrite(ORANGE, 1);
            digitalWrite(YELLOW, 1);
            digitalWrite(PINK,   0);
            digitalWrite(BLUE,   0);
            break;
        case 1:
            digitalWrite(ORANGE, 0);
            digitalWrite(YELLOW, 1);
            digitalWrite(PINK,   1);
            digitalWrite(BLUE,   0);
            break;
        case 2:
            digitalWrite(ORANGE, 0);
            digitalWrite(YELLOW, 0);
            digitalWrite(PINK,   1);
            digitalWrite(BLUE,   1);
            break;
         case 3:
            digitalWrite(ORANGE, 1);
            digitalWrite(YELLOW, 0);
            digitalWrite(PINK,   0);
            digitalWrite(BLUE,   1);
            break;
         default:
            break;   
    }

}
void step_wave_power(int step)
{
    switch(step)
    {
        case 0:
            digitalWrite(ORANGE, 1);
            digitalWrite(YELLOW, 1);
            digitalWrite(PINK,   1);
            digitalWrite(BLUE,   0);
            break;
        case 1:
            digitalWrite(ORANGE, 0);
            digitalWrite(YELLOW, 1);
            digitalWrite(PINK,   1);
            digitalWrite(BLUE,   1);
            break;
        case 2:
            digitalWrite(ORANGE, 1);
            digitalWrite(YELLOW, 0);
            digitalWrite(PINK,   1);
            digitalWrite(BLUE,   1);
            break;
         case 3:
            digitalWrite(ORANGE, 1);
            digitalWrite(YELLOW, 1);
            digitalWrite(PINK,   0);
            digitalWrite(BLUE,   1);
            break;
         default:
            break;   
    }

}
void step_half(int step)
{
     switch(step)
    {
        case 0:
            digitalWrite(ORANGE, 1);
            digitalWrite(YELLOW, 1);
            digitalWrite(PINK,   0);
            digitalWrite(BLUE,   0);
            break;
        case 1:
            digitalWrite(ORANGE, 0);
            digitalWrite(YELLOW, 1);
            digitalWrite(PINK,   0);
            digitalWrite(BLUE,   0);
            break;
        case 2:
            digitalWrite(ORANGE, 0);
            digitalWrite(YELLOW, 1);
            digitalWrite(PINK,   1);
            digitalWrite(BLUE,   0);
            break;
         case 3:
            digitalWrite(ORANGE, 0);
            digitalWrite(YELLOW, 0);
            digitalWrite(PINK,   1);
            digitalWrite(BLUE,   0);
            break;
        case 4:
            digitalWrite(ORANGE, 1);
            digitalWrite(YELLOW, 0);
            digitalWrite(PINK,   1);
            digitalWrite(BLUE,   1);
            break;
        case 5:
            digitalWrite(ORANGE, 0);
            digitalWrite(YELLOW, 0);
            digitalWrite(PINK,   0);
            digitalWrite(BLUE,   1);
            break;
        case 6:
            digitalWrite(ORANGE, 1);
            digitalWrite(YELLOW, 0);
            digitalWrite(PINK,   0);
            digitalWrite(BLUE,   1);
            break;
         case 7:
            digitalWrite(ORANGE, 1);
            digitalWrite(YELLOW, 0);
            digitalWrite(PINK,   0);
            digitalWrite(BLUE,   0);
            break;
         default:
            break;   
    }
}

int main(int argc, char ** agrv)
{
    wiringPiSetup(); //와이어링파이 넘버링으로 사용을한다 즉 와이어링파이숫자기준준
    pinMode(ORANGE, OUTPUT); //7번 아웃풋모드
    pinMode(YELLOW, OUTPUT);
    pinMode(PINK, OUTPUT);
    pinMode(BLUE, OUTPUT);
    pinMode(RED, OUTPUT);
    digitalWrite(RED,HIGH);
    printf("스텝모터 회전 시작 \n");

    while(1)
    for (int i=0; i <2048; i++) //half or full(wave)
    {
       if(strcmp(agrv[1],"1") ==0)
        step_wave_power(i%4);

       else if(strcmp(agrv[1],"2") ==0)
        step_half(i%8);

        else {
            printf("잘못된 입력\n");
            return 1;
        }

        delay(2); //step당 지연시간 필요(wave,full 2~,half:1~)
    }
    return 0;
}