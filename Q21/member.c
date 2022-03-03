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
	printf("%s하는 데이터를 입력하세요.\n", message);
	if (sw & NO) { printf("번호 : "); scanf("%d", &temp.no); }
	if (sw & NAME) { printf("이름 : "); scanf("%s", &temp.name); }
	return temp;
}