#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i = 100;
    int j = 1000;
    int k = 12345;

    //  ������ ������� �ʴ� ���,
    printf("[%d]\n[%d]\n[%d]\n", i, j, k);

    //  ����� 5�ڸ��� ����.
    printf("[%5d]\n[%5d]\n[%5d]\n", i, j, k);

    //  ����� 10�ڸ��� ����.
    printf("[%10d]\n[%10d]\n[%10d]\n", i, j, k);

    //  ����� 10�ڸ��� �����ϰ� ���� ���ķ�
    printf("[%-10d]\n[%-10d]\n[%-10d]\n", i, j, k);

    return 0;
}
