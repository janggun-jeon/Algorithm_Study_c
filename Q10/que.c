#include "main.h"

int Initialize(IntQueue* q, int max) { 
	printf("\n큐 초기화\n");

	q->num = q->front = 0; q->rear = 1;
	if ( (q->que = calloc(max, sizeof(int)) ) == NULL) {
		q->max = 0;
		return -1;
	}
	q->max = max;
	return 0;
}

int Enque(IntQueue* q, int x) {
	printf("큐에 데이터를 인큐\n");

	if (q->num >= q->max - 2) { q->num--; } // 큐가 가득참
	if (q->deck == 0) { // 프런트에 인큐
		q->num++;
		q->que[(q->front)--] = x;
		if ((q->front) == -1) { q->front += q->max; } // front가 (-1)과 같아지면 (max - 1)로 변경
		if (q->front == q->rear) { 
			q->rear--;
			if (q->rear <= 0) { q->rear = q->max - 1; }
		}	
	}
	else { // 리어에 인큐
		q->num++;
		q->que[q->rear++] = x;
		if (q->rear >= q->max) { q->rear = 0; } // rear가 max와 같아지면 0으로 변경
		if (q->front == q->rear) {
			q->front++;
			if (q->front >= q->max) { q->front = 0; }
		}
	}
	return 0;
}

int Deque(IntQueue* q, int* x) {
	printf("\n큐에 데이터를 디큐\n");

	if (q->num <= 0) { return -1; } // 큐가 빈공간
	else if (q->deck == 0) { // 프런트에 디큐
		q->num--;
		q->front++;
		if ((q->front) == q->max) { q->front = 0; } // front가 max와 같아지면 0으로 변경
		*x = q->que[q->front];
		
	}
	else { // 리어에 디큐
		q->num--;
		q->rear--;
		if ((q->rear) == -1) { q->rear += q->max; } // rear가 (-1)과 같아지면 (max - 1)로 변경
		*x = q->que[q->rear];
	}
	return 0;
}

int Peek(const IntQueue* q, int* x) {
	printf("\n큐에서 피크(프런트) 데이터 확인\n");

	if (q->num <= 0) { return -1; } // 큐가 빈공간
	int peek = q->que[q->front + 1];
	if (q->max <= q->front + 1) { peek = q->que[0]; }
	*x = peek;
	return 0;
}

void Clear(IntQueue* q) {
	printf("\n큐의 모든 데이터 비우기\n");

	q->num = q->front = 0; q->rear = 1;
	int i;
	for (i = 0; i < q->max; i++) {
		q->que[i] = NULL;
	}
}

int Capacity(const IntQueue* q) {
	printf("\n큐의 최대용량 확인\n");

	return q->max-2;
}

int Size(const IntQueue* q) {
	printf("큐의 현재용량 확인\n");

	return q->num;
}

int Search(IntQueue* q, int x) {
	printf("큐에서 검색\n");

	int i = 0;
	while (++i <= q->num) {
		if (q->que[ (i + q->front) % q->max] == x) {
			return i;
		}
	}
	return -1; // 검색실패
}

void Print(IntQueue* q) {
	printf("\n프런트에서 리어까지 모든 데이터 출력\n");
	
		int i = 1;
		while (i <= q->num) {
			printf(" %d ", q->que[(i++ + q->front) % q->max]);
		}
		putchar('\n');
}
	

void Terminate(IntQueue* q) {
	printf("\n큐를 종료\n");

	if (q->que != NULL) { free(q->que); } // 배열을 삭제
	q->max = q->num = q->front = q->rear = 0;
}