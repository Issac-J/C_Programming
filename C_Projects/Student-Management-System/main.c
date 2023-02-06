#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

#define ENTER 13

void add(FILE * fp);
void modify(FILE * fp);
void display(FILE * fp);
void Indivisual(FILE *fp);
void password();
void printChar(char ch,int n);
void title();

FILE * del(FILE * fp);
FILE *tp;

struct student {
    char name[100];
    char dept[50];
    int roll;
    float sgpa[12];
    float cgpa;
};

struct pass {
    char pass[25];
}pa;

void gotoXY(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void setColor(unsigned short text, unsigned short back) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), text | (back << 4));
}

int main()
{
    SetConsoleTitle("*** Student Management System ***");
    setColor(7, 0);

    // Declare Variables.
    int k;
    char password[10];
    int option;

    FILE *fp;

    // FILE Check
    // Not exist file
//    if((fp=) == NULL) {
//
//    }

    // Move Cursor
    gotoXY(42, 8);
    printf("LOGIN (If 1st login press ENTER)");

    gotoXY(42, 10);
    printf("********************************");

    gotoXY(42, 11);
    printf(" Enter Password :               ");

    gotoXY(42, 12);
    printf("********************************");

    gotoXY(60, 11);

    //  10�ڸ� ��й�ȣ�� �Է�.(10�ڸ��̱� ������ k<10 ����)
    //  k�� ���� 0 ���� ����.
    while( k<10 ) {

        //  ���� �Է� �޾� �迭 password �� ����.
        password[k] = getch();
        char s = password[k];

        //  ENTER Key�� ������ �Է� ����.
        //  �ƴ� ��� �Է��� ������ "*" �� ���.
        if(s == ENTER) break;
        else    printf("*");

        k++;
    }

    //  getch() �� ���� �Է� �޾ұ� ������ ���ڿ� �������� ���ڿ� ���Ḧ �˸��� '\0' �� �ִ´�.
    password[k]='\0';

    tp = fopen("password.txt", "r+");

    //  fgets : ��Ʈ��(stream) ���� ���ڿ��� �޴´�.
    //  char* fgets(char* str, int num, FILE* stream)
    /*
        Stream ���� ���ڿ��� �޾Ƽ� num-1 ���� ���ڸ� �Է� ���� �� ������, ���� ���ڳ� ���� ���� ������ ������ �Է� �޾Ƽ� C ������ ���ڿ��� �����Ѵ�.
        ���๮�ڴ� fgets �� �Ͽ��� �Է��� ������ ������ �� ����(���๮��) ���� str �� �����Ѵ�. (NULL ���ڴ� �ڵ������� ���������� �Է¹��� ���� �ڿ� �ٴ´�.)

        fgets �Լ��� scanf �Լ��ʹ� �޸� ���� ���� ���ڿ� ���ؼ��� �Է��� ������ ������ ���Ⱑ �ִ� ���ڿ��� �Է� ���� �� �ִ�.
        �ݸ�, scanf �Լ��� ��� ���� ���� �Ӹ� �ƴ϶� ''�� '\t' �� ���ؼ��� �Է��� ������ ������ ���Ⱑ �ִ� ���ڿ��� �Է� ���� �� ����.
    */
    fgets(pa.pass, 25, tp);

    if(strcmp(password, pa.pass) == 0) {
        system("cls");
        gotoXY(10, 3);
        printf("<<<<   Loading Please Wait   >>>>\n\n\n");
        printf("\t\t");

        for(int i=0; i<5; i++) {
            printf("****");
//            Sleep(500);
        }

        printf(" \n\n\n\n\n\t\t\t\t\t     *  *  *  *  *  *  *  *");
		printf("\n\n\t\t\t\t\t     *                    *");
		printf("\n\n\t\t\t\t\t     *       Welcome      *");
		printf("\n\n\t\t\t\t\t     *                    *");
		printf("\n\n\t\t\t\t\t     *  *  *  *  *  *  *  *");
		printf("\n\n\n\n\n\t\t\t\t\tPress any key to continue...... ");
//		getch();

        title();
        gotoXY(30, 5);
        printf("Korea University 2023");
        printf("\n\n\t\t\t\t    The A Team\n\n\t\t       ");
        printChar('=', 38);
        printf("\n\n\n\t\t\t     press any key to Enter...");
//        getch();

        while(1) {
            title();
            printf("\n\t");
            printChar('*',64);

            printf("\n\n\t\t\t\t1. Add Student");
            printf("\n\n\t\t\t\t2. Modify Student");
            printf("\n\n\t\t\t\t3. Show All Student");
            printf("\n\n\t\t\t\t4. Individual View");
            printf("\n\n\t\t\t\t5. Remove Student");
            printf("\n\n\t\t\t\t6. Change Password");
            printf("\n\n\t\t\t\t7. Logout\n\t");
            printf("\n\t");
            printChar('*',64);

            printf("\n\n\t\t\t\tEnter Your Option :--> ");
            scanf("%d",&option);

            switch(option) {
            //  add
            case 1:
                add(fp);
                break;

            //  modify
            case 2:
                modify(fp);
                break;

            //  display
            case 3:
                display(fp);
                break;

            //  indivisual
            case 4:
                Indivisual(fp);
                break;

            //  delete
            case 5:
                fp=del(fp);
                break;

            //  Change password
            case 6:
                system("cls");
				system("color 5f");
//                password();
                break;

            //  Logout
            case 7:
                return 1;
                break;

            default:
                printf("\n\t\tNot Invalid Number");
                printf("\n\t\tPress Any Key\n\n\n");
                getch();
                system("pause");
            }
        }
    }

    else {
        gotoXY(60, 11);
        printf("Not invaild Password");
    }

    return 0;
}

