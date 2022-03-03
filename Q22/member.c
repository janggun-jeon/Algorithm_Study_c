#include "main.h"

int MemberNoCmp(const Member* x, const Member* y) {
	return x->n < y->n ? -1 : x->n > y->n ? 1 : 0;
}

int MemberNameCmp(const Member* x, const Member* y) {
	return strcmp(x->name, y->name);
}

void PrintMember(const Member* x) {
	printf("%d %s", x->n, x->name);
}

Member ScanMember(const char* message, int sw) {
	Member temp;
	printf("\n%s�ϴ� �����͸� �Է��ϼ���.\n", message);
	if (sw & N) { printf("��ȣ : "); scanf("%d", &temp.n); }
	if (sw & NAME) { printf("�̸� : "); scanf("%s", &temp.name); }
	return temp;
}