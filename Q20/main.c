#define _CRT_SECURE_NO_WARNINGS // �ڷ��Է� ��뱸��
#define swap(type, x, y) do {type t = x; x = y; y = t;} while(0)

#include <stdio.h> // c��� ǥ�� ���̺귯�� : c������ ����� �Լ�
#include <stdlib.h> // c��� ǥ�� ���̺귯�� : ���� ���� , ���� ����, �޸� �Ҵ�

//����20 ���� ���� �˰����� �ۼ��϶�.

void wsort(int a[], int n, int min,int max) {
	int i;
	int* w = calloc(max + 1, sizeof(int)); // ���� ���� ������ �迭
	int* b = calloc(n, sizeof(int)); // ��� ���� �۾��� �迭

	i = 0;
	while (i <= max) { // w[]�� ��� ���� 0���� �ʱ�ȭ
		w[i] = 0;
		i++;
	}
	
	i = 0;
	while (i < n) { // a[]�� ��Ұ����� �ε����� ������ w[a[]]�� ��Ұ����� �ߺ� ī��Ʈ
		w[a[i]]++;
		i++;
	}
	
	i = 1;
	while (i <= max) { // w[]�� ��Ұ��� ������������ ��������, ���� a[]�� �������� w[a[]]�� �۾����� ���谡 ����
		w[i] += w[i - 1];
		i++;
	}

	i = n - 1;
	while (i >= 0) { // a[]�� �� ��Ұ����� ��������, b[w[a[]] - 1]�� ���� �ε����� �ش��ϴ� ��ҿ� �����
		b[--w[a[i]]] = a[i];
		i--;
	}
	
	i = 0;
	while (i < n) { // a[]�� ��ҵ��� ������������ ����� b[]�� a[]�� ����
		a[i] = b[i];
		i++;
	}
	
	free(b), free(w);
}

void main() {
	int i, n;
	const int min, max;
	int* x;

	puts("���� ����\n");
	puts("min ~ max ������ ������ �Է��϶�");
	printf("min : "); scanf("%d", &min);
	printf("max : "); scanf("%d", &max);
	printf("\n��� ���� : "); scanf("%d", &n);
	x = calloc(n, sizeof(int));

	i = 0;
	while (i < n) {
			printf("x[%d] : ", i); scanf("%d", &x[i++]);
			if ((x[i - 1] < min) || (max < x[i - 1])) {
				printf("%d ~ %d ������ ������ �Է��϶�\n", min, max);
				i--;
			}
	}

	wsort(x, n, min, max);
	puts("\n������������ ���ĵ�");

	i = 0;
	while (i < n) {
		printf("x[%d] = %d\n", i, x[i++]);
	}

	free(x);
}