#define _CRT_SECURE_NO_WARNINGS // scanf 사용 허용 구문

#include <stdio.h> // c언어 표준 입출력 함수 헤더파일
#include <stdlib.h> // c언어 표준 라이브러리 : 숫자 변환 함수, 난수 생성 함수,메모리 할당 함수

#ifndef ___INTStack
#define ___INTStack

typedef struct { // 스택을 구현하는 구조체
	int max; // 스택의 용량
	int Aptr; // 스택A의 포인터
	int Bptr; // 스택B의 포인터
	int* stk; // 스택의 첫 요소에 대한 포인터
	int ab; // 작업할 스택을 선택
} INtStack;// 구조체 이름

int Initialize(INtStack* s, int max);
int Push(INtStack* s, int x);
int Pop(INtStack* s, int* x);
int Peek(const INtStack* s, int* x);
int Clear(INtStack* s);
int Capacity(const INtStack* s);
int Size(const INtStack* s);
int Search(INtStack* s, int x);
void Print(INtStack* s);
void Terminate(INtStack* s);

#endif