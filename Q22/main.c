#include "main.h"

//����22 �����ͷ� ���� ���Ḯ��Ʈ(����21) ���� ���� ���Ḯ��Ʈ�θ� ������.

typedef int Menu;

Menu SelectMenu(void)
{
	int i, ch; // ch = choice
	char* mstring[] = { // mstring = Menu string
		"�Ӹ��� ��带 ����",      "������ ��带 ����",      "�Ӹ� ��带 ����",
		"���� ��带 ����",        "������ ��带 ���",      "������ ��带 ����",
		"��ȣ�� �˻�",             "�̸����� �˻�",           "��� ��带 ���",
		"���� ����� ������ ����", "���� ����� ���ʸ� ����", "��� ��带 ����",
	};

	do {
		for (i = 0; i < 12; i++) {
			printf("(%2d) %-26.26s ", i + 1, mstring[i]);
			if ((i % 3) == 2)
				putchar('\n');
		}
		printf("( 0) %-26.26s (?) : ","����...");
		scanf("%d", &ch);
	} while (ch < 0 || ch > 12);

	return ch;
}

void main() {
	Menu menu;
	List list;

	Initialize(&list);
	do {
		puts("\n���� ���� ���Ḯ��Ʈ ����\n");
		Member x;
		switch (menu = SelectMenu()) {
			/* �Ӹ��� ��带 ���� */
		case 1:
			x = ScanMember("�Ӹ��� ����", N | NAME);
			InsertFront(&list, &x);
			break;

			/* ������ ��带 ���� */
		case 2:
			x = ScanMember("������ ����", N | NAME);
			InsertRear(&list, &x);
			break;

			/* �Ӹ� ��带 ���� */
		case 3:
			RemoveFront(&list);
			break;

			/* ���� ��带 ���� */
		case 4:
			RemoveRear(&list);
			break;

			/* ������ ����� �����͸� ���*/
		case 5:
			putchar('\n');
			PrintCurrent(&list);
			break;

			/* ������ ��带 ���� */
		case 6:
			RemoveCurrent(&list);
			break;

			/* ��ȣ�� �˻� */
		case 7:
			x = ScanMember("�˻�", N);
			if (search(&list, &x, MemberNoCmp) != NULL)
				PrintCurrent(&list);
			else
				puts("�� ��ȣ�� �����Ͱ� �����ϴ�.");
			break;

			/* �̸����� �˻� */
		case 8:
			x = ScanMember("�˻�", NAME);
			if (search(&list, &x, MemberNameCmp) != NULL)
				PrintCurrent(&list);
			else
				puts("�� �̸��� �����Ͱ� �����ϴ�.");
			break;

			/* ��� ����� �����͸� ��� */
		case 9:
			Print(&list);
			break;

			/* ���� ����� ������ ���� */
		case 10:
			Next(&list);
			break;

			/* ���� ����� ������ ����*/
		case 11:
			Prev(&list);
			break;

			/* ��� ��带 ���� */
		case 12:
			Clear(&list);
			break;
		}
	} while (menu != 0);

	Terminate(&list);
}