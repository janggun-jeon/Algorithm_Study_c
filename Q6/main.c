#define _CRT_SECURE_NO_WARNINGS // scanf 사용 허용 구문

#include <stdio.h> // c언어 표준 입출력 함수 헤더파일
#include <stdlib.h> // c언어 표준 라이브러리 : 숫자 변환 함수, 난수 생성 함수,메모리 할당 함수

//문제6 오름차순으로 정렬된 배열을 이진검색하는 함수를 작성하라.

int binary_search(const int a[], int n, int key) { // 일차원 배열을 이진 검색하는 함수(배열, 배열의 크기, 키값)
	int pl = 0; // 제일 앞쪽의 인덱스
	int pr = n - 1; // 제일 뒤쪽의 인덱스
	int pc; // 현재 선택된 인덱스

	do { // 검색을 최소 한번이상 함
		pc = (pl + pr) / 2; // 검색을 반복할 때 마다 pc 초기화

		if(a[pc] == key){ // 배열 요소에 키값이 있는 경우
			return pc; // 검색 성공, 해당 인덱스 반환
		}
		else if (a[pc] > key) {
			pr = pc - 1;
		}
		else {
			pl = pc + 1;
		}

	} while (pl <= pr); // 배열 요소에 키값이 없는 경우
	return -1; // 배열 요소에 키값이 없는 경우
}

void main() {
	int nx, ky, idx; // 배열의 크기, 키값, 인덱스
	int* x; // 동적 할당한 배열의 주소를 저장할 포인터
	printf("이진 검색\n");
	printf("요소 개수 : "); scanf("%d", &nx); // 배열의 크기값 결정

	x = calloc(nx, sizeof(int)); // 동적 배열 생성
	int i = 0;
	printf("오름차순으로 입력하세요.\n");
	while (i < nx) {
		printf("x[%d] : ", i); scanf("%d", &x[i++]); // 각 인덱스에 해당하는 값을 입력받음

		if (x[i - 2] > x[i - 1]) { // 오름차순 입력이 아니면 재입력하게 함
			printf("오름차순으로 입력하세요.\n");
			i--;
		}

	}

	printf("검색값 : "); scanf("%d", &ky); // 키값 설정
	idx = binary_search(x, nx, ky); // 검색

	if (idx == -1) {
		printf("검색실패");
	}
	else {
		printf("검색성공 : x[%d]에 있음", idx);
	}

}