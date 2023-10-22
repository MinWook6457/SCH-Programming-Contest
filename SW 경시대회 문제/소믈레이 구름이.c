#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
int compare(const void* a, const void* b) {
    return (*(int*)b - *(int*)a);
}

int main() {
    int n;
    scanf("%d", &n);

    int* arr = (int*)malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    qsort(arr, n, sizeof(int), compare); // 와인 잔 내림차순 정렬

    long long count = 0;
    int target = arr[0]; // 가장 큰 용량의 잔의 용량

    for (int i = 1; i < n; i++) {
        count += target - arr[i];
    }

    printf("필요한 최소 와인 잔의 수: %lld\n", count);
    free(arr);

    return 0;
}
