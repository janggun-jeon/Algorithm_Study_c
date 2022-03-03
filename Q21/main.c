#include "main.h"

//문제21 포인터로 연결리스트를 만들어라.(주어진 member.c와member.h 그리고 list.h와 main.c의 코드를 참고해 list.c와 main.h의 코드를 작성하라)

typedef int Menu;

Menu SelectMenu(void)
{
	int i, ch; // ch = choice
	char* mstring[] = { // mstring = Menu string
		"머리에 노드를 삽입",   "꼬리에 노드를 삽입",   "머리 노드를 삭제",
		"꼬리 노드를 삭제",     "선택한 노드를 출력",   "선택한 노드를 삭제",
		"번호로 검색",          "이름으로 검색",        "모든 노드를 출력",
		"모든 노드를 삭제",
	};

	do {
		for (i = 0; i < 10; i++) {
			printf("(%2d) %-18.18s ", i + 1, mstring[i]);
			if ((i % 3) == 2)
				putchar('\n');
		}
		printf("( 0) 종료...	(?) : ");
		scanf("%d", &ch);
	} while (ch < 0 || ch > 10);

	return ch;
}

void main() {
	Menu menu;
	List list;

	Initialize(&list);  
	do {
		puts("\n연결리스트 관리\n");
		Member x;
		switch (menu = SelectMenu()) {
			/* 머리에 노드를 삽입 */
		case 1:
			x = ScanMember("머리에 삽입", NO | NAME);
			InsertFront(&list, &x);
			break;

			/* 꼬리에 노드를 삽입 */
		case 2:
			x = ScanMember("꼬리에 삽입", NO | NAME);
			InsertRear(&list, &x);
			break;

			/* 머리 노드를 삭제 */
		case 3:
			RemoveFront(&list);
			break;

			/* 꼬리 노드를 삭제 */
		case 4:
			RemoveRear(&list);
			break;

			/* 선택한 노드의 데이터를 출력*/
		case 5:
			PrintCurrent(&list);
			break;

			/* 선택한 노드를 삭제 */
		case 6:
			RemoveCurrent(&list);
			break;

			/* 번호로 검색 */
		case 7:
			x = ScanMember("검색", NO);
			if (search(&list, &x, MemberNoCmp) != NULL)
				PrintCurrent(&list);
			else
				puts("그 번호의 데이터가 없습니다.");
			break;

			/* 이름으로 검색 */
		case 8:
			x = ScanMember("검색", NAME);
			if (search(&list, &x, MemberNameCmp) != NULL)
				PrintCurrent(&list);
			else
				puts("그 이름의 데이터가 없습니다.");
			break;

			/* 모든 노드의 데이터를 출력 */
		case 9:
			Print(&list);
			break;

			/* 모든 노드를 삭제 */
		case 10:
			Clear(&list);
			break;
		}
	} while (menu != 0);

	Clear(&list);       
}