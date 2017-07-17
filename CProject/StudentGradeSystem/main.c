#include <windows.h>
#include<stdio.h>
#include<conio.h>
#include <stdlib.h>
#include<string.h>
#include<ctype.h>
#include<dos.h>
#include<time.h>


void addStudent();
void viewStudent();
void editStudent();
void decideLetterGrade(float t);
float viewGrades(float midterm_grade, float final_grade);
void Password();

char password[10]={"pokhara"};

COORD coord = {0, 0}; // sets coordinates to 0,0
//COORD max_buffer_size = GetLargestConsoleWindowSize(hOut);
COORD max_res,cursor_size;
void gotoxy (int x, int y)
{
        coord.X = x; coord.Y = y; // X and Y coordinates
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}

struct student
{
    char id[15];
    char name[30];
    char surname[25];
    char department[30];
    float midterm_grade;
    float final_grade;
    float total_grade;
    char lesson[25];
};



int main()
{

    //Password();
    int ch;

    gotoxy(20,3);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 STUDENT GRADE SYSTEM \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");


   while(1)

        {
                gotoxy(20,9);
                printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 MAIN MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
                gotoxy(20,11);
                printf("\xB2\xB2\xB2\xB2\xB2\xB2   ADD STUDENT[1]");
                gotoxy(20,13);
                printf("\xB2\xB2\xB2\xB2\xB2\xB2   VIEW STUDENT[2]");
                gotoxy(20,15);
                printf("\xB2\xB2\xB2\xB2\xB2\xB2   EDIT STUDENT[3]");
                gotoxy(20,17);
                printf("\xB2\xB2\xB2\xB2\xB2\xB2   EXIT[4]");
                gotoxy(20,19);
                printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
                printf("\n");
                printf("\n\n\t ENTER YOUR CHOICE:");
                scanf("%d",&ch);

            switch(ch)
                    {
                            case 1:
                            addStudent();
                            break;

                            case 2:
                            viewStudent();
                            break;

                            case 3:
                            editStudent();
                            break;

                            case 4:
                                system("cls");
                            printf("\n\n\t\t YILDIRIM BEYAZIT UNIVERSITY COMPUTER ENGINEERING");
                            printf("\n\n\t\t THANK YOU! THE SOFTWARE BY:BUSRA GUL\n\n\t\t...........\n\n\n");
                            delay(10);
                            exit(0);

                            default:
                            printf("\n\t\t YOU ENTERED WRONG CHOICE..");
                            printf("\n\t\t PRESS ANY KEY TO TRY AGAIN");
                            delay(10);
                            break;
                    }
                system("cls");
        }
            return 0;
}
void addStudent( )
{
                system("cls");
                FILE *fp ;
                char another = 'Y',id[15];
                struct student st ;
                char filename[20];
                int choice;

                gotoxy(20,3);
                printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 STUDENT ADD MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
                printf("\n");

                gotoxy(20,7);
                printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2  ENTER LESSON NAME OF YOUR RECORD:");
                fflush(stdin);
                gets(filename);
                fp = fopen (filename, "ab+" ) ;
                if ( fp == NULL )
                {
                fp=fopen(filename,"wb+");
                if(fp==NULL)
                {
                    printf("\n\t\t SYSTEM ERROR...");
                    printf("\n\t\t PRESS ANY KEY TO EXIT");
                    delay(10);
                    return ;
                }
                }


                while ( another == 'Y'|| another=='y' )
                {
                    choice=0;
                    fflush(stdin);
                    system("cls");
                printf ( "\n\t\t\t STUDENT ID:");
                scanf("%s",id);
                rewind(fp);

                while(fread(&st,sizeof(st),1,fp)==1)
                {
                    if(strcmp(st.id,id)==0)
                    {
                        printf("\n\t\t THE RECORD ALREADY EXISTS.\n");
                        choice=1;
                    }
                }
                    if(choice==0)
                    {
                        strcpy(st.id,id);

                        printf("\n\t\t\t ENTER NAME:");
                        fflush(stdin);
                        gets(st.name);
                        fflush(stdin);

                        printf("\n\t\t\t ENTER SURNAME:");
                        gets(st.surname);
                        fflush(stdin);

                        printf("\n\t\t\t DEPARTMENT:");
                        gets(st.department);
                        fflush(stdin);

                        printf("\n\t\t\t LESSON:");
                        gets(st.lesson);

                        printf("\n\t\t\t Enter Midterm Grade: ");
                        scanf("%f",&st.midterm_grade);

                        printf("\n\t\t\t Enter Final Grade: ");
                        scanf("%f",&st.final_grade);
                        st.total_grade=viewGrades(st.midterm_grade,st.final_grade);
                        fwrite ( &st, sizeof ( st ), 1, fp ) ;
                        system("cls");
                        gotoxy(20,10);
                        printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 YOUR RECORD IS ADDED  \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
                        printf("\n");
                    }
                        printf ( "\n\t\t ADD ANOTHER RECORD...(Y/N) " ) ;

                        fflush ( stdin ) ;
                        another = getchar( ) ;
                }

                fclose ( fp ) ;
                gotoxy(20,23);
                printf("xB2\xB2\xB2\xB2\xB2  PRESS ANY KEY TO EXIT...");
                delay(10);
    }

