#define _CRT_SECURE_NO_WARNINGS // �ڷ��Է� ��뱸��
#define swap(type, x, y) do {type t = x; x = y; y = t;} while(0)

#include <stdio.h> // c��� ǥ�� ���̺귯�� : c������ ����� �Լ�
#include <stdlib.h> // c��� ǥ�� ���̺귯�� : ���� ���� , ���� ����, �޸� �Ҵ�

//����19 �� ���� �˰����� �����ϱ� ���� 
//void downheap(int a[], int left, int right) : ���� �����ϴ� �Լ�
//heapdown�Լ��� ����� ���α׷��� �ۼ��϶�.

/*
�θ� �ڽ��� �ε��� ����
 i = ���� ����Ű�� �ε���
 parent = a[(i - 1) / 2] == a[ ((i + 1) / 2) - 1 ] // i�� �θ�
 lefchi = a[(i * 2) + 1] // i�� ���� �ڽ�, 2i + 1
 rigchi = a[(i * 2) + 2] // i�� ���� �ڽ�, 2i + 2
*/

static void downheap(int a[], int left, int right) { // �κ�Ʈ���� ������ ����� �Լ�
	int temp = a[left]; // �ʱ� �θ��� ����
	int child; 
	int parent = left;
	while (parent < (right + 1) / 2) { // ������ parent�� �ڽ��� �����ϴ� ��� == right�� �θ� �����ϴ� ���
		int lefchi = (parent * 2) + 1;
		int rigchi = lefchi + 1;
		child = (rigchi <= right && a[rigchi] > a[lefchi]) ? rigchi : lefchi; //child�� ���� = (���� �ڽ��� �����ϰ�, ���� �ڽĺ��� Ŭ��) ? ����(rigchi) : ����(lefchi)
		if (temp >= a[child]) { // �θ��� ���� ���� ū �ڽ��� ������ Ŭ��, ���� ���� �κ� Ʈ�� ����
			break; // ���̻� �ڽ��� �θ� ��ü�� �ʿ����, ���� �ݺ��� Ż��(���ǹ��� �����ϰ� ���� ����� �ݺ��� �ϳ��� ����
		} // Ż������ ������ ���
		a[parent] = a[child]; // �ڽ��� �θ� ��ü
		parent = child; // �θ� �ε����� �ڽ��� �־��� �ε����� ����Ű�� ��
	}
	a[parent] = temp; // �ε������� �ٲ� �θ� �ʱ� �θ��� ����
}

void heapsort(int a[], int n) { // �� ���� �Լ�
	int i;
	for (i = (n / 2) - 1; i >= 0; i--) { // �ʱ� i�� ������ �ε����� �θ� �ε���
		downheap(a, i, n - 1); // ( i -> 0 )���� i�� ��Ʈ�� �ϴ� �κ�Ʈ���� �� ����� �ݺ�
	} // �� �ϼ�, ��Ʈ�� a[0]�� �迭�� �ִ밪
	i = n - 1; // ���� ���� �ε���
	while (i > 0) { // �迭�� ������������ ���ĵǵ��� �ݺ�
		swap(int, a[0], a[i]); // ���� ���� �ִ񰪰� ������ ���� swap
		downheap(a, 0, --i); // ��Ʈ�� ������ Ʈ���� �ٽ� ������ �籸�� 
	}
}

void main() {
	int i, n;
	int* x;
	puts("�� ����");
	printf("��� ���� : "); scanf("%d", &n); putchar('\n');
	x = calloc(n, sizeof(int));
	i = 0;
	while (i < n) {
		printf("x[%d] : ", i); scanf("%d", &x[i]);
		i++;
	}
	heapsort(x, n);
	puts("\n������������ ���ĵ�\n");
	i = 0;
	while (i < n) {
		printf("x[%d] = %d\n", i, x[i]);
		i++;
	}
	free(x);
}