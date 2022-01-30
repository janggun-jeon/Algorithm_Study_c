#define _CRT_SECURE_NO_WARNINGS // 자료입력 허용구문
#define swap(type, x, y) do {type t = x; x = y; y = t;} while(0)

#include <stdio.h> // c언어 표준 라이브러리 : c언어에서의 입출력 함수
#include <stdlib.h> // c언어 표준 라이브러리 : 숫자 변수 , 난수 생성, 메모리 할당

//문제19 힙 정렬 알고리즘을 구현하기 위해 
//void downheap(int a[], int left, int right) : 힙을 구현하는 함수
//heapdown함수를 사용해 프로그램을 작성하라.

/*
부모 자식의 인덱스 관계
 i = 현재 가리키는 인덱스
 parent = a[(i - 1) / 2] == a[ ((i + 1) / 2) - 1 ] // i의 부모
 lefchi = a[(i * 2) + 1] // i의 좌측 자식, 2i + 1
 rigchi = a[(i * 2) + 2] // i의 우측 자식, 2i + 2
*/

static void downheap(int a[], int left, int right) { // 부분트리을 힙으로 만드는 함수
	int temp = a[left]; // 초기 부모값을 저장
	int child; 
	int parent = left;
	while (parent < (right + 1) / 2) { // 현재의 parent가 자식이 존재하는 경우 == right가 부모가 존재하는 경우
		int lefchi = (parent * 2) + 1;
		int rigchi = lefchi + 1;
		child = (rigchi <= right && a[rigchi] > a[lefchi]) ? rigchi : lefchi; //child에 대입 = (우측 자식이 존재하고, 좌측 자식보다 클때) ? 참값(rigchi) : 거짓(lefchi)
		if (temp >= a[child]) { // 부모의 값이 가장 큰 자식의 값보다 클때, 완전 이진 부분 트리 성립
			break; // 더이상 자식이 부모를 대체할 필요없음, 현재 반복문 탈출(조건문과 무관하게 가장 가까운 반복문 하나를 종료
		} // 탈출하지 못했을 경우
		a[parent] = a[child]; // 자식이 부모를 대체
		parent = child; // 부모 인덱스가 자식이 있었던 인덱스를 가리키게 됨
	}
	a[parent] = temp; // 인덱스값이 바뀐 부모에 초기 부모값을 대입
}

void heapsort(int a[], int n) { // 힙 정렬 함수
	int i;
	for (i = (n / 2) - 1; i >= 0; i--) { // 초기 i는 마지막 인덱스의 부모 인덱스
		downheap(a, i, n - 1); // ( i -> 0 )까지 i를 루트로 하는 부분트리를 힙 만들기 반복
	} // 힙 완성, 루트인 a[0]는 배열의 최대값
	i = n - 1; // 가장 뒤의 인덱스
	while (i > 0) { // 배열이 오름차순으로 정렬되도록 반복
		swap(int, a[0], a[i]); // 현재 힙의 최댓값과 마지막 값을 swap
		downheap(a, 0, --i); // 루트가 없어진 트리를 다시 힙으로 재구성 
	}
}

void main() {
	int i, n;
	int* x;
	puts("힙 정렬");
	printf("요소 개수 : "); scanf("%d", &n); putchar('\n');
	x = calloc(n, sizeof(int));
	i = 0;
	while (i < n) {
		printf("x[%d] : ", i); scanf("%d", &x[i]);
		i++;
	}
	heapsort(x, n);
	puts("\n오름차순으로 정렬됨\n");
	i = 0;
	while (i < n) {
		printf("x[%d] = %d\n", i, x[i]);
		i++;
	}
	free(x);
}