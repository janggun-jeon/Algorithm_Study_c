#include "main.h"

//����11 '�ϳ����� ž' ������ ����������� �����ϰ�, ����� �̸��� ���ڰ� �ƴ� ���ڷ� ǥ���϶�.

void move // �ϳ����� ž : n���� ���ݱ׷����� 3���� ��� ���̿��� �ּ�Ƚ���� �̵���Ű�� �˰���
(int no, int x, int y) { // no�� �̵���ų ���ݰ���, (x, y)�� (���۱��, ��ǥ���)
	INtStack ns, xs, ys;
	Initialize(&ns, 100); Initialize(&xs, 100); Initialize(&ys, 100);
	ns.ab = 0; xs.ab = 0; ys.ab = 0;
	char column[4] = { NULL, 'A', 'B', 'C' };
Top:
	if (no > 1) {
		ns.stk[ns.Aptr++] = no; xs.stk[xs.Aptr++] = x; ys.stk[ys.Aptr++] = y;
		no -= 1; y = 6 - x - y;
		goto Top;
	}
	printf("����[%d]��(��) %c ��տ��� %c ������� �̵�\n", no, column[x], column[y]);
	no = ns.stk[--ns.Aptr]; x = xs.stk[--xs.Aptr]; y = ys.stk[--ys.Aptr];
	if (ns.Aptr >= 0) {
		if (no > 1) {
			printf("����[%d]��(��) %c ��տ��� %c ������� �̵�\n", no, column[x], column[y]);
			no -= 1; x = 6 - x - y;
			goto Top;
		}
	}
	Terminate(&ns); Terminate(&xs); Terminate(&ys);
}

void main() {
	int n;
	puts("�ϳ����� ž");
	printf("���� ���� : "); scanf("%d", &n);
	putchar('\n');
	move(n, 1, 3);
}