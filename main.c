#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

struct admin
{

};

struct teacher
{
    char tun[20];
    char tpw[20];
    char na[20];
    char cur[20];
    int id;
    char dn[20];
} tcr;

struct student
{
    char sun[20];
    char spw[20];
    char na[20];
    int id;
    char cl[20];
    char marks[20];
} stud;

int main()
{
    welcomeScreen();
    login_menu();
    return 0;
}

void welcomeScreen()
{
    printf("\n\n\n\n\n\t\t\t\t\t#####################################");
    printf("\n\t\t\t \t\t\t WelCome to Our School \t\t ");
    printf("\n\t\t\t\t\t# This is school management program #");
    printf("\n\t\t\t\t\t#####################################");
    printf("\n\n\t\t\t\t\tPress any key to continue....");
    getch();
    system("cls");
}

void login_menu()
{
    system("cls");
    int ch;
    printf("\n\n\n\t\t\t\t\t Login Page\n");
    printf("\n\t\t\t\t\t 1. Login as Admin");
    printf("\n\t\t\t\t\t 2. Login as Teacher");
    printf("\n\t\t\t\t\t 3. Login as Student");
    printf("\n\n\t\t\t\t\tEnter your choice: ");
    scanf("%d", &ch);
    switch(ch)
    {
    case 1:
        admin_login();
        break;
    case 2:
        teacher_login();
        break;
    case 3:
        student_login();
        break;
    }
    getch();
    system("cls");
}

void admin_login()
{
    system("cls");
    char admin_un[20];
    char admin_pw[20];
    char admin_d_un[20] = "admin";
    char admin_d_pw[20] = "admin";
    printf("\n\n\n\t\t\t\t\tDefault Admin Username is: \t admin");
    printf("\n\t\t\t\t\tDefault Admin Password is: \t admin");
    printf("\n\n\t\t\t\t\tEnter admin username: ");
    fflush(stdin);
    gets(admin_un);
    printf("\n\t\t\t\t\tEnter admin password: ");
    fflush(stdin);
    gets(admin_pw);
    while(1)
    {
        if( strcmp(admin_un,admin_d_un) ==0  && strcmp(admin_pw, admin_d_pw)==0)
        {
            printf("\n\t\t\t\t\tWelcome to admin menu");
            printf("\n\t\t\t\t\tPress any key continue....");
            getch();
            admin_options();
            break;
        }
        else
        {
            printf("\n\t\t\t\t\tUsername and Password didn't match.\n");
            printf("\n\t\t\t\t\tPress any key for retry...\n");

            getch();
            admin_login();
            break;
        }
    }
}

void teacher_login()
{

    FILE *fp;
    long sz = sizeof(tcr);

    fp = fopen("teachers.txt","rb");

    char teacher_un[20];
    char teacher_pw[20];
    printf("\n\n\t\t\t\t\tEnter teacher username: ");
    fflush(stdin);
    gets(teacher_un);
    printf("\n\t\t\t\t\tEnter teacher password: ");
    fflush(stdin);
    gets(teacher_pw);

    int f=0;
    if(fp==NULL)
    {
        return;
    }
    while(fread(&tcr, sz, 1, fp))
    {
        if( strcmp(teacher_un,tcr.tun) ==0  && strcmp(teacher_pw, tcr.tpw)==0)
        {
            f=1;
            printf("\n\t\t\t\t\tHi, %s your are welcome to teacher menu.\n\t\t\t\t\tPress any key to continue...\n",tcr.na);
            getch();
            teacher_menu();


        }

    }

    fclose(fp);

    if(f==0)
    {
        printf("\n\t\t\t\t\tUsername and Password didn't match.\n");
        teacher_login();
    }

}

