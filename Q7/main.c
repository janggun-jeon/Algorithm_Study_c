#define _CRT_SECURE_NO_WARNINGS // scanf ��� ��� ����

#include <stdio.h> // c��� ǥ�� ����� �Լ� �������
#include <stdlib.h> // c��� ǥ�� ���̺귯�� : ���� ��ȯ �Լ�, ���� ���� �Լ�,�޸� �Ҵ� �Լ�

//����7 ������������ ���ĵ� long�� �迭�� bsearch �Լ��� �̿��� �˻��϶�.

long long_cmp(const void *a, const void *b){ // bsearch �Լ��� �迭�� �������� ������ �������� �� �Լ�
	if (*(long*)a > *(long*)b) return -1; // �������� ������ �������� �˻��� �ϱ� ���ؼ���
	if (*(long*)a < *(long*)b) return 1; // ���Լ��� ���, ���� ��ȯ������ ���� ��ȯ�ؾ���
	else return 0;
}
void main() {
	long nx, ky; // �迭�� ũ��, Ű��
	long* x; long* idx; // ���� �Ҵ��� �迭 ����� �ּҸ� ������ ������
	printf("bsearch �Լ��� ����� �˻�\n");
	printf("��� ���� : "); scanf("%d", &nx); // �迭�� ũ�Ⱚ ����

	x = calloc(nx, sizeof(long)); // ���� �迭 ����
	long i = -1;
	while (++i < nx) {
		printf("x[%d] : ", i); scanf("%d", &x[i]); // �� �ε����� �ش��ϴ� ���� �Է¹���

		if (i == 0) {}
		else if (x[i - 1] < x[i]) { // �������� �Է��� �ƴϸ� ���Է��ϰ� ��
			printf("������������ �Է��ϼ���.\n");
			i--;
		}

	}

	printf("�˻��� : "); scanf("%d", &ky); // Ű�� ����
	idx = bsearch // �˻�
	(&ky, // �˻��� ��ü�� �ּ�
		x, // x�迭�� ������
		nx, // �迭ũ��
		sizeof(long), // �迭�� �ڷ����� �ش��ϴ� �޸� ����ũ��
		(long(*)(const void*, const void*))long_cmp // void�� ���ڸ� �޾� int�� ��ȯ���� ���� ���Լ��� �ּ�
	);

	if (idx == NULL) {
		printf("�˻�����");
	}
	else {
		printf("�˻����� : x[%d]�� ����", (idx - x)); // idx�� x[�˻��� �ε���]�� �ּҸ� ��Ÿ���� ������, [�ε��� = idx�� x�� �ּҰ� ����]�� ���� �� ����
	}

}