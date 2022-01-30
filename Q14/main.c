#define _CRT_SECURE_NO_WARNINGS // 자료입력 허용구문
#define swap(type, x, y) do {type t = x; x = y; y = t;} while(0)

#include <stdio.h> // c언어 표준 라이브러리 : c언어에서의 입출력 함수
#include <stdlib.h> // c언어 표준 라이브러리 : 숫자 변수 , 난수 생성, 메모리 할당

//문제14 단순 삽입 정렬에서, call by reference 방식으로 비교횟수를 구하도록 프로그램을 작성하라.

void insertion(int a[], int n, int** cmp) {
	int i = 1;
	(**cmp) = 0;
	while (i < n) {
		int tmp = a[i];
		int j = i;		
		while ( ++(**cmp) && (j > 0 && a[j - 1] > tmp) ) {
			a[j] = a[j - 1];
			j--;		
		}
		a[j] = tmp;
		i++;
	}
}

void main() {
	int i, nx;
	int* x;
	int* compar;
	compar = malloc(sizeof(int));
	

	puts("단순 삽입 정렬");
	printf("요소 개수 : "); scanf("%d", &nx);
	x = calloc(nx, sizeof(int));

	for (i = 0; i < nx; i++) {
		printf("x[%d] : ", i); scanf("%d", &x[i]);
	}

	insertion(x, nx, &compar);

	printf("오름차순으로 정렬");
	for (i = 0; i < nx; i++) {
		printf("\nx[%d] = %d", i, x[i]);
	}

	printf("\n비교횟수 : %d", *compar);
	free(x);
}