#define _CRT_SECURE_NO_WARNINGS // scanf 사용 허용 구문

#include <stdio.h> // c언어 표준 입출력 함수 헤더파일
#include <stdlib.h> // c언어 표준 라이브러리 : 숫자 변환 함수, 난수 생성 함수,메모리 할당 함수

//문제17 qsort 함수를 이용해 다음 배열
//char a[][7] = { "LISP", "C", "Ada", "Pascal" }; 와(과)
//char* p[] = { "LISP", "C", "Ada", "Pascal" }; 을(를)
//알파벳순 정렬하는 프로그램을 작성하라.

int ascmp(const char* a, const char* b) { // 문자열 비교 함수
	return strcmp(a, b);
}
int pscmp(const char** a, const char** b) { // 문자열 비교 함수
	return strcmp(*a, *b);
}
void main() {
	int i;
	char a[][7] = { "LISP", "C", "Ada", "Pascal" };
	char* p[] = { "LISP", "C", "Ada", "Pascal" };
	int na = sizeof(a) / sizeof(a[0]); // 4
	int np = sizeof(p) / sizeof(p[0]); // 4
	
	qsort(a, na, sizeof(a[0]) /* == 7 */, (int(*)(const void* a, const void* b))ascmp);
	qsort(p, np, sizeof(p[0]) /* == sizeof(char*) */, (int(*)(const void* a, const void* b))pscmp);

	i = 0;
	while (i < na) { printf("%s\n", a[i++]); }
	i = 0;
	while (i < np) { printf("%s\n", p[i++]); }
}