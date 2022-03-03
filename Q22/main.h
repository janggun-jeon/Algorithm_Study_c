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
	int n; // ��ȣ
	char name[20];
} Member;

#define N 1 // ��ȣ�� ��Ÿ���� ���� ��
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
	struct __node* prev;
	struct __node* next;
} Node;

typedef struct {
	Node* head;
	Node* crnt; // current
} List;

void Initialize(List* list);

int Next(List* list);

int prev(List* list);

Node* search(List* list, const Member* x, int compare(const Member* x, const Member* y));

void InsertBefore(List* list, Node* p, const Member* x);

void InsertAfter(List* list, Node* p, const Member* x);

void InsertFront(List* list, const Member* x);

void InsertRear(List* list, const Member* x);

void RemoveThis(List* list, Node* p);

void RemoveFront(List* list);

void RemoveRear(List* list);

void RemoveCurrent(List* list);

void Clear(List* list);

void PrintCurrent(const List* list);

void Print(const List* list);

void PrintReverse(const List* list);

void Terminate(List* list);

#endif 