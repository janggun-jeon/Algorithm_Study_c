#include "main.h"

int Initialize(IntQueue* q, int max) { 
	printf("\nť �ʱ�ȭ\n");

	q->num = q->front = 0; q->rear = 1;
	if ( (q->que = calloc(max, sizeof(int)) ) == NULL) {
		q->max = 0;
		return -1;
	}
	q->max = max;
	return 0;
}

int Enque(IntQueue* q, int x) {
	printf("ť�� �����͸� ��ť\n");

	if (q->num >= q->max - 2) { q->num--; } // ť�� ������
	if (q->deck == 0) { // ����Ʈ�� ��ť
		q->num++;
		q->que[(q->front)--] = x;
		if ((q->front) == -1) { q->front += q->max; } // front�� (-1)�� �������� (max - 1)�� ����
		if (q->front == q->rear) { 
			q->rear--;
			if (q->rear <= 0) { q->rear = q->max - 1; }
		}	
	}
	else { // ��� ��ť
		q->num++;
		q->que[q->rear++] = x;
		if (q->rear >= q->max) { q->rear = 0; } // rear�� max�� �������� 0���� ����
		if (q->front == q->rear) {
			q->front++;
			if (q->front >= q->max) { q->front = 0; }
		}
	}
	return 0;
}

int Deque(IntQueue* q, int* x) {
	printf("\nť�� �����͸� ��ť\n");

	if (q->num <= 0) { return -1; } // ť�� �����
	else if (q->deck == 0) { // ����Ʈ�� ��ť
		q->num--;
		q->front++;
		if ((q->front) == q->max) { q->front = 0; } // front�� max�� �������� 0���� ����
		*x = q->que[q->front];
		
	}
	else { // ��� ��ť
		q->num--;
		q->rear--;
		if ((q->rear) == -1) { q->rear += q->max; } // rear�� (-1)�� �������� (max - 1)�� ����
		*x = q->que[q->rear];
	}
	return 0;
}

int Peek(const IntQueue* q, int* x) {
	printf("\nť���� ��ũ(����Ʈ) ������ Ȯ��\n");

	if (q->num <= 0) { return -1; } // ť�� �����
	int peek = q->que[q->front + 1];
	if (q->max <= q->front + 1) { peek = q->que[0]; }
	*x = peek;
	return 0;
}

void Clear(IntQueue* q) {
	printf("\nť�� ��� ������ ����\n");

	q->num = q->front = 0; q->rear = 1;
	int i;
	for (i = 0; i < q->max; i++) {
		q->que[i] = NULL;
	}
}

int Capacity(const IntQueue* q) {
	printf("\nť�� �ִ�뷮 Ȯ��\n");

	return q->max-2;
}

int Size(const IntQueue* q) {
	printf("ť�� ����뷮 Ȯ��\n");

	return q->num;
}

int Search(IntQueue* q, int x) {
	printf("ť���� �˻�\n");

	int i = 0;
	while (++i <= q->num) {
		if (q->que[ (i + q->front) % q->max] == x) {
			return i;
		}
	}
	return -1; // �˻�����
}

void Print(IntQueue* q) {
	printf("\n����Ʈ���� ������� ��� ������ ���\n");
	
		int i = 1;
		while (i <= q->num) {
			printf(" %d ", q->que[(i++ + q->front) % q->max]);
		}
		putchar('\n');
}
	

void Terminate(IntQueue* q) {
	printf("\nť�� ����\n");

	if (q->que != NULL) { free(q->que); } // �迭�� ����
	q->max = q->num = q->front = q->rear = 0;
}