#define _CRT_SECURE_NO_WARNINGS // 자료입력 허용구문

#include <stdio.h> // c언어 표준 라이브러리 : c언어에서의 입출력 함수

// 문제1 '1 + ... + n = 1부터 n까지의 합' 형태로 출력하는 정수합 코드를 작성하라.

void main() {

	int i;
	int n;
	int sum = 1;

	printf("1부터 n까지의 합을 구한다.\n");
	printf("n의 값 : ");
	scanf("%d", &n);

	printf("1부터 %d까지의 합\n : 1", n);

	for (i = 2; i <= n; i++) {
		sum += i;
		printf(" + %d", i);
	}

	printf(" = %d", sum);

}