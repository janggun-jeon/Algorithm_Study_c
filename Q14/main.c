#define _CRT_SECURE_NO_WARNINGS // �ڷ��Է� ��뱸��
#define swap(type, x, y) do {type t = x; x = y; y = t;} while(0)

#include <stdio.h> // c��� ǥ�� ���̺귯�� : c������ ����� �Լ�
#include <stdlib.h> // c��� ǥ�� ���̺귯�� : ���� ���� , ���� ����, �޸� �Ҵ�

//����14 �ܼ� ���� ���Ŀ���, call by reference ������� ��Ƚ���� ���ϵ��� ���α׷��� �ۼ��϶�.

void insertion(int a[], int n, int** cmp) {
	int i = 1;
	(**cmp) = 0;
	while (i < n) {
		int tmp = a[i];
		int j = i;		
		while ( ++(**cmp) && (j > 0 && a[j - 1] > tmp) ) {
			a[j] = a[j - 1];
			j--;		
		}
		a[j] = tmp;
		i++;
	}
}

void main() {
	int i, nx;
	int* x;
	int* compar;
	compar = malloc(sizeof(int));
	

	puts("�ܼ� ���� ����");
	printf("��� ���� : "); scanf("%d", &nx);
	x = calloc(nx, sizeof(int));

	for (i = 0; i < nx; i++) {
		printf("x[%d] : ", i); scanf("%d", &x[i]);
	}

	insertion(x, nx, &compar);

	printf("������������ ����");
	for (i = 0; i < nx; i++) {
		printf("\nx[%d] = %d", i, x[i]);
	}

	printf("\n��Ƚ�� : %d", *compar);
	free(x);
}