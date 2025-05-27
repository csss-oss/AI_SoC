#include <stdio.h>
#include <wiringPi.h>
#include <softPwm.h> 
#include <stdlib.h>

#define SERVO    29
int main(int n, char **s) { //servo [회전각도 0~180] //동적인형태로 왔다갔다 만들기기

    if(n<2)
    {
        printf("Usage : servo[Rotate degree(0~90)]");
        return 0;
    }
    int r; // cLI회전각도 (0~180)
    r = atoi(s[1]);
    r = r * 1000 / 180 ; //micro_delay value //수직을 움직이는 나타내는 변위위
    wiringPiSetup(); //wpi pin번호 사용
    pinMode(SERVO,OUTPUT);
    printf("%d\n",r);
    for(int i =0; i<50;i++)
    {
        int r1 = 1500 +r *((i%2)?(-1):1);
        for(int j = 0; j<30; j++)
        {
        digitalWrite(SERVO,HIGH);
        delayMicroseconds(r1);// 펈스폭 1ms  = 90 degree
        digitalWrite(SERVO,LOW);
        delayMicroseconds(20000 - r1);//19ms + 1ms = 20ms =50HZ 이러한 주기를 완성
        }
    }
   
    return 0;
}

/*
커맨드라인에 입력받은 값을 숫자로 바꿔서 그값을 딜레이로 줘서 펄스폭을 만든다음에 
주기를 일정하게 만드는 연습
*/