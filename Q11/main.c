#include "main.h"

//문제11 '하노이의 탑' 문제를 비재귀적으로 구현하고, 기둥의 이름을 숫자가 아닌 문자로 표현하라.

void move // 하노이의 탑 : n개의 원반그룹을을 3개의 기둥 사이에서 최소횟수로 이동시키는 알고리즘
(int no, int x, int y) { // no는 이동시킬 원반개수, (x, y)는 (시작기둥, 목표기둥)
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
	printf("원반[%d]를(을) %c 기둥에서 %c 기둥으로 이동\n", no, column[x], column[y]);
	no = ns.stk[--ns.Aptr]; x = xs.stk[--xs.Aptr]; y = ys.stk[--ys.Aptr];
	if (ns.Aptr >= 0) {
		if (no > 1) {
			printf("원반[%d]를(을) %c 기둥에서 %c 기둥으로 이동\n", no, column[x], column[y]);
			no -= 1; x = 6 - x - y;
			goto Top;
		}
	}
	Terminate(&ns); Terminate(&xs); Terminate(&ys);
}

void main() {
	int n;
	puts("하노이의 탑");
	printf("원반 개수 : "); scanf("%d", &n);
	putchar('\n');
	move(n, 1, 3);
}