void student_login()
{

    FILE *fp;
    long sz = sizeof(stud);

    fp = fopen("students.txt","rb");

    char student_un[20];
    char student_pw[20];

    printf("\n\n\t\t\t\t\tEnter student username: ");
    fflush(stdin);
    gets(student_un);
    printf("\n\t\t\t\t\tEnter student password: ");
    fflush(stdin);
    gets(student_pw);

    int f=0;
    if(fp==NULL)
    {
        return;
    }
    while(fread(&stud, sz, 1, fp))
    {

        if( strcmp(student_un,stud.sun) ==0  && strcmp(student_pw, stud.spw)==0)
        {
            f=1;
        }

    }

    fclose(fp);

    if(f==1)
    {

        printf("\n\t\t\t\t\tWelcome %s\n",stud.na);
        printf("\n\n\t\t\t\t\tYour class test mark is %s\n", stud.marks);
    }
    else
    {
        printf("\n\t\t\t\t\tError\n");
        student_login();
    }



}


void admin_options()
{
    int ch;
    system("cls");
    printf("\n\n\n\t\t\t\t\t<== Choose your option ==>\n");
    printf("\n\t\t\t\t\t1.Teacher Options\n");
    printf("\n\t\t\t\t\t2.Student Options\n");
    printf("\n\t\t\t\t\t0.<< Back to login menu.\n");
    printf("\n\t\t\t\t\tEnter your choice: ");
    scanf("%d", &ch);
    switch(ch)
    {
    case 0:
        login_menu();
        break;
    case 1:
        teacher_options();
        break;
    case 2:
        student_options();
        break;
    }
}

void teacher_options()
{
    int ch;
    system("cls");
    printf("\n\n\n\t\t\t\t\t<== Choose teacher option ==>\n");
    printf("\n\t\t\t\t\t1.Teachers Info\n");
    printf("\n\t\t\t\t\t2.Add Teacher\n");
    printf("\n\t\t\t\t\t3.Update Teacher Info\n");
    printf("\n\t\t\t\t\t4.Add or Update Course\n");
    printf("\n\t\t\t\t\t5.Delete Teacher Record\n");
    printf("\n\t\t\t\t\t0.<< Back to admin options.\n");
    printf("\n\t\t\t\t\tEnter your choice: ");
    scanf("%d", &ch);
    switch(ch)
    {
    case 0:

        admin_options();

        break;
    case 1:
        teacher_info();
        break;
    case 2:
        teacher_add();
        break;

    case 3:
        teacher_update();
        break;
    case 4:
        teacher_add_course();
        break;

    case 5:
        teacher_del();
        break;

    default:
        printf("\n\t\t\t\t\tInvalid choice..\n");
    }

}

void teacher_add()
{
    system("cls");
    FILE *fp;
    long sz = sizeof(tcr);
    fp = fopen("teachers.txt","ab");
    printf("\n\n\n\t\t\t\t\t<== Create teacher account ==>\n");

    printf("\n\t\t\t\t\t<== Teacher Login Info ==>\n");
    printf("\n\t\t\t\t\tEnter teacher username: ");
    fflush(stdin);
    gets(tcr.tun);
    printf("\n\t\t\t\t\tEnter teacher password: ");
    fflush(stdin);
    gets(tcr.tpw);
    printf("\n\n\n\t\t\t\t\t<== Create Personal Info ==>\n");
    printf("\n\t\t\t\t\tEnter teacher name: ");
    fflush(stdin);
    gets(tcr.na);
    printf("\n\t\t\t\t\tEnter teacher id: ");
    scanf("%d", &tcr.id);
    printf("\n\t\t\t\t\tEnter teacher designation: ");
    fflush(stdin);
    gets(tcr.dn);
    strcpy(tcr.cur,"");
    fwrite(&tcr, sz, 1, fp);
    printf("\n\t\t\t\t\tRecord saved successfully....\n");
    fclose(fp);
    printf("\n\t\t\t\t\t1. Add More Teacher\n");
    printf("\n\t\t\t\t\t0. <<Return to teachers options\n");
    int ch;
    printf("\n\t\t\t\t\tEnter your choice: ");
    scanf("%d", &ch);
    switch(ch)
    {
    case 0:
        teacher_options();
        break;
    case 1:
        teacher_add();
        break;
    default:
        printf("\n\t\t\t\t\tInvalid Choice...\n");

    }
}

