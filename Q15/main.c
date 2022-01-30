#define _CRT_SECURE_NO_WARNINGS // 자료입력 허용구문
#define swap(type, x, y) do {type t = x; x = y; y = t;} while(0)

#include <stdio.h> // c언어 표준 라이브러리 : c언어에서의 입출력 함수
#include <stdlib.h> // c언어 표준 라이브러리 : 숫자 변수 , 난수 생성, 메모리 할당

//문제15 셀정렬에서 반복수행된 처리들의 횟수를 출력하도록 프로그램을 작성하라.

int* shell(int a[], int n) {
	int* rtct = calloc(4, sizeof(int)); // 함수에서 반복된 연산&비교&대입 등의 횟수를 저장
	int cmp = 0; // 요소 간의 비교횟수
	int mov = 0; // 요소 이동 횟수
	int insert = 0; // 반드시 필요한 삽입의 갯수
	int sort = 0; // 수행한 각 h-정렬 종류 갯수
	int h = 0;
	while (h < (n / 3)) {
		h = h * 3 + 1;
		sort++;
	}
	while (h > 0) {
		int i = h;
		while (i < n) {
			int tmp = a[i];
			int j = i - h;
			while (++cmp && (j >= 0 && a[j] > tmp)) { // while문 조건불만족 경우라도 비교자체는 했기때문에 cmp 카운트
				a[j + h] = a[j];
				mov++; // 조건이 참일때 요소 이동 후 이동횟수 카운트
				j -= h;
			}
			if (a[j + h] != tmp) { //요소 삽입 필요여부를 알기위해서 비교, 실제 셀정렬에서 이 비교는 수행하지 않아서 cmp 노카운트 
				a[j + h] = tmp; 
				insert++; // j + h == i 이거나 a[j + h] == a[i] 일때는 실제로 삽입을 하지만 필요없음 
			}		
			i++;
		}
		h /= 3;
	}
	rtct[0] = cmp; 
	rtct[1] = mov; 
	rtct[2] = insert;
	rtct[3] = sort;
	return rtct;
}
	
void main() {
	int i, nx;
	int* x;
	int* RepeatCount;
	
	
	puts("셀 정렬");
	do { printf("요소 개수(3이상) : "); scanf("%d", &nx); } while (nx < 3);
	x = calloc(nx, sizeof(int));

	for (i = 0; i < nx; i++) {
		printf("x[%d] : ", i); scanf("%d", &x[i]);
	}

	RepeatCount = shell(x, nx);

	printf("오름차순으로 정렬");
	for (i = 0; i < nx; i++) {
		printf("\nx[%d] = %d", i, x[i]);
	}

	printf("\n비교 횟수 : %d", RepeatCount[0]);
	printf("\n요소 이동 횟수 : %d", RepeatCount[1]);
	printf("\n유효한 삽입의 횟수 : %d", RepeatCount[2]);
	printf("\nh-정렬 횟수 : %d", RepeatCount[3]);
	free(x);
	free(RepeatCount);
}