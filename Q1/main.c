#define _CRT_SECURE_NO_WARNINGS // �ڷ��Է� ��뱸��

#include <stdio.h> // c��� ǥ�� ���̺귯�� : c������ ����� �Լ�

// ����1 '1 + ... + n = 1���� n������ ��' ���·� ����ϴ� ������ �ڵ带 �ۼ��϶�.

void main() {

	int i;
	int n;
	int sum = 1;

	printf("1���� n������ ���� ���Ѵ�.\n");
	printf("n�� �� : ");
	scanf("%d", &n);

	printf("1���� %d������ ��\n : 1", n);

	for (i = 2; i <= n; i++) {
		sum += i;
		printf(" + %d", i);
	}

	printf(" = %d", sum);

}