void teacher_info()
{
    system("CLS");
    FILE *fp;
    long sz = sizeof(tcr);
    printf("\n\n\n\t\t\t\t\t<== Teacher Info ==>\n\n");
    printf("\t%-20s %-15s %-20s %-10s %-15s %s\n","Name","Course","Designation", "ID","Username", "Password");
    fp = fopen("teachers.txt","rb");
    while(fread(&tcr, sz, 1, fp) == 1)
    {
        printf("\t%-20s %-15s %-20s %-10d %-15s %s\n",tcr.na,tcr.cur,tcr.dn,tcr.id,tcr.tun, tcr.tpw);
    }
    fclose(fp);
    printf("\n\t\t\t\t\t1. Add More Teacher\n");
    printf("\n\t\t\t\t\t0. <<Return to teachers options\n");
    int ch;
    printf("\n\t\t\t\t\tEnter your choice: ");
    scanf("%d", &ch);
    switch(ch)
    {
    case 0:
        teacher_options();
        break;
    case 1:
        teacher_add();
        break;
    default:
        printf("\n\t\t\t\t\tInvalid Choice...\n");
    }
}

void teacher_update()
{
    int id, f=0;
    system("cls");
    FILE *fp;
    long sz = sizeof(tcr);
    printf("\n\n\n\t\t\t\t\tEnter id to update: ");
    scanf("%d", &id);
    fp = fopen("teachers.txt","rb+");
    while(fread(&tcr,sz, 1, fp)==1)
    {
        if(id == tcr.id)
        {
            f=1;
            printf("\n\t\t\t\t\t<== Fill Up this information ==>\n");
            printf("\n\t\t\t\t\tEnter teacher new name: ");
            fflush(stdin);
            gets(tcr.na);

            printf("\n\t\t\t\t\tEnter teacher new id: ");
            scanf("%d", &tcr.id);

            printf("\n\t\t\t\t\tEnter teacher new designation: ");
            fflush(stdin);
            gets(tcr.dn);
            fseek(fp, -sz, 1);

            fwrite(&tcr, sz, 1, fp);
            fclose(fp);
            break;
        }
    }

    if (f == 0)
    {
        printf("\n\t\t\t\t\tRecord not found\n");
        printf("\n\t\t\t\t\tPress any key to retry....\n");
        getch();
        teacher_update();
    }
    else
    {
        printf("\n\t\t\t\t\tRecord Updated successfully.\n");
        printf("\n\t\t\t\t\t1. Update another\n");
        printf("\n\t\t\t\t\t0. <<Return to teacher options\n");
        int ch;
        printf("\n\t\t\t\t\tEnter your choice: ");
        scanf("%d", &ch);
        switch(ch)
        {
        case 0:
            teacher_options();
            break;
        case 1:
            teacher_update();
            break;
        default:
            printf("\n\t\t\t\t\tInvalid Choice...\n");

        }
    }
}


void teacher_add_course()
{
    int id, f=0;
    system("cls");
    printf("\n\t\t\t\t\tEnter teacher id: ");
    scanf("%d", &id);
    FILE *fp;

    long sz = sizeof(tcr);
    fp = fopen("teachers.txt","rb+");
    while(fread(&tcr,sz, 1, fp)==1)
    {
        if(id == tcr.id)
        {
            f=1;
            printf("\n\n\t\t\t\t\t<== Update Course Information ==>\n");

            printf("\n\t\t\t\t\tEnter teacher course name: ");
            fflush(stdin);
            gets(tcr.cur);
            fseek(fp, -sz, 1);

            fwrite(&tcr, sz, 1, fp);
            fclose(fp);
            //break;
        }
    }

    if(f==0)
    {

        printf("\n\t\t\t\t\tTeacher id is not match\n");

    }
    else
    {
        printf("\n\t\t\t\t\tUpdated successfully.....\n");

    }


    printf("\n\t\t\t\t\t1. Add Another Course\n");
    printf("\n\t\t\t\t\t0. <<Return to teacher options\n");
    printf("\n\t\t\t\t\tEnter your choice: ");
    int ch;
    scanf("%d", &ch);
    switch(ch)
    {
    case 0:
        teacher_options();
        break;
    case 1:
        teacher_add_course();
        break;
    default:
        printf("\n\t\t\t\t\tInvalid Choice...\n");

    }



}



