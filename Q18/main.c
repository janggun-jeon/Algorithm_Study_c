#define _CRT_SECURE_NO_WARNINGS // �ڷ��Է� ��뱸��

#include <stdio.h>
#include <stdlib.h>

//����18 ���� ���� �˰����� �ۼ��϶�.

static int* buff; // �۾��� �迭

void merge(int a[], int left, int center, int right) { // ���ĵ� �� �迭�� ����
	int i = left;
	int j = 0; 
	int k = left;
	int p = 0;
	while (i <= center) { // left ~ center ���� buff�� �ӽ�����
		buff[p++] = a[i++];
	}
	while (i <= right && j < p) {
		a[k++] = (buff[j] <= a[i]) ? buff[j++] : a[i++];
	}
	while (j < p) {
		a[k++] = buff[j++];
	}
}

static void merge_after_divide(int a[], int left, int right) { // ���� �� ����
	int center = (left + right) / 2;
	if (left < right) { // �迭�� ��Ұ� 2���̻��� ��� ����
		merge_after_divide (a, left, center);
		merge_after_divide(a, center + 1, right);
	}
	merge(a, left, center, right); // ���������� ���ĵ� left ~ center ������ ��ҿ� (center + 1) ~ right ������ ��Ҹ� ����
}

int merge_sort(int a[], int n) { // ��������
	if( (buff = calloc(n, sizeof(int)) ) == NULL) {
		puts("\n���� ���Ŀ� ����");
		return -1;
	}
	merge_after_divide(a, 0, n - 1);
	free(buff); 
	return 0;
}

void main() {
	int i, n;
	int* x;
	puts("���� ����");
	printf("\n��� ���� : "); scanf("%d", &n);
	x = calloc(n, sizeof(int));
	i = 0;
	while (i < n) {
		printf("x[%d] : ", i); scanf("%d", &x[i]);
		i++;
	}
	i = merge_sort(x, n);
	if (i < 0) { return; }
	else { puts("\n�������� ���� �Ϸ�"); }
	i = 0;
	while (i < n) {
		printf("x[%d] = %d\n", i, x[i]);
		i++;
	}
	free(x);
}