#define _CRT_SECURE_NO_WARNINGS // scanf ��� ��� ����

#include <stdio.h> // c��� ǥ�� ����� �Լ� �������
#include <time.h> // c��� ǥ�� ���̺귯�� : �ð��Լ�
#include <stdlib.h> // c��� ǥ�� ���̺귯�� : ���� ��ȯ �Լ�, ���� ���� �Լ�,�޸� �Ҵ� �Լ�

//����3 ������ ����� �迭�� ��Ұ����� �����ϰ� �ٽ� �������� �����϶�.

void swap(int* x, int* y) { // �� �Է� ��ü�� ���� �����͸� ���� ��ȯ�ϴ� �Լ�
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

void main() {
	int* array; // ���� ��ü�� ȣ���� ������
	int size;
	printf("�迭�� ũ�� : ");
	scanf("%d", &size);

	array = calloc(size, sizeof(int)); // size��ŭ ��Ҹ� ���� �迭 ���� 
	int i;
	int n = size;
	srand(time(NULL)); // �ð����� ������ seed�� �ʱ�ȭ

	for (i = 0; i < size; i++) {
		array[i] = rand() % 99; // 0~������ ���� �������� ���� ����
		printf("array[%d] = %d\n", i, array[i]); // ������ �迭�� ��Ұ����� ���
	}

	printf("all array elements swap!!\n");

	for (i = 0; n >= i + 1; i++) {
		n = size - 1 - i;
		swap(&array[i], &array[n]); // �迭 ��ҵ��� ������ �ǰ� ��ȯ
	}

	for (i = 0; i < size; i++) {
		printf("array[%d] = %d\n", i, array[i]); // �������� �������� �迭�� ��Ұ����� ���
	}
}