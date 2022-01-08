#include "main.h"

int Initialize(INtStack* s, int max) { // 스택의 공간을 확보하기 위해서 스택 내부를 비움
	printf("스택 초기화\n");

	s->Aptr = 0; // 배열의 최저 인덱스
	s->Bptr = max - 1; // 배열의 최고 인덱스
	if ((s->stk = calloc(max, sizeof(int))) == NULL) { // 일단 원하는 용량만큼 배열 생성 시도
		s->max = 0;
		return -1; // 스택 초기화 실패
	}
	s->max = max; // 스택 용량을 나타내는 값을 구조체 s의 멤버 max에 저장
	return 0; // 스택 초기화 성공
}

int Push(INtStack* s, int x) {
	printf("스택에 데이터 푸시\n");

	if (s->Aptr > s->Bptr) { return -1; } // 스택이 가득참
	if (s->ab == 0) {
		s->stk[s->Aptr++] = x;
	}
	else {
		s->stk[s->Bptr--] = x;
	}
	return 0;
}

int Pop(INtStack* s, int* x) {
	printf("\n스택에 데이터 팝\n");

	if (s->ab == 0) {
		if (s->Aptr == 0) { return -1; } // 스택이 빈공간
		*x = s->stk[--(s->Aptr)];
	}
	else {
		if (s->Bptr == s->max - 1) { return -1; } // 스택이 빈공간
		*x = s->stk[++(s->Bptr)];
	}
	return 0;
}

int Peek(const INtStack* s, int* x) {
	printf("\n스택에 피크 데이터 확인\n");

	if (s->ab == 0) {
		if (s->Aptr <= 0) { return -1; } // 스택이 빈공간
		*x = s->stk[s->Aptr - 1];
	}
	else {
		if (s->Bptr >= s->max) { return -1; } // 스택이 빈공간
		*x = s->stk[s->Bptr + 1];
	}
	return 0;
}

int Clear(INtStack* s) {
	printf("스택 비우기\n");

	if (s->ab == 0) { s->Aptr = 0; }
	else { s->Bptr = s->max - 1; }
}

int Capacity(const INtStack* s) {
	printf("\n배열의 최대용량 확인\n");

	return s->max;
}

int Size(const INtStack* s) {
	printf("배열의 데이터 개수 확인\n");

	return s->Aptr + ((s->max - 1) - (s->Bptr));
}

int Search(INtStack* s, int x) {
	printf("스택을 검색\n");

	if (s->ab == 0) {
		int i = s->Aptr;
		while (--i >= 0) {
			if (s->stk[i] == x) {
				printf("stk[%d] = %d", i, x); // 검색 성공, 해당 인덱스 출력
				return 0;
			}

		}
	}
	else {
		int i = s->Bptr;
		while (++i < s->max) {
			if (s->stk[i] == x) {
				printf("stk[%d] = %d", i, x); // 검색 성공, 해당 인덱스 출력
				return 0;
			}
		}
	}
	return -1; // 검색실패
}

void Print(INtStack* s) {
	printf("\n모든 데이터 출력\n");

	if (s->ab == 0) {
		int i = 0;
		while (i < s->Aptr) {
			printf(" %d ", s->stk[i++]);
		}
		putchar('\n');
	}
	else {
		int i = s->max - 1;
		while (i > s->Bptr) {
			printf(" %d ", s->stk[i--]);
		}
		putchar('\n');
	}
}

void Terminate(INtStack* s) {
	printf("\n스택 종료\n");

	if (s->stk != NULL) { free(s->stk); } // 배열을 삭제
	s->max = s->Aptr = s->Bptr = 0;
}