void viewStudent( )
{
        FILE *fpte ;
        system("cls");
        struct student st ;
        char id[15],choice,filename[20],name[30],lesson[30];
        int ch;

        gotoxy(20,3);
        printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 STUDENT VIEWING MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
        printf("\n");

        do
            {
                     system("cls");
                    gotoxy(20,5);
                    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  ENTER THE NAME OF LESSON RECORD TO BE VIEWED:");
                    fflush(stdin);
                    gets(filename);

                    fpte = fopen ( filename, "rb" ) ;
                    if ( fpte == NULL )
                            {
                                puts ( "\nTHE RECORD DOES NOT EXIST...\n" ) ;
                                printf("PRESS ANY KEY TO EXIT...");
                                delay(10);
                                return ;
                            }

                gotoxy(20,7);
                printf("\xB2\xB2\xB2\xB2\xB2  HOW WOULD YOU LIKE TO VIEW:\n");
                gotoxy(20,9);
                printf("\xB2\xB2\xB2\xB2\xB2\t1.STUDENT ID.");
                gotoxy(20,11);
                printf("\xB2\xB2\xB2\xB2\xB2\t2.STUDENT NAME");

                gotoxy(20,15);
                printf("\n\t\t\t ENTER YOUR CHOICE:");
                scanf("%d",&ch);

                switch(ch)
                {

                    case 1:
                        fflush(stdin);
                        system("cls");
                            printf("\n\t\t ENTER STUDENT ID:");
                            gets(id);
                            while ( fread ( &st, sizeof ( st ), 1, fpte ) == 1 )

                            {
                                if(strcmp(st.id,id)==0)
                                {
                            gotoxy(10,5);
                            printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 YOUR RECORD IS \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
                            printf("\n\t\t STUDENT ID: %s",st.id);
                            printf("\n\t\t STUDENT NAME: %s",st.name);
                            printf("\n\t\t TUDENT SURNAME: %s",st.surname);
                            printf("\n\t\t DEPARTMENT: %s",st.department);
                            printf("\n\t\t LESSON: %s",st.lesson);
                            printf("\n\t\t Midterm  Final Total\n\t\t");
                            printf(" %.2f\t%.2f\t%2.f\n",st.midterm_grade,st.final_grade,st.total_grade);
                            decideLetterGrade(st.total_grade);
                            gotoxy(10,17);
                            printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
                            printf("\n");
                         }
                            }
                         break;


                    case 2:

                        fflush(stdin);
                        system("cls");
                            printf("\n\n\t\t ENTER STUDENT NAME:");
                            gets(name);
                            while ( fread ( &st, sizeof ( st ), 1, fpte ) == 1 )

                            {
                                if(strcmp(st.name,name)==0)
                                {
                                    gotoxy(10,5);
                                    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 YOUR RECORD IS \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
                                    printf("\n\t\t NAME: %s",st.name);
                                    printf("\n\t\t SURNAME: %s",st.surname);
                                    printf("\n\t\t STUDENT ID: %s",st.id);
                                    printf("\n\t\t DEPARTMENT: %s",st.department);
                                    printf("\n\t\t LESSON: %s",st.lesson);
                                    printf("\n\t\t Midterm\tFinal\t\Total\n\t\t ");
                                    printf("\n\t\t Midterm  Final Total\n\t\t");
                                    printf(" %.2f\t%.2f\t%2.f\n",st.midterm_grade,st.final_grade,st.total_grade);
                                    decideLetterGrade(st.total_grade);
                                    gotoxy(10,17);
                                    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
                                    printf("\n");

                                }
                            }
                            break;

                }
               gotoxy(10,22);
               printf("\n\n\t WOULD YOU LIKE TO CONTINUE VIEWING...(Y/N):");
               fflush(stdin);
            scanf("%c",&choice);
        }while(choice=='Y'||choice=='y');
            fclose ( fpte ) ;

            return ;
}


