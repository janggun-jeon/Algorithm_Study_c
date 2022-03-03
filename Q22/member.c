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
	printf("\n%s하는 데이터를 입력하세요.\n", message);
	if (sw & N) { printf("번호 : "); scanf("%d", &temp.n); }
	if (sw & NAME) { printf("이름 : "); scanf("%s", &temp.name); }
	return temp;
}