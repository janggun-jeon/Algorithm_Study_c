#define _CRT_SECURE_NO_WARNINGS // scanf 사용 허용 구문

#include <stdio.h> // c언어 표준 입출력 함수 헤더파일

//문제2 구분선이 있는 9*9곱셈표를 출력하는 프로그램을 작성하라.

void main() {
	int i, j;
	printf("   |");
	for (i = 1; i <= 9; i++) {
		printf("% 3d", i);
	}
	printf("\n---+");
	for (i = 1; i <= 9; i++) {
		printf("---");
	}
	for (i = 1; i <= 9; i++) {
		printf("\n %d |", i);
		for (j = 1; j <= 9; j++) {
			printf("% 3d", i * j);
		}
	}
}