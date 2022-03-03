#include "main.h"

//����21 �����ͷ� ���Ḯ��Ʈ�� ������.(�־��� member.c��member.h �׸��� list.h�� main.c�� �ڵ带 ������ list.c�� main.h�� �ڵ带 �ۼ��϶�)

typedef int Menu;

Menu SelectMenu(void)
{
	int i, ch; // ch = choice
	char* mstring[] = { // mstring = Menu string
		"�Ӹ��� ��带 ����",   "������ ��带 ����",   "�Ӹ� ��带 ����",
		"���� ��带 ����",     "������ ��带 ���",   "������ ��带 ����",
		"��ȣ�� �˻�",          "�̸����� �˻�",        "��� ��带 ���",
		"��� ��带 ����",
	};

	do {
		for (i = 0; i < 10; i++) {
			printf("(%2d) %-18.18s ", i + 1, mstring[i]);
			if ((i % 3) == 2)
				putchar('\n');
		}
		printf("( 0) ����...	(?) : ");
		scanf("%d", &ch);
	} while (ch < 0 || ch > 10);

	return ch;
}

void main() {
	Menu menu;
	List list;

	Initialize(&list);  
	do {
		puts("\n���Ḯ��Ʈ ����\n");
		Member x;
		switch (menu = SelectMenu()) {
			/* �Ӹ��� ��带 ���� */
		case 1:
			x = ScanMember("�Ӹ��� ����", NO | NAME);
			InsertFront(&list, &x);
			break;

			/* ������ ��带 ���� */
		case 2:
			x = ScanMember("������ ����", NO | NAME);
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
			PrintCurrent(&list);
			break;

			/* ������ ��带 ���� */
		case 6:
			RemoveCurrent(&list);
			break;

			/* ��ȣ�� �˻� */
		case 7:
			x = ScanMember("�˻�", NO);
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

			/* ��� ��带 ���� */
		case 10:
			Clear(&list);
			break;
		}
	} while (menu != 0);

	Clear(&list);       
}