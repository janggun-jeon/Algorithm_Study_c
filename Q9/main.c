#include "main.h"

//����9 �ϳ��� �迭�� �����ϴ� 2���� ������ �����ϴ� ���α׷��� �ۼ��϶�.

void main() {

	INtStack stack; // ���� ����ü ��üstack ����
	int* max = malloc(sizeof(int)); // �迭�� ũ�⸦ �����ϴ� ���� ����
	printf("�迭�� ũ�� ���� : "); scanf("%d", max);
	if (Initialize(&stack, *max) == -1) {
		puts("\a���� ������ ������."); // �迭�� ũ�Ⱑ �ʹ� ũ�� ����
		return 1; // �����Լ� ����
	}
	free(max); // ���� max�� �ʿ������ ����

	while (1) {
		int menu; // �޴��ɼ��� ����
		int x; // �����Լ����� ��ȯ���� ����
		printf("\n���� ������(���뷮, �ִ�뷮) : %d / %d\n", Size(&stack), Capacity(&stack));
		printf("�۾��� ������ ���� (A ***0 or B ***others) : "); scanf("%d", &stack.ab);
		printf("0.����   1.Ǫ��   2.��   3.��ũ   4.���   5.��ġ   6.Ŭ���� : ");
		scanf("%d", &menu);
		if (menu == 0) break; // while���� ���� ���� ���� ����
		
		switch (menu) {

		case 1 : { // Ǫ��
			printf("������ : ");
			scanf("%d", &x);
			putchar('\n');
			if (Push(&stack, x) == -1) {
				puts("\a���� : Ǫ�ÿ� ����");
			}
			break;
		}
		case 2 : { // ��
			if (Pop(&stack, &x) == -1) {
				puts("\a���� : �˿� ����");
			}
			else {
				printf("�� �����ʹ� %d\n", x);
			}
			break;
		}
		case 3 : { // ��ũ
			if (Peek(&stack, &x) == -1) {
				puts("\a���� : ��ũ�� ����");
			}
			else {
				printf("��ũ �����ʹ� %d\n", x);
			}
			break;
		}
		case 4 : { // ���
			Print(&stack);
			break;
		}
		case 5 : { // ��ġ
			printf("������ : ");
			scanf("%d", &x);
			putchar('\n');
			if (Search(&stack, x) == -1) {
				puts("\a���� : ��ġ�� ����");
			}
			break;
		}
		case 6: {
			Clear(&stack);
			break;
		}

		} // swithch���� ��
	} // while���� ��
	Terminate(&stack); // ����
}