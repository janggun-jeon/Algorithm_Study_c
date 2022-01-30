#define _CRT_SECURE_NO_WARNINGS // 자료입력 허용구문

#include <stdio.h>
#include <stdlib.h>

//문제18 병합 정렬 알고리즘을 작성하라.

static int* buff; // 작업용 배열

void merge(int a[], int left, int center, int right) { // 정렬된 두 배열을 병합
	int i = left;
	int j = 0; 
	int k = left;
	int p = 0;
	while (i <= center) { // left ~ center 까지 buff에 임시저장
		buff[p++] = a[i++];
	}
	while (i <= right && j < p) {
		a[k++] = (buff[j] <= a[i]) ? buff[j++] : a[i++];
	}
	while (j < p) {
		a[k++] = buff[j++];
	}
}

static void merge_after_divide(int a[], int left, int right) { // 분할 후 병합
	int center = (left + right) / 2;
	if (left < right) { // 배열의 요소가 2개이상인 경우 분할
		merge_after_divide (a, left, center);
		merge_after_divide(a, center + 1, right);
	}
	merge(a, left, center, right); // 독립적으로 정렬된 left ~ center 까지의 요소와 (center + 1) ~ right 까지의 요소를 병합
}

int merge_sort(int a[], int n) { // 병합정렬
	if( (buff = calloc(n, sizeof(int)) ) == NULL) {
		puts("\n병합 정렬에 실패");
		return -1;
	}
	merge_after_divide(a, 0, n - 1);
	free(buff); 
	return 0;
}

void main() {
	int i, n;
	int* x;
	puts("병합 정렬");
	printf("\n요소 개수 : "); scanf("%d", &n);
	x = calloc(n, sizeof(int));
	i = 0;
	while (i < n) {
		printf("x[%d] : ", i); scanf("%d", &x[i]);
		i++;
	}
	i = merge_sort(x, n);
	if (i < 0) { return; }
	else { puts("\n오름차순 정렬 완료"); }
	i = 0;
	while (i < n) {
		printf("x[%d] = %d\n", i, x[i]);
		i++;
	}
	free(x);
}