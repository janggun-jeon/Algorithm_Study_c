#define _CRT_SECURE_NO_WARNINGS // scanf ��� ��� ����
#define swap(type, x, y) do {type t = x; x = y; y = t;} while(0)

#include <stdio.h> // c��� ǥ�� ����� �Լ� �������
#include <stdlib.h> // c��� ǥ�� ���̺귯�� : ���� ��ȯ �Լ�, ���� ���� �Լ�,�޸� �Ҵ� �Լ�

//����16 ������(�⺻���� �˰��򺸴� ȿ���� �� ����)�� �� ������ ����ϴ� ���α׷��� �ۼ��϶�. 

void quick(int a[], int left, int right) {
	int i;
	int pl = left;
	int pr = right;
	int x = a[(pl + pr) / 2];

	printf("\n�ǹ��� ���� %d\n", x);
	do {
		while (a[pl] < x) { pl++; }
		while (a[pr] > x) { pr--; }
		if (pl <= pr) {
			swap(int, a[pl], a[pr]);
			pl++;
			pr--;
		}
	} while (pl <= pr);

	puts("�ǹ� ������ �׷�");
	i = left;
	printf("x[%d] ~ x[%d] : ", i, pl - 1);
	while (i <= pl - 1) { printf("%d ", a[i++]); }
	putchar('\n');

	if (pl > pr + 1) {
		puts("�ǹ��� ��ġ�ϴ� �׷�");
		i = pr + 1;
		if (pr + 1 == pl - 1) { printf("x[%d] : ", pr + 1); }
		while (i <= pl - 1) { printf("%d ", a[i++]); }
		putchar('\n');
	}

	puts("�ǹ� �̻��� �׷�");
	i = pr + 1;
	printf("x[%d] ~ x[%d] : ", i, right);
	while (i <= right) { printf("%d ", a[i++]); }
	putchar('\n');

	if (left < pr) { quick(a, left, pr); }
	if (pl < right) { quick(a, pl, right); }
}

void main() {
	int i, j, n;
	int* x;
	puts("�� ����");
	printf("��� ���� : "); scanf("%d", &n); putchar('\n');
	x = calloc(n, sizeof(int));
	i = 0;
	while (i < n) {
		printf("x[%d] : ", i); scanf("%d", &x[i++]);
	}
	quick(x, 0, n - 1);
	j = 0;
	while (j < n) { 
		printf("\nx[%d] : %d", j, x[j]);
		j++;
	}
	free(x);
}