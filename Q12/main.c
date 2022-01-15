#define _CRT_SECURE_NO_WARNINGS // scanf ��� ��� ����
#define swap(type, x, y) do {type t = x; x = y; y = t;} while(0)

#include <stdio.h>
#include <stdlib.h>

//����12 ���������� �н������� �ܰ������� ����ϰ�, ��Ƚ���� ��ȯȽ���� ���� �� �ִ� ���α׷��� �ۼ��϶�.

int bubble(int a[], int n) {
	int i, j, k;
	int change = 0;
	for  (i = 0; i < n - 1; i++) {
		printf("�н�%d :\n", i + 1);

		for (j = n - 1;j > i ; j--) {

			for (k = 0; k < j - 1; k++) {
				printf("%d", a[k]);
				printf("%3s", "");
			}

			if (a[j - 1] > a[j]) {
				swap(int, a[j - 1], a[j]);
				printf("%d<->%d", a[j - 1], a[j]);
				change++;
			}
			else {
				printf("%d---%d", a[j - 1], a[j]);
			}

			for (k = j + 1; k < n; k++) {
				printf("%3s", "");
				printf("%d", a[k]);	
			}
			putchar('\n');
		}
	}
	return change;
}



void main() {
	int i, nx, cng;
	int* x;

	puts("���� ����");
	printf("��� ���� : "); scanf("%d", &nx);
	x = calloc(nx, sizeof(int));

	for (i = 0; i < nx; i++) {
		printf("x[%d] : ", i); scanf("%d", &x[i]);
	}

	cng = bubble(x, nx);

	printf("������������ ����");
	for  (i = 0; i < nx; i++) {
		printf("\nx[%d] = %d", i, x[i]);
	}

	free(x);
	printf("\n��Ƚ�� : %d\n��ȯȽ�� : %d", (nx * (nx - 1)) / 2, cng);
}