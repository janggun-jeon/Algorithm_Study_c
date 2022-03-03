#include "main.h"

int MemberNoCmp(const Member* x, const Member* y) {
	return x->no < y->no ? -1 : x->no > y->no ? 1 : 0;
}

int MemberNameCmp(const Member* x, const Member* y) {
	return strcmp(x->name, y->name);
}

void PrintMember(const Member* x) {
	printf("%d %s", x->no, x->name);
}

Member ScanMember(const char* message, int sw) {
	Member temp;
	printf("%s�ϴ� �����͸� �Է��ϼ���.\n", message);
	if (sw & NO) { printf("��ȣ : "); scanf("%d", &temp.no); }
	if (sw & NAME) { printf("�̸� : "); scanf("%s", &temp.name); }
	return temp;
}