void teacher_del()
{

    int id, f=0;
    long sz = sizeof(tcr);
    system("cls");
    printf("\n\n\n\t\t\t\t\tEnter id to delete: ");
    scanf("%d", &id);
    FILE *fp;
    FILE *ft;
    fp = fopen("teachers.txt","rb");
    ft = fopen("temp.txt","ab");

    while(fread(&tcr, sz, 1, fp)==1)
    {
        if(id == tcr.id)
        {
            f=1;
        }
        else
        {
            fwrite(&tcr,sz, 1, ft);
        }
    }
    fclose(fp);
    fclose(ft);
    remove("teachers.txt");
    rename("temp.txt", "teachers.txt");
    if(f==0)
    {
        printf("\n\t\t\t\t\tRecord Not Found.\n");
    }
    else
    {
        printf("\n\t\t\t\t\tRecord deleted successfully\n");

    }
    printf("\n\t\t\t\t\t1. Delete another\n");
    printf("\n\t\t\t\t\t0. <<Return to teacher options\n");
    int ch;
    printf("\n\t\t\t\t\tEnter your choice: ");
    scanf("%d", &ch);
    switch(ch)
    {
    case 0:
        teacher_options();
        break;
    case 1:
        teacher_del();
        break;
    default:
        printf("\n\t\t\t\t\tInvalid Choice...\n");

    }

}


void student_options()
{
    int ch;
    system("cls");
    printf("\n\n\n\t\t\t\t\t<== Choose Student option ==>\n");
    printf("\n\t\t\t\t\t1.Students Info\n");
    printf("\n\t\t\t\t\t2.Add Student\n");
    printf("\n\t\t\t\t\t3.Update Student\n");
    printf("\n\t\t\t\t\t4.Delete Student\n");
    printf("\n\t\t\t\t\t0.<< Back to admin options.\n");
    printf("\n\t\t\t\t\tEnter your choice: ");
    scanf("%d", &ch);
    switch(ch)
    {
    case 0:

        admin_options();

        break;
    case 1:
        student_info();
        break;
    case 2:
        student_add();
        break;
    case 3:
        student_update();
        break;
    case 4:
        student_del();
        break;
    default:
        printf("\n\t\t\t\t\tInvalid choice\n");
    }

}

void student_add()
{
    system("cls");
    FILE *fp;
    long sz = sizeof(stud);
    fp = fopen("students.txt","ab");
    printf("\n\n\n\t\t\t\t\t<== Fill Up this information ==>\n");
    printf("\n\t\t\t\t\t<== Create student account ==>\n");

    printf("\n\t\t\t\t\tEnter student username: ");
    fflush(stdin);
    gets(stud.sun);

    printf("\n\t\t\t\t\tEnter student password: ");
    fflush(stdin);
    gets(stud.spw);

    printf("\n\n\t\t\t\t\t<== Student Personal Info ==>\n");

    printf("\n\t\t\t\t\tEnter student name: ");
    fflush(stdin);
    gets(stud.na);

    printf("\n\t\t\t\t\tEnter class name: ");
    fflush(stdin);
    gets(stud.cl);

    printf("\n\t\t\t\t\tEnter student id: ");
    scanf("%d", &stud.id);

    strcpy(stud.marks, " ");
    fwrite(&stud, sz, 1, fp);
    printf("\n\t\t\t\t\tRecord saved successfully....\n");
    fclose(fp);

    printf("\n\t\t\t\t\t1. Add More Student\n");
    printf("\n\t\t\t\t\t0. <<Return to student options\n");
    int ch;
    printf("\n\t\t\t\t\tEnter your choice: ");
    scanf("%d", &ch);
    switch(ch)
    {
    case 0:
        student_options();
        break;
    case 1:
        student_add();
        break;
    default:
        printf("\n\t\t\t\t\tInvalid Choice...\n");

    }



}

