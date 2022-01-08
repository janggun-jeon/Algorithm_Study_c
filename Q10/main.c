#include "main.h"

//����10 ��(����⿡�� ��ť, ��ť ����)�� ��_����(�迭�� �糡�� ���ӵǰ� ����)�� �����ϴ� ť ���α׷��� �ۼ��϶�.

void main() {
	IntQueue que; // ť ����ü ��ü que ����
	int* max = malloc(sizeof(int)); // �迭�� ũ�⸦ �����ϴ� ���� ����
	printf("�ʿ��� ť�� �뷮 : "); scanf("%d", max);
	if (Initialize(&que, *max + 2) == -1) {
		puts("ť ������ ������."); // �迭�� ũ�Ⱑ �ʹ� ũ�� ����
		return 1; // �����Լ� ����
	}
	free(max); // ���� max�� �ʿ������ ����

	while (1) {
		int menu; // �޴��ɼ��� ����
		int x; // ť�Լ����� ��ȯ���� ����
		printf("\n���� ������(���뷮, �ִ�뷮) : %d / %d\n", Size(&que), Capacity(&que));
		printf("0.����   1.��ť   2.��ť   3.��ũ   4.���   5.�˻�   6.���� : "); scanf("%d", &menu);

		if (menu == 0) break; // while���� ���� ���� ���� ����
		
		switch (menu) {

		case 1 : { // ��ť
			printf("������ : "); scanf("%d", &x);
			printf("��ť����(����Ʈ *** 0, ���� *** other) : "); scanf("%d", &(que.deck));
			putchar('\n');
			if (Enque(&que, x) == -1) {
				puts("���� : ��ť�� ����");
			}
			break;
		}
		case 2 : { // ��ť
			printf("��ť����(����Ʈ *** 0, ���� *** other) : "); scanf("%d", &(que.deck));
			if (Deque(&que, &x) == -1) {
				puts("���� :��ť�� ����");
			}
			else {
				printf("��ť�� �����ʹ� %d\n", x);
			}
			break;
		}
		case 3 : { // ��ũ
			if (Peek(&que, &x) == -1) {
				puts("���� : ��ũ�� ����");
			}
			else {
				printf("��ũ �����ʹ� %d\n", x);
			}
			break;
		}
		case 4 : { // ���
			Print(&que);
			break;
		}
		case 5 : { // �˻�
			printf("������ : "); scanf("%d", &x);
			putchar('\n');
			int i = Search(&que, x);
			if (i == -1) {
				puts("���� : �˻��� ����");
			}
			else {
				printf("����Ʈ �������� %d��° ������\n", i);
			}
			break;
		}
		case 6: {
			Clear(&que);
			break;
		}

		} // swithch���� ��
	} // while���� ��
	Terminate(&que); // ����
}