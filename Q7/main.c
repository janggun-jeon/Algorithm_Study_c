#define _CRT_SECURE_NO_WARNINGS // scanf 사용 허용 구문

#include <stdio.h> // c언어 표준 입출력 함수 헤더파일
#include <stdlib.h> // c언어 표준 라이브러리 : 숫자 변환 함수, 난수 생성 함수,메모리 할당 함수

//문제7 내림차순으로 정렬된 long형 배열을 bsearch 함수를 이용해 검색하라.

long long_cmp(const void *a, const void *b){ // bsearch 함수는 배열의 오름차순 정렬을 기준으로 한 함수
	if (*(long*)a > *(long*)b) return -1; // 내림차순 정렬을 기준으로 검색을 하기 위해서는
	if (*(long*)a < *(long*)b) return 1; // 비교함수의 양수, 음수 반환값들을 서로 교환해야함
	else return 0;
}
void main() {
	long nx, ky; // 배열의 크기, 키값
	long* x; long* idx; // 동적 할당한 배열 요소의 주소를 저장할 포인터
	printf("bsearch 함수를 사용해 검색\n");
	printf("요소 개수 : "); scanf("%d", &nx); // 배열의 크기값 결정

	x = calloc(nx, sizeof(long)); // 동적 배열 생성
	long i = -1;
	while (++i < nx) {
		printf("x[%d] : ", i); scanf("%d", &x[i]); // 각 인덱스에 해당하는 값을 입력받음

		if (i == 0) {}
		else if (x[i - 1] < x[i]) { // 내림차순 입력이 아니면 재입력하게 함
			printf("내림차순으로 입력하세요.\n");
			i--;
		}

	}

	printf("검색값 : "); scanf("%d", &ky); // 키값 설정
	idx = bsearch // 검색
	(&ky, // 검색값 객체의 주소
		x, // x배열의 포인터
		nx, // 배열크기
		sizeof(long), // 배열의 자료형에 해당하는 메모리 생성크기
		(long(*)(const void*, const void*))long_cmp // void형 인자를 받아 int형 반환값을 갖는 비교함수의 주소
	);

	if (idx == NULL) {
		printf("검색실패");
	}
	else {
		printf("검색성공 : x[%d]에 있음", (idx - x)); // idx가 x[검색된 인덱스]의 주소를 나타내기 때문에, [인덱스 = idx와 x의 주소간 차이]로 구할 수 있음
	}

}