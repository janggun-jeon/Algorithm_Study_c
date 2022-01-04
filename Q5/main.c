#define _CRT_SECURE_NO_WARNINGS // scanf 사용 허용 구문

#include <stdio.h> // c언어 표준 입출력 함수 헤더파일
#include <stdlib.h> // c언어 표준 라이브러리 : 숫자 변환 함수, 난수 생성 함수,메모리 할당 함수

//문제5 배열검색 중 선형검색기법를 사용하는 함수와 그 과정을 단계적으로 표시하는 프로그램을 작성하라.

/*선형검색 함수를 작성하는 것과 그 과정을 표시할때 시각적으로 이해할 수 있게만 하면 되기 때문에, 기호표시의 간결함을 위해
-> 배열의 각 인덱스값들을 최대 두자릿수로 제한*/

int search(int a[], int n, int key) { // 일차원 배열을 선형 검색하는 함수(배열, 배열의 크기, 키값)
	int i = 0; // i로 a[0]부터 검색

	do { // 검색을 최소 한번이상 함
		int j = 0;
		printf("\n   |  "); printf("%*s", 3 * i,"");
		printf("*\n%3d|", i); for (j = 0; j < n; j++) printf("%3d", a[j]);

		if (a[i] == key) { // 배열 요소에 키값이 있는 경우
			return i; // 검색 성공,해당 인덱스 반환
		}

		i++; // 다음 요소를 검색하기 위해 i증가
	} while (i < n); // 배열 요소에 키값이 없는 경우

	return -1; // 배열 요소에 키값이 없는 경우
}

void main() {
	int nx, ky, idx; // 배열의 크기, 키값, 인덱스
	int* x; // 동적 할당한 배열의 주소를 저장할 포인터
	printf("선형 검색 과정\n");
	printf("요소 개수 : "); scanf("%d", &nx); // 배열의 크기값 결정

	x = calloc(nx, sizeof(int)); // 동적 배열 생성
	int i = 0;
	while (i < nx) {
		printf("x[%d] : ", i); scanf("%d", &x[i++]); // 각 인덱스에 해당하는 값을 입력받음
		if (x[i - 1] >= 100) {
			i--;
			printf("두자릿수 이하의 입력만 가능합니다.\n");
		}
	}

	printf("검색값 : "); scanf("%d", &ky); // 키값 설정
	printf("   |");
	for (i = 0; i < nx; i++)  printf("%3d", i);

	printf("\n---+");
	for (i = 0; i < nx; i++) printf("---");
	idx = search(x, nx, ky); // 검색
	
	if (idx == -1) {
		printf("\n\n검색실패");
	}
	else {
		printf("\n\n검색성공 : x[%d]에 있음", idx);
	}
}