#define _CRT_SECURE_NO_WARNINGS // scanf ��� ��� ����

#include <stdio.h> // c��� ǥ�� ����� �Լ� �������

//����2 ���м��� �ִ� 9*9����ǥ�� ����ϴ� ���α׷��� �ۼ��϶�.

void main() {
	int i, j;
	printf("   |");
	for (i = 1; i <= 9; i++) {
		printf("% 3d", i);
	}
	printf("\n---+");
	for (i = 1; i <= 9; i++) {
		printf("---");
	}
	for (i = 1; i <= 9; i++) {
		printf("\n %d |", i);
		for (j = 1; j <= 9; j++) {
			printf("% 3d", i * j);
		}
	}
}