void title() {
    system("cls");
    setColor(6, 0);
    printf("\n\n\t");
    printChar('=',19);
    printf(" Student Management System ");
    printChar('=',19);
    printf("\n");
}

void password()
{
	char c;
	printf("\nEnter new password :");
	fflush(stdin);
	gets(pa.pass);
	printf("\nSave password (y/n) :");
	fflush(stdin);
	scanf("%c",&c);
	if(c=='y'||c=='Y')
	{
		tp=fopen("F:/Password.txt","w+");
	    fwrite(&pa,sizeof(pa),1,tp);
	    fclose(tp);
		printf("\n\tPassword Saved\n");
	}
	else
	{
		printf("Password not saved :\n");
		printf("Press any key to continue >>>");
		getch();
	}
}

void printChar(char ch, int n) {
    while( n > 0 ) {
        putchar(ch);
        n--;
    }
}

void add(FILE *fp) {
    title();
    printf("I'm add Function\n");
    char another = 'y';
    struct student s;

    int i;
    float cgpa;
//
//    fseek(fp,0,SEEK_END);
//
    while(another == 'y' || another == 'Y') {
        //  Input Student Name
        printf("\n\n\t\tEnter Full Name of Student: ");
        fflush(stdin);
        fgets(s.name, 100, stdin);
        s.name[strlen(s.name) - 1] = '\0';

        //  Input Student Department
        printf("\n\n\t\tEnter Department: ");
        fflush(stdin);
        fgets(s.dept, 50, stdin);
        s.dept[strlen(s.dept) - 1] = '\0';

        printf("\n\n\t\tEnter Roll number: ");
        scanf("%d",&s.roll);

        printf("\n\n\t\tEnter SGPA for 12 semesters\n\t\t");
        for( i=0, cgpa=0; i<12; i++) {
            scanf("%f", &s.sgpa[i]);
            cgpa += s.sgpa[i];
        }

        cgpa /= 12.0;
        s.cgpa = cgpa;

        fwrite(&s,sizeof(s),1,fp);

//        printf("%s %s %d", s.name, s.dept, s.roll);
//        for(i=0; i<12; i++) {
//
//        }

        printf("\n\n\t\tAdd another student?(Y/N)?");
        fflush(stdin);
        another=getchar();

    }

}

FILE * del(FILE * fp)
{
    title();

    struct student s;
    int flag=0,tempRoll,siz=sizeof(s);
    FILE *ft;

    if((ft=fopen("temp.txt","wb+"))==NULL)
    {
        printf("\n\n\t\t\t\\t!!! ERROR !!!\n\t\t");
        system("pause");
        return fp;
    }

    printf("\n\n\tEnter Roll number of Student to Delete the Record");
    printf("\n\n\t\t\tRoll No. : ");
    scanf("%d",&tempRoll);

    rewind(fp);


    while((fread(&s,siz,1,fp))==1)
    {
        if(s.roll==tempRoll)
        {
            flag=1;
            printf("\n\tRecord Deleted for");
            printf("\n\n\t\t%s\n\n\t\t%s\n\n\t\t%d\n\t",s.name,s.dept,s.roll);
            continue;
        }

        fwrite(&s,siz,1,ft);
    }


    fclose(fp);
    fclose(ft);

    remove("db.txt");
    rename("temp.txt","db.txt");

    if((fp=fopen("db.txt","rb+"))==NULL)
    {
        printf("ERROR");
        return  NULL;
    }

    if(flag==0) printf("\n\n\t\tNO STUDENT FOUND WITH THE INFORMATION\n\t");

    printChar('-',65);
    printf("\n\t");
    system("pause");
    return fp;
}


