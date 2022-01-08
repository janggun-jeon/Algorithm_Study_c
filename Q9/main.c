#include "main.h"

//문제9 하나의 배열을 공유하는 2개의 스택이 공유하는 프로그램을 작성하라.

void main() {

	INtStack stack; // 스택 구조체 객체stack 선언
	int* max = malloc(sizeof(int)); // 배열의 크기를 결정하는 동적 변수
	printf("배열의 크기 설정 : "); scanf("%d", max);
	if (Initialize(&stack, *max) == -1) {
		puts("\a스택 생성에 실패함."); // 배열의 크기가 너무 크면 실패
		return 1; // 메인함수 종료
	}
	free(max); // 이제 max는 필요없으니 제거

	while (1) {
		int menu; // 메뉴옵션을 선택
		int x; // 스택함수들의 반환값을 저장
		printf("\n현재 데이터(사용용량, 최대용량) : %d / %d\n", Size(&stack), Capacity(&stack));
		printf("작업할 스택을 선택 (A ***0 or B ***others) : "); scanf("%d", &stack.ab);
		printf("0.종료   1.푸시   2.팝   3.피크   4.출력   5.서치   6.클리어 : ");
		scanf("%d", &menu);
		if (menu == 0) break; // while문을 빠져 나와 스택 종료
		
		switch (menu) {

		case 1 : { // 푸시
			printf("데이터 : ");
			scanf("%d", &x);
			putchar('\n');
			if (Push(&stack, x) == -1) {
				puts("\a오류 : 푸시에 실패");
			}
			break;
		}
		case 2 : { // 팝
			if (Pop(&stack, &x) == -1) {
				puts("\a오류 : 팝에 실패");
			}
			else {
				printf("팝 데이터는 %d\n", x);
			}
			break;
		}
		case 3 : { // 피크
			if (Peek(&stack, &x) == -1) {
				puts("\a오류 : 피크에 실패");
			}
			else {
				printf("피크 데이터는 %d\n", x);
			}
			break;
		}
		case 4 : { // 출력
			Print(&stack);
			break;
		}
		case 5 : { // 서치
			printf("데이터 : ");
			scanf("%d", &x);
			putchar('\n');
			if (Search(&stack, x) == -1) {
				puts("\a오류 : 서치에 실패");
			}
			break;
		}
		case 6: {
			Clear(&stack);
			break;
		}

		} // swithch문의 끝
	} // while문의 끝
	Terminate(&stack); // 종료
}