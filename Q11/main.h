#define _CRT_SECURE_NO_WARNINGS // scanf ��� ��� ����

#include <stdio.h> // c��� ǥ�� ����� �Լ� �������
#include <stdlib.h> // c��� ǥ�� ���̺귯�� : ���� ��ȯ �Լ�, ���� ���� �Լ�,�޸� �Ҵ� �Լ�

#ifndef ___INTStack
#define ___INTStack

typedef struct { // ������ �����ϴ� ����ü
	int max; // ������ �뷮
	int Aptr; // ����A�� ������
	int Bptr; // ����B�� ������
	int* stk; // ������ ù ��ҿ� ���� ������
	int ab; // �۾��� ������ ����
} INtStack;// ����ü �̸�

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