void modify(FILE * fp)
{
    title();

    struct student s;
    int i,flag=0,tempRoll,siz=sizeof(s);
    float cgpa;

    printf("\n\n\tEnter Roll Number of Student to MODIFY the Record : ");
    scanf("%d",&tempRoll);

    rewind(fp);

    while((fread(&s,siz,1,fp))==1)
    {
        if(s.roll==tempRoll)
        {
            flag=1;
            break;
        }
    }

    if(flag==1)
    {
        fseek(fp,-siz,SEEK_CUR);
        printf("\n\n\t\t\t\tRecord Found\n\t\t\t");
        printChar('=',38);
        printf("\n\n\t\t\tStudent Name: %s",s.name);
        printf("\n\n\t\t\tStudent Roll: %d\n\t\t\t",s.roll);
        printChar('=',38);
        printf("\n\n\t\t\tEnter New Data for the student");

        printf("\n\n\t\t\tEnter Full Name of Student: ");
        fflush(stdin);
        fgets(s.name,100,stdin);
        s.name[strlen(s.name)-1]='\0';

        printf("\n\n\t\t\tEnter Department: ");
        fflush(stdin);
        fgets(s.dept,50,stdin);
        s.dept[strlen(s.dept)-1]='\0';

        printf("\n\n\t\t\tEnter Roll number: ");
        scanf("%d",&s.roll);


        printf("\n\n\t\tEnter SGPA for 12 semesters\n");
        for(i=0,cgpa=0; i<12; i++)
        {
            scanf("%f",&s.sgpa[i]);
            cgpa+=s.sgpa[i];

        }
        cgpa=cgpa/8.0;


        fwrite(&s,sizeof(s),1,fp);
    }

    else printf("\n\n\t!!!! ERROR !!!! RECORD NOT FOUND");

    printf("\n\n\t");
    system("pause");

}

void display(FILE * fp)
{
    title();
    struct student s;
    int i,siz=sizeof(s);

    rewind(fp);

    while((fread(&s,siz,1,fp))==1)
    {
        printf("\n\t\tNAME : %s",s.name);
        printf("\n\n\t\tDepertment : %s",s.dept);
        printf("\n\n\t\tROLL : %d",s.roll);
        printf("\n\n\tSGPA: ");

        for(i=0; i<-12; i++)
            printf("| %.2f |",s.sgpa[i]);
        printf("\n\n\t\tCGPA : %.2f\n\t",s.cgpa);
        printChar('-',65);
    }
    printf("\n\n\n\t");
    printChar('*',65);
    printf("\n\n\t");
    system("pause");
}

void Indivisual(FILE *fp)
{
    title();

    int tempRoll,flag,siz,i;
    struct student s;
    char another='y';

    siz=sizeof(s);

    while(another=='y'||another=='Y')
    {
        printf("\n\n\tEnter Roll Number: ");
        scanf("%d",&tempRoll);

        rewind(fp);

        while((fread(&s,siz,1,fp))==1)
        {
            if(s.roll==tempRoll)
            {
                flag=1;
                break;
            }
        }

        if(flag==1)
        {
            printf("\n\t\tNAME : %s",s.name);
            printf("\n\n\t\tDepartment : %s",s.dept);
            printf("\n\n\t\tROLL : %d",s.roll);
            printf("\n\n\tSGPA: ");

            for(i=0; i<12; i++)
                printf("| %.2f |",s.sgpa[i]);
            printf("\n\n\t\tCGPA : %.2f\n\t",s.cgpa);
            printChar('-',65);

        }
        else printf("\n\n\t\t!!!! ERROR RECORD NOT FOUND !!!!");


        printf("\n\n\t\tShow another student information? (Y/N)?");
        fflush(stdin);
        another=getchar();
    }
}
