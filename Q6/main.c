#define _CRT_SECURE_NO_WARNINGS // scanf ��� ��� ����

#include <stdio.h> // c��� ǥ�� ����� �Լ� �������
#include <stdlib.h> // c��� ǥ�� ���̺귯�� : ���� ��ȯ �Լ�, ���� ���� �Լ�,�޸� �Ҵ� �Լ�

//����6 ������������ ���ĵ� �迭�� �����˻��ϴ� �Լ��� �ۼ��϶�.

int binary_search(const int a[], int n, int key) { // ������ �迭�� ���� �˻��ϴ� �Լ�(�迭, �迭�� ũ��, Ű��)
	int pl = 0; // ���� ������ �ε���
	int pr = n - 1; // ���� ������ �ε���
	int pc; // ���� ���õ� �ε���

	do { // �˻��� �ּ� �ѹ��̻� ��
		pc = (pl + pr) / 2; // �˻��� �ݺ��� �� ���� pc �ʱ�ȭ

		if(a[pc] == key){ // �迭 ��ҿ� Ű���� �ִ� ���
			return pc; // �˻� ����, �ش� �ε��� ��ȯ
		}
		else if (a[pc] > key) {
			pr = pc - 1;
		}
		else {
			pl = pc + 1;
		}

	} while (pl <= pr); // �迭 ��ҿ� Ű���� ���� ���
	return -1; // �迭 ��ҿ� Ű���� ���� ���
}

void main() {
	int nx, ky, idx; // �迭�� ũ��, Ű��, �ε���
	int* x; // ���� �Ҵ��� �迭�� �ּҸ� ������ ������
	printf("���� �˻�\n");
	printf("��� ���� : "); scanf("%d", &nx); // �迭�� ũ�Ⱚ ����

	x = calloc(nx, sizeof(int)); // ���� �迭 ����
	int i = 0;
	printf("������������ �Է��ϼ���.\n");
	while (i < nx) {
		printf("x[%d] : ", i); scanf("%d", &x[i++]); // �� �ε����� �ش��ϴ� ���� �Է¹���

		if (x[i - 2] > x[i - 1]) { // �������� �Է��� �ƴϸ� ���Է��ϰ� ��
			printf("������������ �Է��ϼ���.\n");
			i--;
		}

	}

	printf("�˻��� : "); scanf("%d", &ky); // Ű�� ����
	idx = binary_search(x, nx, ky); // �˻�

	if (idx == -1) {
		printf("�˻�����");
	}
	else {
		printf("�˻����� : x[%d]�� ����", idx);
	}

}