#define _CRT_SECURE_NO_WARNINGS // scanf ��� ��� ����
#define swap(type, x, y) do {type t = x; x = y; y = t;} while(0)

#include <stdio.h>
#include <stdlib.h>

//����13 ����� ���� ����(����Ŀ ����)�� �����ϴ� ���α׷��� �ۼ��϶�.

int shaker(int a[], int n)
{
	int left = 0;
	int right = n - 1;
	int last = right;
	int change; // �����н� ���� ��ȯȽ���� ī����
	int count = 0; // ��Ƚ���� ī����

	while (left < right) {
		int i;
		for (i = right; i > left; i--) {
			change = 0;
			if (a[i - 1] > a[i]) {
				swap(int, a[i - 1], a[i]);
				last = i;
				change++;
				count++;
			}
		}
		if (change == 0) { return count; } // �н� ���ο� ��ȯ�� ���ٸ�, ��������
		left = last; // ������ ��ȯ �ε��� ��(���� ������ȣ, left ����)�� �񱳴�󿡼� ����

		for (i = left; i < right; i++) {
			change = 0;
			if (a[i] > a[i + 1]) {
				swap(int, a[i], a[i + 1]);
				last = i;
				change++;
				count++;
			}
		}
		if (change == 0) { return count; } // �н� ���ο� ��ȯ�� ���ٸ�, ��������
		right = last; // ������ ��ȯ�� �Ͼ �ε��� ��(���� ������ȣ, right ����)�� �񱳴�󿡼� ����
	}
	return count;
}

void main(void)
{
	int i, nx;
	int* x;

	puts("����� ���� ����");
	printf("��� ���� : ");
	scanf("%d", &nx);
	x = calloc(nx, sizeof(int));

	for (i = 0; i < nx; i++) {
		printf("x[%d] : ", i);
		scanf("%d", &x[i]);
	}

	int compar = shaker(x, nx);

	puts("������������ ����");
	for (i = 0; i < nx; i++)
		printf("x[%d] = %d\n", i, x[i]);

	free(x);
	printf("��Ƚ�� : %dȸ", compar);
}