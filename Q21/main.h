#define _CRT_SECURE_NO_WARNINGS // �ڷ��Է� ��뱸��
#define swap(type, x, y) do {type t = x; x = y; y = t;} while(0)

#include <stdio.h> // c��� ǥ�� ���̺귯�� : c������ ����� �Լ�
#include <string.h> // c��� ǥ�� ���̺귯�� : ���ڿ� ��� �Լ�
#include <stdlib.h> // c��� ǥ�� ���̺귯�� : ���� ���� , ���� ����, �޸� �Ҵ�

int compare(const void* a, const void* b);

/*  member.h */
#ifndef ___Member
#define ___Member

typedef struct {
	int no; // ��ȣ
	char name[20];
} Member;

#define NO 1 // ��ȣ�� ��Ÿ���� ���� ��
#define NAME 2 // �̸��� ��Ÿ���� ��� ��

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