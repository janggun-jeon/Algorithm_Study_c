#define _CRT_SECURE_NO_WARNINGS // scanf ��� ��� ����

#include <stdio.h> // c��� ǥ�� ����� �Լ� �������
#include <time.h> // c��� ǥ�� ���̺귯�� : �ð��Լ�
#include <stdlib.h> // c��� ǥ�� ���̺귯�� : ���� ��ȯ �Լ�, ���� ���� �Լ�,�޸� �Ҵ� �Լ�

//����4 �Լ� ���ο� �߰� ������ �������� �ʰ�, �� ���� ���� �� ���� ���ϴ� ���α׷�(������ ����ؼ�)�� �ۼ��϶�.

int mdays[][12] = {
	{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int isleap(int year) {
	return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

int dayofyear(int y, int m, int d) {
	m--;
	while (m--) {
		d += mdays[isleap(y)][m];
	}
	return d;
}

void main() {
	int year, month, day;	/* �� �� �� */
	int retry;				/* �ٽ� �� ��? */

		do {
			printf("�� : "); scanf("%d", &year);
			printf("�� : "); scanf("%d", &month);
			printf("�� : "); scanf("%d", &day);
	
			printf("%d ��° \n", dayofyear(year, month, day));
		
			printf("�ٽ� �� �� �ұ��?(1 �� / 0 �ƴϿ�): ");
			scanf("%d", &retry);
		} while (retry == 1);
}