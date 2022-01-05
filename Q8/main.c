#define _CRT_SECURE_NO_WARNINGS // scanf 사용 허용 구문
#include <stdio.h> // c언어 표준 입출력 함수 헤더파일
#include <string.h> // c언어 표준 라이브러리 : 문자열 허용 함수
#include <stdlib.h> // c언어 표준 라이브러리 : 숫자 변환 함수, 난수 생성 함수,메모리 할당 함수

//문제8 기존 bsearchx 함수의 선언형태를 고려하려 직접 정의를 작성하시오.

void* bsearchx // ( (besearch 함수)&&(검색값이 여럿일때, 가장 빠른 인덱스의 포인터 반환) )하는 함수
	(const void* key, // 검색값 주소
	const void* a, // 검색할 배열
	int n, // 배열크기
	int size, // 배열자료형에 따른 메모리 크기
	int(*compar)(const int*, const int*))  // 비교함수의 주소를 저장할 포인터 compar
	{
	int pl = 0; // 제일 앞쪽의 인덱스
	int pr = n - 1; // 제일 뒤쪽의 인덱스
	int pc; // 현재 선택된 인덱스
	int* x = a; // 윈도우에서 a를 컴파일러가 포인터가 아닌 주소 그 자체로만 인식, 따라서 그 주소를 새로 포인터를 선언해서 저장해야함

	do { // 이진검색을 최소 한번이상 함
		pc = ((pl + pr) / 2); // 검색을 반복할 때 마다 pc 초기화
		int cmp = compar(&x[pc], key); // 여기서 compar의 역할은 [compar 함수 이름 = 비교함수의 포인터]가 아닌, 비교함수의 호출  

		if (cmp == 0) { // 배열 요소에 키값이 있는 경우
			
			while (1) { // 검색값의 가장 낮은 인덱스를 찾아 선형검색을 반복
				cmp = compar(&x[(--pc)], key);
				
				if (cmp != 0) {
					return &x[(++pc)];
				}	
			}
		}
		else if (pl > pr) {
			return NULL;
		}
		else if (cmp > 0) { 
			pl = pc + 1; 
		}
		else {
			pr = pc - 1;
		}
	} while (1); 	
}

int int_cmp(const int *a, const int *b) { // 비교함수
	if (*a > *b) return -1;
	else if (*a < *b) return 1;
	else if(*a == *b) return 0;
}

void main() { // 메인함수
	int i = 0; // 반복입력을 위한 카운터
	int nx, ky; // 동적 배열 크기, 검색값
	int* x; int* idx; // 동적 배열 주소, 찾고 싶은 배열[인덱스]의 주소
	printf("bsearchx 함수\n요소 개수 : "); scanf("%d", &nx);
	x = calloc(nx, sizeof(int)); // 동적 배열 주소 할당

	while (i < nx) {
		printf("x[%d] : ", i); scanf("%d", &x[i++]);

		if (x[i - 2] > x[i - 1]) {
			printf("오름차순으로 입력하시오\n"); // bsearch 함수는 오름차순 정렬을 가정한 함수
			i--;
		}
	}
	printf("검색값 : "); scanf("%d", &ky);
	idx = bsearchx // bsearch 함수 호출
	(&ky,
		x,
		nx,
		sizeof(int),
		 int_cmp); // (int(*)(const int*, const int*))

	if (idx == NULL) {
		printf("검색실패");
	}
	else {
		printf("x[%d] = %d", (idx - x), ky); 
	}
}