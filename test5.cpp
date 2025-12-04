#include <stdio.h>      //ㅐPRINTF, scanf를 사용하기 위해서 헤더 추가
#include <stdlib.h>    // rand, srand를 사용하기 위해서 헤더 추가
#include <time.h>   // time 함수를 사용하기 위해서 헤더 추가

int main(void)      //프로그램을 실행하는 main 함수
{                   //메인함수의 시작
    int ball[3]; // 3개의 난수 저장 배열
    srand(time(NULL)); // 난수 초기화

    // 중복 없는 3자리 난수 생성
    do {
        ball[0] = rand() % 10;
        ball[1] = rand() % 10;
        ball[2] = rand() % 10;
    } while (ball[0] == ball[1] || ball[0] == ball[2] || ball[1] == ball[2]);  // 숫자 중복 시 다시 생성

    //printf("baseball : %d %d %d\n", ball[0], ball[1], ball[2]); // 정답 확인용(테스트시만)

    int input[3];  // 플레이어 입력 3자리 숫자 저장
    int strike_count = 0 ;   // strike_count 초기값 설정
    int ball_count = 0 ;    // ball_count 초기값 설정
    int out_count = 0;      // out_count 초기값 설정
    int try_count = 0;      // try_count 초기값 설정

    clock_t start, end;     // 시간 측정을 위한 변수
    start = clock(); // 게임 시작 시간 기록

    while (1) {     // 반복 시작
        printf("\n숫자 3개를 입력하세요 (공백으로 구분): \n");        // 플레이어 숫자 입력
        scanf("%d %d %d", &input[0], &input[1], &input[2]);     // 플레이어 입력 숫자 출력

        // 반복시 초기값 초기화 설정
        strike_count = 0;       
        ball_count = 0;

        // strike, ball 판정
        for (int i = 0; i < 3; i++) {       // strike, ball 판정 시작
            if (input[i] == ball[i]) // 같은자리 + 같은 숫자 = strike
            {   // if 시작
                strike_count++;  
            }   // if 끝
            else if (input[i] == ball[(i+1)%3] || input[i] == ball[(i+2)%3]) // 다른자리 + 같은숫자 = ball
            {   // else if 시작
                ball_count++;   
            }   // else if 끝
        }       // strike, ball 판정 끝 

        out_count = 3 - (strike_count + ball_count);        // strike와 ball을 제외한 나머지 out
        
        try_count++;    // 한번 시도 할 때마다 try
        // 다 맞췄을 경우
        if (strike_count == 3) // strike_count가 3일시
            {        // if 함수 시작
            end = clock(); // 게임 종료 시간 기록            
            double elapsed_sec = (double)(end - start) / CLOCKS_PER_SEC;    // 걸린시간 계산
            printf("Home Run! %d번 만에 맞췄습니다!\n", try_count);     // 홈런 및 시도 횟수 출력
            printf("%f 초 시간이 걸렸습니다.\n", elapsed_sec);      // 걸린시간 출력
            break;      // 종료
            }       // if 함수 끝
        else        // 틀렸을시 다시
            {       // else 시작
            printf("%d Strike, %d Ball, %d Out\n", strike_count, ball_count, out_count);    // 결과 출력
            }       // else 끝
    }   // 반복 끝
    return 0;   // 프로그램 정상 종료
}   // 메인함수의 끝
