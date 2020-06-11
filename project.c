#include<stdio.h>
#include<string.h>
struct books   //BOOK DATA
{
    char  title[50];
    char  author[50];
    char  subject[100];
    char   id[10];
};
char book() //1.Add Book
{
    struct books book;
    printf("             -----ADD Books-----\n\n\n");
    gets(book.title);
    printf("            Enter The Book name:");
    gets(book.title);
    printf("            Enter Author name  :");
    gets(book.author);
    printf("            Enter subject      :");
    gets(book.subject);
    printf("             ID(from 1 to 100000):");
    scanf("%s", &book.id);
    char name[10];
    sprintf(name, "%s.txt", &book.id);
    FILE *file2;
    file2 = fopen(name, "a");
    fprintf(file2, "%s  -   %s  -  %s   -  %s\t\n",book.id, book.title, book.author, book.subject);
    fclose(file2);
}
char edit() //2. edit Book
{
    struct books book;
    printf("             -----EDIT Books-----\n\n\n");
    gets(book.title);
    printf("            Book ID(from 1 to 100000):");
    scanf("%s", &book.id);
    gets(book.title);
    printf("            Enter The book name:");
    gets(book.title);
    printf("            Enter Author        :");
    gets(book.author);
    printf("            Enter subject       :");
    gets(book.subject);

    char name[10];
    sprintf(name, "%s.txt", &book.id);
    FILE *file1;
    file1 = fopen(name, "w");
    fprintf(file1, "%s  -   %s  -  %s   -  %s\t\n",book.id, book.title, book.author, book.subject);
    fclose(file1);
}
char view() // 4. view entries
{
    char name[10];
    int q=1;
    do
    {
        sprintf(name, "%d.txt", q);
        FILE *file1;
        file1 = fopen(name, "r");
        char c;
        while((c=getc(file1))!=EOF)
            putchar(c);
        q++;
    }
    while(q<=100000);
}
char exit1()// 6.Exit
{
    system("cls");
    printf("\n");
    printf("                Bye Bye ADMIN!!!!!\n");

}
char menu()//Main menu
{
    char a, q;
    printf("\n");
    printf("\n");
    printf("\n");
    printf("                 MAIN MENU ");
    printf("\n");
    printf("                1. Add Entry    ");
    printf("\n");
    printf("                2. Edit         ");
    printf("\n");
    printf("                3. Delete        ");
    printf("\n");
    printf("                4. View Entries   ");
    printf("\n");
    printf("                5. Search Entry   ");
    printf("\n");
    printf("                 6. Exit         \n");
    printf("                *****************************");
    printf("\n");
    printf("                Enter Your Choice:");
    scanf("%d", &a);
    if(a == 1)   //1.add book
    {
        system("cls");
        do  //add book
        {
            book();
            printf("            DO YOU WANT TO ADD ANOTHER BOOK Y/N?????");
            scanf("%s", &q);
        }
        while(q == 'y');
        if(q == 'n')
        {
            system("cls");
            menu();
        }
    }
    else if(a == 2) //2.edit
    {
        system("cls");
        edit();
        printf("\nEnter 0 to Return:");
        scanf("%d", &q);
        if(q == 0)
        {
            system("cls");
            menu();
        }
    }
    else if(a == 3) //3.delete
    {
        system("cls");
        char q[10], name[10], *dlt;
        system("cls");
        printf("            ENTER THE BOOK ID YOU WANT TO DELETE:");
        scanf("%s", &q);

        sprintf(name, "%s.txt", &q);
        dlt=fopen(name, "w");
        remove(dlt);
        printf("            ENTRY DELETED!!!!!");

        printf("\n          Enter 0 to Return:");
        int w;
        scanf("%d", &w);
        if(w == 0)
        {
            system("cls");
            return menu();
        }

    }
    else if(a == 4)  //Data view
    {
        system("cls");
        view();
        printf("\nEnter 0 to Return:");
        scanf("%d", &q);
        if(q == 0)
        {
            system("cls");
            menu();
        }
    }
    else if(a == 5)  // search
    {
        char q[10], name[10];
        system("cls");
        printf("\n\n\n\n");
        printf("        ***********************************************\n");
        printf("        *****Enter The Book ID You Want to search:");
        scanf("%s", &q);
        printf("\n\nSEARCH RESULT:  ");
        sprintf(name, "%s.txt", &q);
        FILE *file1;
        file1 = fopen(name, "r");
        char c;
        while((c=getc(file1))!=EOF)
            putchar(c);
        fclose(file1);
        printf("        ***********************************************");

        printf("\n          Enter 0 to Return:");
        int w;
        scanf("%d", &w);
        if(w == 0)
        {
            system("cls");
            return menu();
        }

    }
    else if(a == 6) //6.exit
    {
        exit1();
    }
    if(a >=7)
    {
        printf("            Nothing to Show");
        printf("\n");
        printf("                Enter Your Choice(1-6):");
        scanf("%d", &a);
    }

}
int main()
{

    int a, x;
    char q;

// welcome page
    printf("                  Welcome ");
    printf("\n\n");
    printf("               Library Management System");
    printf("\n\n\n");
    printf("                 RESERVED by MAM!!!");
    printf("\n\n\n");
    printf("            Don't  worry its means Manas Arnob Momo!!!");
    printf("            Enter Your Passcode");
    printf("\n\n");
    printf("            PASSCODE:::");

    char password[10]= {"c"};

    char ch,pass[10];

    int i=0,j;


    while(ch!=13)
    {
        ch=getch();

        if(ch!=13 && ch!=8)
        {
            putch('*');
            pass[i] = ch;
            i++;
        }
    }
    pass[i] = '\0';
    if(strcmp(pass,password)==0)
    {
        system("cls");
        menu();

    }
    else
    {
        system("cls");
        main();
        getch();

    }
}

