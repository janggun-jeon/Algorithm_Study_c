#define _CRT_SECURE_NO_WARNINGS // scanf 사용 허용 구문

#include <stdio.h> // c언어 표준 입출력 함수 헤더파일
#include <time.h> // c언어 표준 라이브러리 : 시간함수
#include <stdlib.h> // c언어 표준 라이브러리 : 숫자 변환 함수, 난수 생성 함수,메모리 할당 함수

//문제3 난수를 사용해 배열의 요소값들을 설정하고 다시 역순으로 정렬하라.

void swap(int* x, int* y) { // 두 입력 객체의 값을 포인터를 통해 교환하는 함수
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

void main() {
	int* array; // 동적 객체를 호출할 포인터
	int size;
	printf("배열의 크기 : ");
	scanf("%d", &size);

	array = calloc(size, sizeof(int)); // size만큼 요소를 갖는 배열 생성 
	int i;
	int n = size;
	srand(time(NULL)); // 시간으로 난수의 seed를 초기화

	for (i = 0; i < size; i++) {
		array[i] = rand() % 99; // 0~지정한 숫자 범위에서 난수 생성
		printf("array[%d] = %d\n", i, array[i]); // 생성된 배열의 요소값들을 출력
	}

	printf("all array elements swap!!\n");

	for (i = 0; n >= i + 1; i++) {
		n = size - 1 - i;
		swap(&array[i], &array[n]); // 배열 요소들을 역순이 되게 교환
	}

	for (i = 0; i < size; i++) {
		printf("array[%d] = %d\n", i, array[i]); // 역순으로 재정렬한 배열의 요소값들을 출력
	}
}