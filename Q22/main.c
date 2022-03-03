#include "main.h"

//문제22 포인터로 만든 연결리스트(문제21) 원형 이중 연결리스트로를 만들어라.

typedef int Menu;

Menu SelectMenu(void)
{
	int i, ch; // ch = choice
	char* mstring[] = { // mstring = Menu string
		"머리에 노드를 삽입",      "꼬리에 노드를 삽입",      "머리 노드를 삭제",
		"꼬리 노드를 삭제",        "선택한 노드를 출력",      "선택한 노드를 삭제",
		"번호로 검색",             "이름으로 검색",           "모든 노드를 출력",
		"현재 노드의 뒤쪽을 선택", "현재 노드의 앞쪽를 선택", "모든 노드를 삭제",
	};

	do {
		for (i = 0; i < 12; i++) {
			printf("(%2d) %-26.26s ", i + 1, mstring[i]);
			if ((i % 3) == 2)
				putchar('\n');
		}
		printf("( 0) %-26.26s (?) : ","종료...");
		scanf("%d", &ch);
	} while (ch < 0 || ch > 12);

	return ch;
}

void main() {
	Menu menu;
	List list;

	Initialize(&list);
	do {
		puts("\n원형 이중 연결리스트 관리\n");
		Member x;
		switch (menu = SelectMenu()) {
			/* 머리에 노드를 삽입 */
		case 1:
			x = ScanMember("머리에 삽입", N | NAME);
			InsertFront(&list, &x);
			break;

			/* 꼬리에 노드를 삽입 */
		case 2:
			x = ScanMember("꼬리에 삽입", N | NAME);
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
			putchar('\n');
			PrintCurrent(&list);
			break;

			/* 선택한 노드를 삭제 */
		case 6:
			RemoveCurrent(&list);
			break;

			/* 번호로 검색 */
		case 7:
			x = ScanMember("검색", N);
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

			/* 현재 노드의 뒤쪽을 선택 */
		case 10:
			Next(&list);
			break;

			/* 현재 노드의 앞쪽을 선택*/
		case 11:
			Prev(&list);
			break;

			/* 모든 노드를 삭제 */
		case 12:
			Clear(&list);
			break;
		}
	} while (menu != 0);

	Terminate(&list);
}