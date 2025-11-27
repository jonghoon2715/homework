#include <stdio.h>                          // printf, scanf를 사용하기 위해서 헤더 추가
#include <stdlib.h>                         // rand, srand를 사용하기 위해서 헤더 추가
#include <time.h>                           // time 함수르르 사용하기 위해서 헤더 추가

int main(void)                          // 프로그램을 실행하는 main 함수
{                                       // 메인함수의 시작
    int ball[3];                        // 3개의 난수 저장 배열 
    srand(time(NULL));                  // 난수 초기화

    // 서로 다른 난수 생성
    do {
        ball[0] = rand() % 10;
        ball[1] = rand() % 10;
        ball[2] = rand() % 10;
    } while (ball[0] == ball[1] || ball[0] == ball[2] || ball[1] == ball[2]);    // 서로 중복일경우 난수 다시 생성 

    printf("baseball : %d %d %d\n", ball[0], ball[1], ball[2]);

    int strike_count = 0;               // strike_count 선언
    int ball_count = 0 ;                // baal_count 선언
    int out_count = 3 ;                 // out_count 선언

    while (strike_count != 3)           // 홈런이 아닐경우 반복
    {

        //3개의 숫자를 입력
        int input[3];
        printf("Enter the first number: ");
        scanf("%d", &input[0]);

        printf("Enter the second number: ");
        scanf("%d", &input[1]);

        printf("Enter the third number: ");
        scanf("%d", &input[2]);

        printf("input : %d %d %d\n", input[0], input[1], input[2]) ;     // 정답 출력

        int strike_count = 0;               // strike_count 선언
        int ball_count = 0 ;                // baal_count 선언
        int out_count = 3 ;                 // out_count 선언
        if( ball[0] == input[0] )       // strike
        {
            strike_count = strike_count + 1 ;
            out_count = out_count - 1 ;
        }
        if( ball[1] == input[1] )       // strike
    
        {
            strike_count = strike_count + 1 ;
            out_count = out_count - 1 ;
        }
        if( ball[2] == input[2] )     // strike
        {
            strike_count = strike_count + 1 ;
            out_count = out_count - 1 ;
        }
        if( ball[0] == input[1] )     // ball
        {
            ball_count = ball_count + 1 ;
            out_count = out_count - 1 ;
        }
        if( ball[0] == input[2] )     // ball
        {
            ball_count = ball_count + 1 ;
            out_count = out_count - 1 ;
        }
        if( ball[1] == input[0] )       // ball
        {
            ball_count = ball_count + 1 ;
            out_count = out_count - 1 ;
        }
    
        if( ball[1] == input[2] )       // ball
        {
            ball_count = ball_count + 1 ;
            out_count = out_count - 1 ;
        }
        if( ball[2] == input[1] )     // ball
        {
            ball_count = ball_count + 1 ;
            out_count = out_count - 1 ;
        }
        if( ball[2] == input[0] )       // ball
        {
            ball_count = ball_count + 1 ;
            out_count = out_count - 1 ;
        }
    

        // 홈런일경우
        if( ball[0] == input[0] && ball[1] == input[1] && ball[2] == input[2] )
        {
	        printf("Home Run~\n") ;
            break;    // 반복 종료
        }
        else
        {
            printf("%d Strike, %d Ball, %d Out\n", strike_count, ball_count, out_count) ;   // 결과 출력
        }

    }
    return 0;    // 프로그램 종료
}

