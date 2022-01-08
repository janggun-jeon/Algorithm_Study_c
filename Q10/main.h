#define _CRT_SECURE_NO_WARNINGS // scanf ��� ��� ����

#include <stdio.h> // c��� ǥ�� ����� �Լ� �������
#include <stdlib.h> // c��� ǥ�� ���̺귯�� : ���� ��ȯ �Լ�, ���� ���� �Լ�,�޸� �Ҵ� �Լ�

#ifndef ___IntQueue 
#define ___IntQueue

typedef struct { // ť�� �����ϴ� ����ü
	int max; // ť�� �ִ� �뷮
	int num; // ������ ��Ұ���
	int front; // ����Ʈ
	int rear; // ����
	int deck; // �ε�ť ���� ����
	int* que; // ť�� �Ǿ� �ε����� ���� ������
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