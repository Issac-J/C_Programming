#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define ENTER 13

int main(void)
{
    int ch;

    printf("Press Any Key to Convert.\n\n");

    do {
        ch = getch();
        printf("Character : %c , AscII Code : %d\n", ch, ch);
    }
    //  Enter ��(13) �Է� �� ������ ��� �ݺ��Ͽ� Ű�� �Է¹޴´�.
    while( ch != ENTER);

    return 0;
}

/*
    getch() �Լ��� Ű����κ��� ���ڸ� 1�� �Է¹޾Ƽ� int�� ���ڷ� ��ȯ�Ѵ�.

    [Note]
    1���� ���ڸ� �Է¹������� getch() �Լ��� ����Ѵ�.
    1���� ���ڸ� ����Ϸ��� putch() �Լ��� ����Ѵ�.

*/
