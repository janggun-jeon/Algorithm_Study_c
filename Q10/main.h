#define _CRT_SECURE_NO_WARNINGS // scanf 사용 허용 구문

#include <stdio.h> // c언어 표준 입출력 함수 헤더파일
#include <stdlib.h> // c언어 표준 라이브러리 : 숫자 변환 함수, 난수 생성 함수,메모리 할당 함수

#ifndef ___IntQueue 
#define ___IntQueue

typedef struct { // 큐을 구현하는 구조체
	int max; // 큐의 최대 용량
	int num; // 현재의 요소개수
	int front; // 프런트
	int rear; // 리어
	int deck; // 인디큐 방향 선택
	int* que; // 큐의 맨앞 인덱스에 대한 포인터
} IntQueue;

int Initialize(IntQueue* q, int max);
int Enque(IntQueue* q, int x);
int Deque(IntQueue* q, int* x);
int Peek(const IntQueue* s, int* x);
void Clear(IntQueue* q);
int Capacity(const IntQueue* q);
int Size(const IntQueue* q);
int Search(IntQueue* q, int x);
void Print(IntQueue* q);
void Terminate(IntQueue* q);

#endif