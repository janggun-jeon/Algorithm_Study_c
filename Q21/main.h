#define _CRT_SECURE_NO_WARNINGS // 자료입력 허용구문
#define swap(type, x, y) do {type t = x; x = y; y = t;} while(0)

#include <stdio.h> // c언어 표준 라이브러리 : c언어에서의 입출력 함수
#include <string.h> // c언어 표준 라이브러리 : 문자열 허용 함수
#include <stdlib.h> // c언어 표준 라이브러리 : 숫자 변수 , 난수 생성, 메모리 할당

int compare(const void* a, const void* b);

/*  member.h */
#ifndef ___Member
#define ___Member

typedef struct {
	int no; // 번호
	char name[20];
} Member;

#define NO 1 // 번호를 나타내는 정수 값
#define NAME 2 // 이름을 나타내는 상수 값

int MemberNoCmp(const Member* x, const Member* y);

int MemberNameCmp(const Member* x, const Member* y);

void PrintMember(const Member* x);

Member ScanMember(const char* message, int sw);

#endif

/* list.h */
#ifndef ___List
#define ___List

typedef struct __node {
	Member data;
	struct __node* next;
} Node;

typedef struct {
	Node* head;
	Node* crnt; // current
} List;

void Initialize(List* list);

Node* search(List* list, const Member* x, int compare(const Member* x, const Member* y));

void InsertFront(List* list, const Member* x);

void InsertRear(List* list, const Member* x);

void RemoveFront(List* list);

void RemoveRear(List* list);

void RemoveCurrent(List* list);

void Clear(List* list);

void PrintCurrent(const List* list);

void Print(const List* list);

#endif 