void editStudent()
{
        system("cls");
        FILE *fpte ;
        struct student st ;
        char id[15],choice,filename[20];
        int num,count=0;

        gotoxy(20,3);
        printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 STUDENT EDITING MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
        printf("\n");


        do
            {

                   system("cls");
                    gotoxy(20,5);
                    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 ENTER THE NAME OF LESSON OF RECORD TO BE EDITED: ");
                    fflush(stdin);
                    gets(filename);
                    printf("\n\t\t\t ENTER  STUDENT ID:");
                    gets(id);
                    fpte = fopen ( filename, "rb+" ) ;
                    if ( fpte == NULL )
                            {
                                printf( "\n\t\t RECORD DOES NOT EXISTS:" ) ;
                                printf("\n\t\t PRESS ANY KEY TO GO BACK");
                                delay(10);
                                return;
                            }
                    while ( fread ( &st, sizeof ( st ), 1, fpte ) == 1 )
                    {
                        if(strcmp(st.id,id)==0)
                        {
                            gotoxy(20,10);
                            printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 YOUR OLD RECORD WAS \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
                            printf("\n\t\t\t STUDENT ID: %s",st.id);
                            printf("\n\t\t\t STUDENT NAME: %s",st.name);
                            printf("\n\t\t\t STUDENT SURNAME: %s",st.surname);
                            printf("\n\t\t\t DEPARTMENT: %s",st.department);
                            printf("\n\t\t\t LESSON: %s",st.lesson);
                            printf("\n\t\t\t Midterm  Final  Total\n\t\t\t");
                            printf("%.2f\t%.2f\t%2.f\n",st.midterm_grade,st.final_grade,st.total_grade);

                            delay(3500);
                            system("cls");

                            printf("\n\n\t\tWHAT WOULD YOU LIKE TO EDIT..");
                            gotoxy(20,5);
                                printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 1.STUDENT ID.");
                                gotoxy(20,7);
                                printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 2.STUDENT NAME.");
                                gotoxy(20,9);
                                printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 3.STUDENT SURNAME.");
                                gotoxy(20,11);
                                printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 4.STUDENT DEPARTMENT.");
                                gotoxy(20,13);
                                printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 5.STUDENT LESSON");
                                gotoxy(20,15);
                                printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 6.STUDENT MIDTERM GRADE");
                                gotoxy(20,17);
                                printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 7.STUDENT FINAL GRADE");
                                gotoxy(20,19);
                                printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 8.WHOLE STUDENT INFO.");
                                gotoxy(20,21);
                                printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 9.GO BACK TO MAIN MENU.");

                                do
                                {

                                        printf("\n\n\t ENTER YOUR CHOICE:");
                                        fflush(stdin);
                                        scanf("%d",&num);
                                        fflush(stdin);

                                        system("cls");
                                        switch(num)
                                        {
                                            case 1:
                                                printf("\n\t\t NEW STUDENT ID:");
                                                    gets(st.id);

                                                    break;

                                            case 2:
                                                   printf("\n\t\t ENTER THE NEW NAME:");
                                                    gets(st.name);
                                                    break;

                                            case 3:
                                                     printf("\n\t\t NEW THE NEW SURNAME:");
                                                    gets(st.surname);
                                                    break;

                                            case 4:
                                                    printf("\n\t\t NEW DEPARTMENT:");
                                                    gets(st.department);
                                                    break;

                                            case 5:
                                                    printf("\n\t\t NEW LESSON:");
                                                    gets(st.lesson);
                                                    break;
                                            case 6:
                                                 printf("\n\t\t NEW MIDTERM GRADE:");
                                                    scanf("%f",&st.midterm_grade);
                                                    break;
                                            case 7:
                                                 printf("\n\t\tNEW FINAL GRADE:");
                                                scanf("%f",&st.final_grade);
                                                break;

                                            case 8:
                                                     printf("\n\t\t NEW NAME:");
                                                     gets(st.name);
                                                     printf("\n\t\t NEW SURNAME:");
                                                     gets(st.surname);
                                                     printf("\n\t\t NEW STUDENT ID:");
                                                     gets(st.id);
                                                     printf("\n\t\t NEW DEPARTMENT:");
                                                     gets(st.department);
                                                     printf("\n\t\t NEW LESSON:");
                                                     gets(st.lesson);
                                                     printf("\n\t\t NEW MIDTERM GRADE:");
                                                     scanf("%f",&st.midterm_grade);
                                                     printf("\n\t\t NEW FINAL GRADE:");
                                                     scanf("%f",&st.final_grade);
                                                     break;

                                            case 9: printf("\n\t\t PRESS ANY KEY TO GO BACK...\n");
                                                    delay(10);
                                                    return ;
                                                    break;

                                            default: printf("\n\t\t YOU TYPED SOMETHING ELSE...TRY AGAIN\n");
                                                     break;
                                        }

                                }while(num<1||num>9);
                            fseek(fpte,-sizeof(st),SEEK_CUR);
                            fwrite(&st,sizeof(st),1,fpte);
                            fseek(fpte,-sizeof(st),SEEK_CUR);
                            fread(&st,sizeof(st),1,fpte);
                            choice=5;
                            break;
                        }
                    }
                    if(choice<9)
                    {
                    system("cls");
                    printf("\n\t\tEDITING COMPLETED...\n");
                    printf("--------------------\n");
                    printf("THE UPDATED RECORD IS:\n");
                    printf("--------------------\n");
                    printf("\nSTUDENT NAME: %s",st.name);
                    printf("\nSTUDENT SURNAME: %s",st.surname);
                    printf("\nSTUDENT ID: %s",st.id);
                    printf("\nDEPARTMENT: %s",st.department);
                    printf("\nLESSON: %s",st.lesson);
                    printf("\nMidterm  Final  Total\n");
                    printf("%.2f\t%.2f\t%2.f\n",st.midterm_grade,st.final_grade,st.total_grade);
                    fclose(fpte);
                    delay(2000);
                    printf("\n\n\t WOULD YOU LIKE TO EDIT ANOTHER RECORD.(Y/N)");
                    scanf("%c",&choice);
                    count++;
                    }
                    else
                    {
                        printf("\n\t\t THE RECORD DOES NOT EXIST::\n");
                        printf("\n\t\t WOULD YOU LIKE TO TRY AGAIN...(Y/N)");
                        scanf("%c",&choice);
                    }

            }while(choice=='Y'||choice=='y');
            fclose ( fpte ) ;

            if(count==1)
            printf("\n%d FILE IS EDITED...\n",count);
            else if(count>1)
            printf("\n%d FILES ARE EDITED..\n",count);
            else
            printf("\nNO FILES EDITED...\n");
            printf("\tPRESS ENTER TO EXIT EDITING MENU.");
            delay(10);
}


