#include<stdio.h>
struct student{
    char name[30];
    int rollno;
    int mark;
};
void main()
{
    struct student students[3];
    int num,id;
    printf("Enter number of students:");
    scanf("%d",&num);
    for(int i=0;i<num;i++)
    {
        printf("Enter the details of student %d\n",i+1);
        printf("Enter the name of student :");
        scanf("%s", students[i].name);
        printf("Enter the rollno of student :");
        scanf("%d",&students[i].rollno);
        printf("Enter the total mark of student :");
        scanf("%d",&students[i].mark);
    }
    printf("Enter the rollno student to display details :");
    scanf("%d",&id);
     for(int i=0;i<num;i++)
    {
        if(id == i+1)
        {
            printf("Details of student %d\n",i+1);
            printf("Name of student :%s\n",students[i].name);
            printf("Rollno of student :%d\n",students[i].rollno);
            printf("Enter the total mark of student :%d\n",students[i].mark);
        }
    }
}