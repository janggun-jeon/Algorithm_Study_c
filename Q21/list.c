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

static void SetNode(Node* n, const Member* x, const Node* next) {
	n->data = *x;
	n->next = next;
}

void Initialize(List* list){
	list->head = NULL;
	list->crnt = NULL;
}

Node* search(List* list, const Member* x, int compare(const Member* x, const Member* y)) {
	Node* ptr = list->head;
	while (ptr != NULL) {
		if (compare(&ptr->data, x) == 0) {
			list->crnt = ptr;
			return ptr;
		}
		ptr = ptr->next;
	}
	return NULL;
}

void InsertFront(List* list, const Member* x) {
	Node* ptr = list->head;
	list->head = list->crnt = AllocNode();
	SetNode(list->head, x, ptr);
}

void InsertRear(List* list, const Member* x) {
	if (list->head == NULL) {
		InsertFront(list, x);
	}
	else {
		Node* ptr = list->head;
		while (ptr->next != NULL) {
			ptr = ptr->next;
		}
		ptr->next = list->crnt = AllocNode();
		SetNode(ptr->next, x, NULL);
	}
}

void RemoveFront(List* list) {
	if (list->head != NULL) {
		Node* ptr = list->head->next;
		free(list->head);
		list->head = list->crnt = ptr;
	}
}

void RemoveRear(List* list) {
	if (list->head != NULL) {
		if ((list->head)->next == NULL) { 
			RemoveFront(list); 
		}
		else {
			Node* ptr = list->head;
			Node* pre;
			while (ptr->next != NULL) {
				pre = ptr;
				ptr = ptr->next;
			}
			pre->next = NULL;
			free(ptr);
			list->crnt = pre;
		}
	}
}

void RemoveCurrent(List* list) {
	if (list->head != NULL) {
		if (list->crnt == list->head) {
			RemoveFront(list);
		}
		else {
			Node* ptr = list->head;
			while (ptr->next != list->crnt) { // crnt의 바로 직전 노드를 ptr 가리킬때 까지 반복
				ptr = ptr->next;
			}
			ptr->next = list->crnt->next;
			free(list->crnt);
			list->crnt = ptr;
		}
	}
}

void Clear(List* list) {
	while (list->head != NULL) {
		RemoveFront(list);
	}
	list->crnt = NULL;
}

void PrintCurrent(const List* list) {
	if (list->crnt == NULL) {
		puts("선택한 노드가 없습니다.");
	}
	else {
		PrintMember(&list->crnt->data);
		putchar('\n');
	}
}

void Print(const List* list) {
	if (list->head == NULL) {
		puts("노드가 없습니다.");
	}
	else {
		Node* ptr = list->head;
		puts("\n[ 모두 보기 ]");
		while (ptr != NULL) {
			PrintMember(&ptr->data);
			putchar('\n');
			ptr = ptr->next;
		}
	}
}