float viewGrades(float midterm_grade, float final_grade)
{
        float  total;
        float makeup_grade;


                            total=((midterm_grade*0.40)+(final_grade*0.60));



                            printf("\n\t\t\t Please enter Make-Up Grade: (If not exists,write '0'): ");
                            scanf("%f", &makeup_grade);


                                if ( makeup_grade == 0.0 )
                                    total = ( midterm_grade * 0.40 ) + ( final_grade * 0.60 );

                                        else
                                    total = ( midterm_grade * 0.40 ) + ( makeup_grade * 0.60 );

                  return total;
     }


void decideLetterGrade(float t)
{
        if ( t < 40.0 )
               printf("\n\t\t Grade: FF\n\t\t factor: 0.00");

               else if ( t < 50.0 )
                  printf("\n\t\t Grade: FD\n\t\t factor: 0.50");

                          else if ( t < 55.0 )
                        printf("\n\t\t Grade: DD\n\t\t factor: 1.00");

                                else if ( t < 60.0 )
                                    printf("\n\t\t Grade: DC\n\t\t factor: 1.50");

                                    else if ( t < 70.0 )
                                            printf("\n\t\t Grade: CC\n\t\t factor: 2.00");

                                        else if ( t < 75.0 )
                                                printf("\n\t\t Grade: CB\n\t\t factor: 2.50");

                                            else if ( t < 85.0 )
                                                    printf("\n\t\t Grade: BB\n\t\t factor: 3.00");

                                                else if ( t < 90.0 )
                                                        printf("\n\t\t Grade: BA\n\t\t factor: 3.50");

                                                    else
                                                        printf("\n\t\t Grade: AA\n\t\t factor: 4.00");
}

