//������ �Է� �ޱ� : scanf()

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int count;
    int tmp;
    int total = 0;

    for(count = 1; count <= 3; count++) {
        printf("%d ��° ���� �� �Է� : ", count);

        scanf("%d", &tmp);

        total += tmp;

        printf("�Է� �� : %d, ���� : %d\n", tmp, total);
    }

    printf("Total : %d\n", total);

    return 0;
}
