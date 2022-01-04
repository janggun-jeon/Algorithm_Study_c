#define _CRT_SECURE_NO_WARNINGS // scanf 사용 허용 구문

#include <stdio.h> // c언어 표준 입출력 함수 헤더파일
#include <time.h> // c언어 표준 라이브러리 : 시간함수
#include <stdlib.h> // c언어 표준 라이브러리 : 숫자 변환 함수, 난수 생성 함수,메모리 할당 함수

//문제4 함수 내부에 추가 변수를 선언하지 않고, 한 해의 지난 날 수를 구하는 프로그램(윤년을 고려해서)을 작성하라.

int mdays[][12] = {
	{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int isleap(int year) {
	return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

int dayofyear(int y, int m, int d) {
	m--;
	while (m--) {
		d += mdays[isleap(y)][m];
	}
	return d;
}

void main() {
	int year, month, day;	/* 년 월 일 */
	int retry;				/* 다시 한 번? */

		do {
			printf("년 : "); scanf("%d", &year);
			printf("월 : "); scanf("%d", &month);
			printf("일 : "); scanf("%d", &day);
	
			printf("%d 일째 \n", dayofyear(year, month, day));
		
			printf("다시 한 번 할까요?(1 예 / 0 아니오): ");
			scanf("%d", &retry);
		} while (retry == 1);
}