void student_info()
{
    system("CLS");
    FILE *fp;
    long sz = sizeof(stud);
    printf("\n\n\n\t\t\t\t\t<== Student Info ==>\n\n");
    printf("\t%-30s %-20s %-15s %-10s %-20s %s \n","Name","Class","ID","Marks","Username","Password");
    fp = fopen("students.txt","rb");
    while(fread(&stud, sz, 1, fp) == 1)
    {

        printf("\t%-30s %-20s %-15d %-10s %-20s %s \n",stud.na, stud.cl, stud.id, stud.marks, stud.sun, stud.spw);

    }
    fclose(fp);

    printf("\n\t\t\t\t\t1. Add More Student\n");
    printf("\n\t\t\t\t\t0. <<Return to students options\n");
    int ch;
    printf("\n\t\t\t\t\tEnter your choice: ");
    scanf("%d", &ch);
    switch(ch)
    {
    case 0:
        student_options();
        break;
    case 1:
        student_add();
        break;
    default:
        printf("\n\t\t\t\t\tInvalid Choice...\n");

    }

}

void student_update()
{
    int id, f=0;
    system("cls");
    FILE *fp;
    long sz = sizeof(stud);
    printf("\n\n\n\t\t\t\t\tEnter id to update: ");
    scanf("%d", &id);
    fp = fopen("students.txt","rb+");
    while(fread(&stud,sz, 1, fp)==1)
    {
        if(id == stud.id)
        {
            f=1;
            printf("\n\n\n\t\t\t\t\t<== Fill Up this information ==>\n");
            printf("\n\t\t\t\t\tEnter student name: ");
            fflush(stdin);
            gets(stud.na);

            printf("\n\t\t\t\t\tEnter class name: ");
            fflush(stdin);
            gets(stud.cl);

            printf("\n\t\t\t\t\tEnter student id: ");
            scanf("%d", &stud.id);

           /* printf("\n\t\t\t\t\tEnter student marks: ");

            scanf("%d", &stud.marks);*/

            fseek(fp, -sz, 1);

            fwrite(&stud, sz, 1, fp);
            fclose(fp);
            break;
        }
    }

    if (f == 0)
    {
        printf("\n\t\t\t\t\tRecord not found\n");
        getch();
        student_update();
    }
    else
    {
        printf("\n\t\t\t\t\tRecord Updated successfully.\n");
        printf("\n\t\t\t\t\t1. Update another\n");
        printf("\n\t\t\t\t\t0. <<Return to student options\n");
        int ch;
        printf("\n\t\t\t\t\tEnter your choice: ");
        scanf("%d", &ch);
        switch(ch)
        {
        case 0:
            student_options();
            break;
        case 1:
            student_update();
            break;
        default:
            printf("\n\t\t\t\t\tInvalid Choice...\n");

        }
    }
}

