#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void main(void)
{
    print("This is a putch function !");
}

int print(char *string) {

    int len = 0;

    //  ���ڿ��� NULL�� ������ �� ����Ǳ� ������, ���� string �� ����Ű�� ������ ���� NULL�� �� ������ �ݺ� ����.
    while( *string != (char)NULL ) {

        //  ���� string �� ����Ű�� ������ ���ڸ� ����Ѵ�.
        putch( *string );

        //  string �� ����Ű�� ������ 1��ŭ ����
        string++;
        len++;
    }

    //  ���� ��µǰ� �ִ� ���� ���� ���� ù ��°�� �̵�
    putch('\r');    //  ĳ���� ����(CR)
    putch('\n');    //  ���� �ǵ�(LF)

    return len;
}

/*
    ĳ���� ����(CR) : `�� ������ �̵�` �϶�� �ǹ�
    ���� �ǵ�(LF) : `���ο� ����` �̶�� �ǹ�
*/
