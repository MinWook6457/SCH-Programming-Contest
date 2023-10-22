#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)
typedef struct Point {
    int x, y;
    int visited; // 방문 표시
} Point;


int main() {
    int n, m;
    int x = 0, y = 0;
    scanf("%d %d", &n, &m);

    char arr[100] = { 0 };
    scanf("%s", arr);

    // 금지된 좌표 저장 배열
    int* x_arr = (int*)malloc(sizeof(int) * m);
    int* y_arr = (int*)malloc(sizeof(int) * m);
    int* count = (int*)malloc(sizeof(int) * m);

    for (int i = 0; i < m; i++) {
        scanf("%d %d", &x_arr[i], &y_arr[i]);
    }

    int len = strlen(arr);
    Point* p = (Point*)malloc(sizeof(Point) * len); // 좌표 저장할 구조체

    int visited_count = 1; // (0,0) 포함
    Point* visited = (Point*)malloc(sizeof(Point) * len);

    for (int i = 0; i < len; i++) {
        if (m != 0) {
            for (int j = 0; j < m; j++) {
                if (arr[i] == 'E' && (x + 1 != x_arr[j] || y != y_arr[j])) {
                    x++;
                }
                else if (arr[i] == 'W' && (x - 1 != x_arr[j] || y != y_arr[j])) {
                    x--;
                }
                else if (arr[i] == 'S' && (x != x_arr[j] || y - 1 != y_arr[j])) {
                    y--;
                }
                else if (arr[i] == 'N' && (x != x_arr[j] || y + 1 != y_arr[j])) {
                    y++;
                }
            }
        }
        else {
            if (arr[i] == 'E') {
                x++;
            }
            else if (arr[i] == 'W') {
                x--;
            }
            else if (arr[i] == 'S') {
                y--;
            }
            else if (arr[i] == 'N') {
                y++;
            }
        }

        p[i].x = x;
        p[i].y = y;
        p[i].visited = 1;
    }

    for (int i = 0; i < len; i++) {
        if (p[i].visited == 1) {
            visited[i].x = p[i].x;
            visited[i].y = p[i].y;
            visited[i].visited = 0;
        }
    }

    for (int i = 0; i < len; i++) {
        printf("%d %d\n", visited[i].x, visited[i].y);
        for (int j = i; j < len; j++) {
            if (p[i].x == visited[j].x && p[i].y == visited[j].y) {
                visited[i].visited += 1;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        printf("%d\n", visited[i].visited);
    }


    for (int i = 0; i < len; i++) {
        if (visited[i].visited == 1)
            visited_count += 1;
    }

    printf("visited_count : %d", visited_count);

    free(x_arr);
    free(y_arr);

    return 0;
}