void student_del()
{

    int id, f=0;
    long sz = sizeof(stud);
    system("cls");
    printf("\n\n\n\t\t\t\t\tEnter id to delete: ");
    scanf("%d", &id);
    FILE *fp;
    FILE *ft;
    fp = fopen("students.txt","rb");
    ft = fopen("temp.txt","ab");

    while(fread(&stud, sz, 1, fp)==1)
    {
        if(id == stud.id)
        {
            f=1;
        }
        else
        {
            fwrite(&stud,sz, 1, ft);
        }
    }
    fclose(fp);
    fclose(ft);
    remove("students.txt");
    rename("temp.txt", "students.txt");
    if(f==0)
    {
        printf("\n\t\t\t\t\tRecord Not Found.\n");
    }
    else
    {
        printf("\n\t\t\t\t\tRecord deleted successfully\n");

    }
    printf("\n\t\t\t\t\t1. Delete another\n");
    printf("\n\t\t\t\t\t0. <<Return to student options\n");
    int ch;
    printf("\n\t\t\t\t\tEnter your choice: ");
    scanf("%d", &ch);
    switch(ch)
    {
    case 0:
        student_options();
        break;
    case 1:
        student_del();
        break;
    default:
        printf("\n\t\t\t\t\tInvalid Choice...\n");

    }

}


//Teacher Options

void teacher_menu()
{
    system("cls");
    int ch;
    printf("\n\n\n\t\t\t\t\t<== Teacher Menu ==>\n");
    printf("\n\t\t\t\t\t1.Student Info\n");
    printf("\n\t\t\t\t\t2.Add/Update Student Marks\n");
    printf("\n\t\t\t\t\t3.Search Student By ID\n");
    printf("\n\t\t\t\t\t4.Search Student By Name\n");
    printf("\n\t\t\t\t\t5.Count Total Student\n");
    printf("\n\t\t\t\t\t0.<<Back To Login Menu\n");
    printf("\n\t\t\t\t\tEnter your choice: ");
    scanf("%d",&ch);
    switch(ch)
    {
    case 0:
        login_menu();
        break;
    case 1:
        student_info_display();
    case 2:
        teacher_give_mark();
        break;
    case 3:
        search_by_id();
        break;
    case 4:
        search_by_name();
        break;
    case 5:
        total_student();
        break;
    default:


        printf("\n\t\t\t\t\tInvalid choice\n");


    }




}

void student_info_display(){
  system("CLS");
    FILE *fp;
    long sz = sizeof(stud);
    printf("\n\n\n\t\t\t\t\t<== Student Info ==>\n");
    printf("\n\t\t%-30s %-20s %-15s  %s \n","Name","Class","ID","Marks");
    fp = fopen("students.txt","rb");
    while(fread(&stud, sz, 1, fp) == 1)
    {

        printf("\t\t%-30s %-20s %-15d  %s \n",stud.na, stud.cl, stud.id, stud.marks);

    }
    fclose(fp);

    printf("\n\t\t\t\t\t1. Add Student marks\n");
    printf("\n\t\t\t\t\t0. <<Return to teacher menu\n");
    int ch;
    printf("\n\t\t\t\t\tEnter your choice: ");
    scanf("%d", &ch);
    switch(ch)
    {
    case 0:
        teacher_menu();
        break;
    case 1:
        teacher_give_mark();
        break;
    default:
        printf("\n\t\t\t\t\tInvalid Choice...\n");

    }

}
void teacher_give_mark()
{

    int id, f=0;
    system("cls");
    printf("\n\n\n\t\t\t\t\tEnter student id: ");
    scanf("%d", &id);
    FILE *fp;

    long sz = sizeof(stud);
    fp = fopen("students.txt","rb+");
    while(fread(&stud,sz, 1, fp)==1)
    {
        if(id == stud.id)
        {
            f=1;
            printf("\n\n\n\t\t\t\t\t<== Update Mark Information ==>\n");

            printf("\n\t\t\t\t\tEnter student marks: ");
            fflush(stdin);
            gets(stud.marks);
            fseek(fp, -sz, 1);

            fwrite(&stud, sz, 1, fp);
            fclose(fp);
            break;
        }
    }

    if(f==0)
    {

        printf("\n\t\t\t\t\tNot Updated\n");

    }
    else
    {
        printf("\n\t\t\t\t\tUpdate.....\n");

    }


    printf("\n\t\t\t\t\t1. Add Another Marks\n");
    printf("\n\t\t\t\t\t0. <<Return to Teacher Menu\n");
    int ch;
    printf("\n\t\t\t\t\tEnter your choice: ");
    scanf("%d", &ch);
    switch(ch)
    {
    case 0:
        teacher_menu();
        break;
    case 1:
         teacher_give_mark();
        break;
    default:
        printf("\n\t\t\t\t\tInvalid Choice...\n");

    }




}

