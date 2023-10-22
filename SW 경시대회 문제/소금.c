#include <stdio.h>
#pragma warning(disable:4996)
int main() {

    int n;
    scanf("%d", &n);
    int knee[50][50];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &knee[i][j]);
        }
    }

    int minRow = n; // 무릎 상태에서 상처가 있는 가장 위의 행
    int maxRow = -1; // 무릎 상태에서 상처가 있는 가장 아래의 행
    int minCol = n; // 무릎 상태에서 상처가 있는 가장 왼쪽 열
    int maxCol = -1; // 무릎 상태에서 상처가 있는 가장 오른쪽 열

    // 상처가 있는 가장 위, 아래, 왼쪽, 오른쪽 위치를 찾음
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (knee[i][j] == 1) { // 상처를 찾을 때 마다 행,열 상태 업데이트
                minRow = (i < minRow) ? i : minRow;
                maxRow = (i > maxRow) ? i : maxRow;
                minCol = (j < minCol) ? j : minCol;
                maxCol = (j > maxCol) ? j : maxCol;
            }
        }
    }

    //상처를 모두 포함하는 직사각형의 넓이를 계산
    int width = maxCol - minCol + 1; // 가장 오른쪽 열 - 가장 왼쪽 열 + 1
    int height = maxRow - minRow + 1; // 가장 위의 행 - 가장 아래 행 + 1
    int area = width * height;

    printf("%d\n", area);

    return 0;
}