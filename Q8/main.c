#define _CRT_SECURE_NO_WARNINGS // scanf ��� ��� ����
#include <stdio.h> // c��� ǥ�� ����� �Լ� �������
#include <string.h> // c��� ǥ�� ���̺귯�� : ���ڿ� ��� �Լ�
#include <stdlib.h> // c��� ǥ�� ���̺귯�� : ���� ��ȯ �Լ�, ���� ���� �Լ�,�޸� �Ҵ� �Լ�

//����8 ���� bsearchx �Լ��� �������¸� ����Ϸ� ���� ���Ǹ� �ۼ��Ͻÿ�.

void* bsearchx // ( (besearch �Լ�)&&(�˻����� �����϶�, ���� ���� �ε����� ������ ��ȯ) )�ϴ� �Լ�
	(const void* key, // �˻��� �ּ�
	const void* a, // �˻��� �迭
	int n, // �迭ũ��
	int size, // �迭�ڷ����� ���� �޸� ũ��
	int(*compar)(const int*, const int*))  // ���Լ��� �ּҸ� ������ ������ compar
	{
	int pl = 0; // ���� ������ �ε���
	int pr = n - 1; // ���� ������ �ε���
	int pc; // ���� ���õ� �ε���
	int* x = a; // �����쿡�� a�� �����Ϸ��� �����Ͱ� �ƴ� �ּ� �� ��ü�θ� �ν�, ���� �� �ּҸ� ���� �����͸� �����ؼ� �����ؾ���

	do { // �����˻��� �ּ� �ѹ��̻� ��
		pc = ((pl + pr) / 2); // �˻��� �ݺ��� �� ���� pc �ʱ�ȭ
		int cmp = compar(&x[pc], key); // ���⼭ compar�� ������ [compar �Լ� �̸� = ���Լ��� ������]�� �ƴ�, ���Լ��� ȣ��  

		if (cmp == 0) { // �迭 ��ҿ� Ű���� �ִ� ���
			
			while (1) { // �˻����� ���� ���� �ε����� ã�� �����˻��� �ݺ�
				cmp = compar(&x[(--pc)], key);
				
				if (cmp != 0) {
					return &x[(++pc)];
				}	
			}
		}
		else if (pl > pr) {
			return NULL;
		}
		else if (cmp > 0) { 
			pl = pc + 1; 
		}
		else {
			pr = pc - 1;
		}
	} while (1); 	
}

int int_cmp(const int *a, const int *b) { // ���Լ�
	if (*a > *b) return -1;
	else if (*a < *b) return 1;
	else if(*a == *b) return 0;
}

void main() { // �����Լ�
	int i = 0; // �ݺ��Է��� ���� ī����
	int nx, ky; // ���� �迭 ũ��, �˻���
	int* x; int* idx; // ���� �迭 �ּ�, ã�� ���� �迭[�ε���]�� �ּ�
	printf("bsearchx �Լ�\n��� ���� : "); scanf("%d", &nx);
	x = calloc(nx, sizeof(int)); // ���� �迭 �ּ� �Ҵ�

	while (i < nx) {
		printf("x[%d] : ", i); scanf("%d", &x[i++]);

		if (x[i - 2] > x[i - 1]) {
			printf("������������ �Է��Ͻÿ�\n"); // bsearch �Լ��� �������� ������ ������ �Լ�
			i--;
		}
	}
	printf("�˻��� : "); scanf("%d", &ky);
	idx = bsearchx // bsearch �Լ� ȣ��
	(&ky,
		x,
		nx,
		sizeof(int),
		 int_cmp); // (int(*)(const int*, const int*))

	if (idx == NULL) {
		printf("�˻�����");
	}
	else {
		printf("x[%d] = %d", (idx - x), ky); 
	}
}