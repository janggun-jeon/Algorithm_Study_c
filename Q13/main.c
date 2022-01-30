#define _CRT_SECURE_NO_WARNINGS // scanf 사용 허용 구문
#define swap(type, x, y) do {type t = x; x = y; y = t;} while(0)

#include <stdio.h>
#include <stdlib.h>

//문제13 양방향 버블 정렬(셰이커 정렬)를 수행하는 프로그램을 작성하라.

int shaker(int a[], int n)
{
	int left = 0;
	int right = n - 1;
	int last = right;
	int change; // 개별패스 내부 교환횟수를 카운팅
	int count = 0; // 비교횟수를 카운팅

	while (left < right) {
		int i;
		for (i = right; i > left; i--) {
			change = 0;
			if (a[i - 1] > a[i]) {
				swap(int, a[i - 1], a[i]);
				last = i;
				change++;
				count++;
			}
		}
		if (change == 0) { return count; } // 패스 내부에 교환이 없다면, 정렬종료
		left = last; // 마지막 교환 인덱스 앞(보다 낮은번호, left 방향)은 비교대상에서 제외

		for (i = left; i < right; i++) {
			change = 0;
			if (a[i] > a[i + 1]) {
				swap(int, a[i], a[i + 1]);
				last = i;
				change++;
				count++;
			}
		}
		if (change == 0) { return count; } // 패스 내부에 교환이 없다면, 정렬종료
		right = last; // 마지막 교환이 일어난 인덱스 뒤(보다 높은번호, right 방향)는 비교대상에서 제외
	}
	return count;
}

void main(void)
{
	int i, nx;
	int* x;

	puts("양방향 버블 정렬");
	printf("요소 개수 : ");
	scanf("%d", &nx);
	x = calloc(nx, sizeof(int));

	for (i = 0; i < nx; i++) {
		printf("x[%d] : ", i);
		scanf("%d", &x[i]);
	}

	int compar = shaker(x, nx);

	puts("오름차순으로 정렬");
	for (i = 0; i < nx; i++)
		printf("x[%d] = %d\n", i, x[i]);

	free(x);
	printf("비교횟수 : %d회", compar);
}