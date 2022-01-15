#define _CRT_SECURE_NO_WARNINGS // scanf 사용 허용 구문
#define swap(type, x, y) do {type t = x; x = y; y = t;} while(0)

#include <stdio.h>
#include <stdlib.h>

//문제12 버블정렬의 패스과정을 단계적으로 출력하고, 비교횟수와 교환횟수를 구할 수 있는 프로그램을 작성하라.

int bubble(int a[], int n) {
	int i, j, k;
	int change = 0;
	for  (i = 0; i < n - 1; i++) {
		printf("패스%d :\n", i + 1);

		for (j = n - 1;j > i ; j--) {

			for (k = 0; k < j - 1; k++) {
				printf("%d", a[k]);
				printf("%3s", "");
			}

			if (a[j - 1] > a[j]) {
				swap(int, a[j - 1], a[j]);
				printf("%d<->%d", a[j - 1], a[j]);
				change++;
			}
			else {
				printf("%d---%d", a[j - 1], a[j]);
			}

			for (k = j + 1; k < n; k++) {
				printf("%3s", "");
				printf("%d", a[k]);	
			}
			putchar('\n');
		}
	}
	return change;
}



void main() {
	int i, nx, cng;
	int* x;

	puts("버블 정렬");
	printf("요소 개수 : "); scanf("%d", &nx);
	x = calloc(nx, sizeof(int));

	for (i = 0; i < nx; i++) {
		printf("x[%d] : ", i); scanf("%d", &x[i]);
	}

	cng = bubble(x, nx);

	printf("오름차순으로 정렬");
	for  (i = 0; i < nx; i++) {
		printf("\nx[%d] = %d", i, x[i]);
	}

	free(x);
	printf("\n비교횟수 : %d\n교환횟수 : %d", (nx * (nx - 1)) / 2, cng);
}