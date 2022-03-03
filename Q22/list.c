#include "main.h"

int compare(const void* a, const void* b) { // 비교함수
	if (*(int*)a == *(int*)b) {
		return 0;
	}
	else if (*(int*)a > *(int*)b) {
		return 1;
	}
	else { return -1; }
}

static Node* AllocNode(void) { // 빈 노드 생성 및 주소 반환
	return calloc(1, sizeof(Node));
}

static void SetNode(Node* n, const Member* x,const Node* prev, const Node* next) {
	n->data = *x;
	n->prev = prev;
	n->next = next;
}

static int IsEmpty(const List* list) {
	return list->head->next == list->head;
}

void Initialize(List* list) {
	Node* dummyNode = AllocNode();
	list->head = list->crnt = dummyNode;
	dummyNode->prev = dummyNode->next = dummyNode;
}

int Next(List* list) {
	if (IsEmpty(list) || (list->crnt->next == list->head)) {
		return 0;
	}
	list->crnt = list->crnt->next;
	return 1;
}

int Prev(List* list) {
	if (IsEmpty(list) || (list->crnt->prev == list->head)) {
		return 0;
	}
	list->crnt = list->crnt->prev;
	return 1;
}

Node* search(List* list, const Member* x, int compare(const Member* x, const Member* y)) {
	Node* ptr = list->head->next;
	while (ptr != list->head) {
		if (compare(&ptr->data, x) == 0) {
			list->crnt = ptr;
			return ptr;
		}
		ptr = ptr->next;
	}
	return NULL;
}

void InsertBefore(List* list, Node* p, const Member* x) {
	Node* ptr = AllocNode();
	Node* prv = p->prev;
	p->prev = p->prev->next = ptr;
	SetNode(ptr, x, prv, p);
	list->crnt = ptr;
}

void InsertAfter(List* list, Node* p, const Member* x) {
	Node* ptr = AllocNode();
	Node* nxt = p->next;
	p->next = p->next->prev = ptr;
	SetNode(ptr, x, p, nxt);
	list->crnt = ptr;
}

void InsertFront(List* list, const Member* x) {
	InsertBefore(list, list->head->next, x);
}

void InsertRear(List* list, const Member* x) {
	InsertAfter(list, list->head->prev, x);
}

void RemoveThis(List* list, Node* p) {
	p->prev->next = p->next;
	p->next->prev = p->prev;
	if (list->crnt == p) {
		list->crnt = list->head;
	}
	free(p);
}

void RemoveFront(List* list) {
	if (!IsEmpty(list)) {
		RemoveThis(list, list->head->next);
	}
}

void RemoveRear(List* list) {
	if (!IsEmpty(list)) {
		RemoveThis(list, list->head->prev);
	}
}

void RemoveCurrent(List* list) {
	if (list->crnt != list->head) {
		RemoveThis(list, list->crnt);
	}
	else { puts("선택한 노드가 없습니다."); }
}

void Clear(List* list) {
	while (!IsEmpty(list)) {
		RemoveFront(list);
	}
}

void PrintCurrent(const List* list) {
	if (IsEmpty(list)) {
		puts("선택한 노드가 없습니다.");
	}
	else {
		PrintMember(&list->crnt->data);
		putchar('\n');
	}
}

void Print(const List* list) {
	if (IsEmpty(list)) {
		puts("노드가 없습니다.");
	}
	else {
		Node* ptr = list->head->next;
		puts("\n[ 모두 보기 ]");
		while (ptr != list->head) {
			PrintMember(&ptr->data);
			putchar('\n');
			ptr = ptr->next;
		}
	}
}

void PrintReverse(const List* list) {
	if (IsEmpty(list)) {
		puts("노드가 없습니다.");
	}
	else {
		Node* ptr = list->head->prev;
		puts("\n[ 모두 보기 ]");
		while (ptr != list->head) {
			PrintMember(&ptr->data);
			putchar('\n');
			ptr = ptr->prev;
		}
	}
}

void Terminate(List* list) {
	Clear(list);
	free(list->head);
}