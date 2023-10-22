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

    qsort(arr, n, sizeof(int), compare); // ���� �� �������� ����

    long long count = 0;
    int target = arr[0]; // ���� ū �뷮�� ���� �뷮

    for (int i = 1; i < n; i++) {
        count += target - arr[i];
    }

    printf("�ʿ��� �ּ� ���� ���� ��: %lld\n", count);
    free(arr);

    return 0;
}
