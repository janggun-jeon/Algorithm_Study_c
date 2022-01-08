#include "main.h"

//문제10 덱(양방향에서 인큐, 디큐 가능)과 링_버퍼(배열의 양끝이 연속되게 연결)를 구현하는 큐 프로그램을 작성하라.

void main() {
	IntQueue que; // 큐 구조체 객체 que 선언
	int* max = malloc(sizeof(int)); // 배열의 크기를 결정하는 동적 변수
	printf("필요한 큐의 용량 : "); scanf("%d", max);
	if (Initialize(&que, *max + 2) == -1) {
		puts("큐 생성에 실패함."); // 배열의 크기가 너무 크면 실패
		return 1; // 메인함수 종료
	}
	free(max); // 이제 max는 필요없으니 제거

	while (1) {
		int menu; // 메뉴옵션을 선택
		int x; // 큐함수들의 반환값을 저장
		printf("\n현재 데이터(사용용량, 최대용량) : %d / %d\n", Size(&que), Capacity(&que));
		printf("0.종료   1.인큐   2.디큐   3.피크   4.출력   5.검색   6.리셋 : "); scanf("%d", &menu);

		if (menu == 0) break; // while문을 빠져 나와 스택 종료
		
		switch (menu) {

		case 1 : { // 인큐
			printf("데이터 : "); scanf("%d", &x);
			printf("인큐방향(프런트 *** 0, 리어 *** other) : "); scanf("%d", &(que.deck));
			putchar('\n');
			if (Enque(&que, x) == -1) {
				puts("오류 : 인큐에 실패");
			}
			break;
		}
		case 2 : { // 디큐
			printf("디큐방향(프런트 *** 0, 리어 *** other) : "); scanf("%d", &(que.deck));
			if (Deque(&que, &x) == -1) {
				puts("오류 :디큐에 실패");
			}
			else {
				printf("디큐한 데이터는 %d\n", x);
			}
			break;
		}
		case 3 : { // 피크
			if (Peek(&que, &x) == -1) {
				puts("오류 : 피크에 실패");
			}
			else {
				printf("피크 데이터는 %d\n", x);
			}
			break;
		}
		case 4 : { // 출력
			Print(&que);
			break;
		}
		case 5 : { // 검색
			printf("데이터 : "); scanf("%d", &x);
			putchar('\n');
			int i = Search(&que, x);
			if (i == -1) {
				puts("오류 : 검색에 실패");
			}
			else {
				printf("프런트 기준으로 %d번째 데이터\n", i);
			}
			break;
		}
		case 6: {
			Clear(&que);
			break;
		}

		} // swithch문의 끝
	} // while문의 끝
	Terminate(&que); // 종료
}