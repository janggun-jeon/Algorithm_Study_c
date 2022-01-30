#define _CRT_SECURE_NO_WARNINGS // �ڷ��Է� ��뱸��
#define swap(type, x, y) do {type t = x; x = y; y = t;} while(0)

#include <stdio.h> // c��� ǥ�� ���̺귯�� : c������ ����� �Լ�
#include <stdlib.h> // c��� ǥ�� ���̺귯�� : ���� ���� , ���� ����, �޸� �Ҵ�

//����15 �����Ŀ��� �ݺ������ ó������ Ƚ���� ����ϵ��� ���α׷��� �ۼ��϶�.

int* shell(int a[], int n) {
	int* rtct = calloc(4, sizeof(int)); // �Լ����� �ݺ��� ����&��&���� ���� Ƚ���� ����
	int cmp = 0; // ��� ���� ��Ƚ��
	int mov = 0; // ��� �̵� Ƚ��
	int insert = 0; // �ݵ�� �ʿ��� ������ ����
	int sort = 0; // ������ �� h-���� ���� ����
	int h = 0;
	while (h < (n / 3)) {
		h = h * 3 + 1;
		sort++;
	}
	while (h > 0) {
		int i = h;
		while (i < n) {
			int tmp = a[i];
			int j = i - h;
			while (++cmp && (j >= 0 && a[j] > tmp)) { // while�� ���ǺҸ��� ���� ����ü�� �߱⶧���� cmp ī��Ʈ
				a[j + h] = a[j];
				mov++; // ������ ���϶� ��� �̵� �� �̵�Ƚ�� ī��Ʈ
				j -= h;
			}
			if (a[j + h] != tmp) { //��� ���� �ʿ俩�θ� �˱����ؼ� ��, ���� �����Ŀ��� �� �񱳴� �������� �ʾƼ� cmp ��ī��Ʈ 
				a[j + h] = tmp; 
				insert++; // j + h == i �̰ų� a[j + h] == a[i] �϶��� ������ ������ ������ �ʿ���� 
			}		
			i++;
		}
		h /= 3;
	}
	rtct[0] = cmp; 
	rtct[1] = mov; 
	rtct[2] = insert;
	rtct[3] = sort;
	return rtct;
}
	
void main() {
	int i, nx;
	int* x;
	int* RepeatCount;
	
	
	puts("�� ����");
	do { printf("��� ����(3�̻�) : "); scanf("%d", &nx); } while (nx < 3);
	x = calloc(nx, sizeof(int));

	for (i = 0; i < nx; i++) {
		printf("x[%d] : ", i); scanf("%d", &x[i]);
	}

	RepeatCount = shell(x, nx);

	printf("������������ ����");
	for (i = 0; i < nx; i++) {
		printf("\nx[%d] = %d", i, x[i]);
	}

	printf("\n�� Ƚ�� : %d", RepeatCount[0]);
	printf("\n��� �̵� Ƚ�� : %d", RepeatCount[1]);
	printf("\n��ȿ�� ������ Ƚ�� : %d", RepeatCount[2]);
	printf("\nh-���� Ƚ�� : %d", RepeatCount[3]);
	free(x);
	free(RepeatCount);
}