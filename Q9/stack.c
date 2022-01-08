#include "main.h"

int Initialize(INtStack* s, int max) { // ������ ������ Ȯ���ϱ� ���ؼ� ���� ���θ� ���
	printf("���� �ʱ�ȭ\n");

	s->Aptr = 0; // �迭�� ���� �ε���
	s->Bptr = max - 1; // �迭�� �ְ� �ε���
	if ((s->stk = calloc(max, sizeof(int))) == NULL) { // �ϴ� ���ϴ� �뷮��ŭ �迭 ���� �õ�
		s->max = 0;
		return -1; // ���� �ʱ�ȭ ����
	}
	s->max = max; // ���� �뷮�� ��Ÿ���� ���� ����ü s�� ��� max�� ����
	return 0; // ���� �ʱ�ȭ ����
}

int Push(INtStack* s, int x) {
	printf("���ÿ� ������ Ǫ��\n");

	if (s->Aptr > s->Bptr) { return -1; } // ������ ������
	if (s->ab == 0) {
		s->stk[s->Aptr++] = x;
	}
	else {
		s->stk[s->Bptr--] = x;
	}
	return 0;
}

int Pop(INtStack* s, int* x) {
	printf("\n���ÿ� ������ ��\n");

	if (s->ab == 0) {
		if (s->Aptr == 0) { return -1; } // ������ �����
		*x = s->stk[--(s->Aptr)];
	}
	else {
		if (s->Bptr == s->max - 1) { return -1; } // ������ �����
		*x = s->stk[++(s->Bptr)];
	}
	return 0;
}

int Peek(const INtStack* s, int* x) {
	printf("\n���ÿ� ��ũ ������ Ȯ��\n");

	if (s->ab == 0) {
		if (s->Aptr <= 0) { return -1; } // ������ �����
		*x = s->stk[s->Aptr - 1];
	}
	else {
		if (s->Bptr >= s->max) { return -1; } // ������ �����
		*x = s->stk[s->Bptr + 1];
	}
	return 0;
}

int Clear(INtStack* s) {
	printf("���� ����\n");

	if (s->ab == 0) { s->Aptr = 0; }
	else { s->Bptr = s->max - 1; }
}

int Capacity(const INtStack* s) {
	printf("\n�迭�� �ִ�뷮 Ȯ��\n");

	return s->max;
}

int Size(const INtStack* s) {
	printf("�迭�� ������ ���� Ȯ��\n");

	return s->Aptr + ((s->max - 1) - (s->Bptr));
}

int Search(INtStack* s, int x) {
	printf("������ �˻�\n");

	if (s->ab == 0) {
		int i = s->Aptr;
		while (--i >= 0) {
			if (s->stk[i] == x) {
				printf("stk[%d] = %d", i, x); // �˻� ����, �ش� �ε��� ���
				return 0;
			}

		}
	}
	else {
		int i = s->Bptr;
		while (++i < s->max) {
			if (s->stk[i] == x) {
				printf("stk[%d] = %d", i, x); // �˻� ����, �ش� �ε��� ���
				return 0;
			}
		}
	}
	return -1; // �˻�����
}

void Print(INtStack* s) {
	printf("\n��� ������ ���\n");

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
	printf("\n���� ����\n");

	if (s->stk != NULL) { free(s->stk); } // �迭�� ����
	s->max = s->Aptr = s->Bptr = 0;
}