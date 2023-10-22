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

    int minRow = n; // ���� ���¿��� ��ó�� �ִ� ���� ���� ��
    int maxRow = -1; // ���� ���¿��� ��ó�� �ִ� ���� �Ʒ��� ��
    int minCol = n; // ���� ���¿��� ��ó�� �ִ� ���� ���� ��
    int maxCol = -1; // ���� ���¿��� ��ó�� �ִ� ���� ������ ��

    // ��ó�� �ִ� ���� ��, �Ʒ�, ����, ������ ��ġ�� ã��
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (knee[i][j] == 1) { // ��ó�� ã�� �� ���� ��,�� ���� ������Ʈ
                minRow = (i < minRow) ? i : minRow;
                maxRow = (i > maxRow) ? i : maxRow;
                minCol = (j < minCol) ? j : minCol;
                maxCol = (j > maxCol) ? j : maxCol;
            }
        }
    }

    //��ó�� ��� �����ϴ� ���簢���� ���̸� ���
    int width = maxCol - minCol + 1; // ���� ������ �� - ���� ���� �� + 1
    int height = maxRow - minRow + 1; // ���� ���� �� - ���� �Ʒ� �� + 1
    int area = width * height;

    printf("%d\n", area);

    return 0;
}