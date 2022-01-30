#define _CRT_SECURE_NO_WARNINGS // scanf 사용 허용 구문
#define swap(type, x, y) do {type t = x; x = y; y = t;} while(0)

#include <stdio.h> // c언어 표준 입출력 함수 헤더파일
#include <stdlib.h> // c언어 표준 라이브러리 : 숫자 변환 함수, 난수 생성 함수,메모리 할당 함수

//문제16 퀵정렬(기본적인 알고리즘보다 효율이 더 좋게)과 그 과정을 출력하는 프로그램을 작성하라. 

void quick(int a[], int left, int right) {
	int i;
	int pl = left;
	int pr = right;
	int x = a[(pl + pr) / 2];

	printf("\n피벗의 값은 %d\n", x);
	do {
		while (a[pl] < x) { pl++; }
		while (a[pr] > x) { pr--; }
		if (pl <= pr) {
			swap(int, a[pl], a[pr]);
			pl++;
			pr--;
		}
	} while (pl <= pr);

	puts("피벗 이하의 그룹");
	i = left;
	printf("x[%d] ~ x[%d] : ", i, pl - 1);
	while (i <= pl - 1) { printf("%d ", a[i++]); }
	putchar('\n');

	if (pl > pr + 1) {
		puts("피벗과 일치하는 그룹");
		i = pr + 1;
		if (pr + 1 == pl - 1) { printf("x[%d] : ", pr + 1); }
		while (i <= pl - 1) { printf("%d ", a[i++]); }
		putchar('\n');
	}

	puts("피벗 이상의 그룹");
	i = pr + 1;
	printf("x[%d] ~ x[%d] : ", i, right);
	while (i <= right) { printf("%d ", a[i++]); }
	putchar('\n');

	if (left < pr) { quick(a, left, pr); }
	if (pl < right) { quick(a, pl, right); }
}

void main() {
	int i, j, n;
	int* x;
	puts("퀵 정렬");
	printf("요소 개수 : "); scanf("%d", &n); putchar('\n');
	x = calloc(n, sizeof(int));
	i = 0;
	while (i < n) {
		printf("x[%d] : ", i); scanf("%d", &x[i++]);
	}
	quick(x, 0, n - 1);
	j = 0;
	while (j < n) { 
		printf("\nx[%d] : %d", j, x[j]);
		j++;
	}
	free(x);
}