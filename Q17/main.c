#define _CRT_SECURE_NO_WARNINGS // scanf ��� ��� ����

#include <stdio.h> // c��� ǥ�� ����� �Լ� �������
#include <stdlib.h> // c��� ǥ�� ���̺귯�� : ���� ��ȯ �Լ�, ���� ���� �Լ�,�޸� �Ҵ� �Լ�

//����17 qsort �Լ��� �̿��� ���� �迭
//char a[][7] = { "LISP", "C", "Ada", "Pascal" }; ��(��)
//char* p[] = { "LISP", "C", "Ada", "Pascal" }; ��(��)
//���ĺ��� �����ϴ� ���α׷��� �ۼ��϶�.

int ascmp(const char* a, const char* b) { // ���ڿ� �� �Լ�
	return strcmp(a, b);
}
int pscmp(const char** a, const char** b) { // ���ڿ� �� �Լ�
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