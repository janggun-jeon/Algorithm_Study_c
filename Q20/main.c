#define _CRT_SECURE_NO_WARNINGS // 자료입력 허용구문
#define swap(type, x, y) do {type t = x; x = y; y = t;} while(0)

#include <stdio.h> // c언어 표준 라이브러리 : c언어에서의 입출력 함수
#include <stdlib.h> // c언어 표준 라이브러리 : 숫자 변수 , 난수 생성, 메모리 할당

//문제20 도수 정렬 알고리즘을 작성하라.

void wsort(int a[], int n, int min,int max) {
	int i;
	int* w = calloc(max + 1, sizeof(int)); // 누적 도수 구현용 배열
	int* b = calloc(n, sizeof(int)); // 결과 저장 작업용 배열

	i = 0;
	while (i <= max) { // w[]의 모든 값을 0으로 초기화
		w[i] = 0;
		i++;
	}
	
	i = 0;
	while (i < n) { // a[]의 요소값들을 인덱스로 가지는 w[a[]]의 요소값들을 중복 카운트
		w[a[i]]++;
		i++;
	}
	
	i = 1;
	while (i <= max) { // w[]의 요소값을 오름차순으로 누적덧셈, 따라서 a[]가 작을수록 w[a[]]도 작아지는 관계가 형성
		w[i] += w[i - 1];
		i++;
	}

	i = n - 1;
	while (i >= 0) { // a[]의 각 요소값들은 작을수록, b[w[a[]] - 1]의 작은 인덱스에 해당하는 요소에 복사됨
		b[--w[a[i]]] = a[i];
		i--;
	}
	
	i = 0;
	while (i < n) { // a[]의 요소들이 오름차순으로 저장된 b[]를 a[]에 복사
		a[i] = b[i];
		i++;
	}
	
	free(b), free(w);
}

void main() {
	int i, n;
	const int min, max;
	int* x;

	puts("도수 정렬\n");
	puts("min ~ max 범위의 정수를 입력하라");
	printf("min : "); scanf("%d", &min);
	printf("max : "); scanf("%d", &max);
	printf("\n요소 개수 : "); scanf("%d", &n);
	x = calloc(n, sizeof(int));

	i = 0;
	while (i < n) {
			printf("x[%d] : ", i); scanf("%d", &x[i++]);
			if ((x[i - 1] < min) || (max < x[i - 1])) {
				printf("%d ~ %d 범위의 정수를 입력하라\n", min, max);
				i--;
			}
	}

	wsort(x, n, min, max);
	puts("\n오름차순으로 정렬됨");

	i = 0;
	while (i < n) {
		printf("x[%d] = %d\n", i, x[i++]);
	}

	free(x);
}