void search_by_id(){
    int id, f=0;
    system("cls");
    printf("\n\n\n\t\t\t\t\tEnter id to search: ");
    scanf("%d",&id);
    FILE *fp;
    long sz = sizeof(stud);
    fp = fopen("students.txt","rb");
     printf("\n\t\t%-30s %-20s %-15s %s \n","Name","Class","ID","Marks");
    while(fread(&stud, sz,1,fp)==1){
        if(id == stud.id){
                f =1;
                printf("\t\t%-30s %-20s %-15d  %s \n",stud.na, stud.cl, stud.id, stud.marks);
                break;
        }

    }
    fclose(fp);
    if(f==0){
        printf("\n\t\t\t\t\tRecord Not Found.\n");
    }else {
     printf("\n\t\t\t\t\tRecord Found.\n");
    }

     printf("\n\t\t\t\t\t1.Search another id\n");
    printf("\n\t\t\t\t\t0. <<Return to Teacher Menu\n");
    int ch;
    printf("\n\t\t\t\t\tEnter your choice: ");
    scanf("%d", &ch);
    switch(ch)
    {
    case 0:
        teacher_menu();
        break;
    case 1:
         search_by_id();
        break;
    default:
        printf("\n\t\t\t\t\tInvalid Choice...\n");

    }

}

void search_by_name(){
    char na[20];
    int f=0;
    system("cls");
    printf("\n\n\n\t\t\t\t\tEnter name to search: ");
    fflush(stdin);
    gets(na);
    FILE *fp;
    long sz = sizeof(stud);
    fp = fopen("students.txt","rb");
     printf("\n\t\t%-30s %-20s %-15s %s \n","Name","Class","ID","Marks");
    while(fread(&stud, sz,1,fp)==1){
        if(strcmpi(na, stud.na)==0){
                f =1;
                printf("\t\t%-30s %-20s %-15d  %s \n",stud.na, stud.cl, stud.id, stud.marks);
                break;
        }

    }
    fclose(fp);
    if(f==0){
        printf("\n\t\t\t\t\tRecord Not Found.\n");
    }else {
     printf("\n\t\t\t\t\tRecord Found.\n");
    }

     printf("\n\t\t\t\t\t1.Search another Name\n");
    printf("\n\t\t\t\t\t0. <<Return to Teacher Menu\n");
    int ch;
    printf("\n\t\t\t\t\tEnter your choice: ");
    scanf("%d", &ch);
    switch(ch)
    {
    case 0:
        teacher_menu();
        break;
    case 1:
         search_by_name();
        break;
    default:
        printf("\n\t\t\t\t\tInvalid Choice...\n");

    }

}
void total_student(){

    system("cls");
    int num = 0;
    FILE *fp;
    long sz = sizeof(stud);
    fp = fopen("students.txt","rb");
    while(fread(&stud, sz,1,fp)==1){
       num = num + 1;
    }
    fclose(fp);


     printf("\n\n\n\t\t\t\t\tTotal student is %d",num);
    printf("\n\n\n\t\t\t\t\t0. <<Return to Teacher Menu\n");
    int ch;
    printf("\n\t\t\t\t\tEnter your choice: ");
    scanf("%d", &ch);
    switch(ch)
    {
    case 0:
        teacher_menu();
        break;
    default:
        printf("\n\t\t\t\t\tInvalid Choice...\n");

    }
}
















