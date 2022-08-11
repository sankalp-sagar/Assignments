#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Student
{
    char name[20];
    int marks[3];
    char grade;
};

int main()
{
    int n,i;
    char sname[20];
    printf("Enter Number of Students : ");
    scanf("%d",&n);
    struct Student student[n];
    printf("\n");

    for(i=0;i<n;i++)
    {
        printf("Enter Student %d Name : ",i+1);
        scanf("%s",student[i].name);
        printf("\n");
        printf("Enter marks of three subjects : ");
        scanf("%d %d %d",&student[i].marks[0],&student[i].marks[1],&student[i].marks[2]);
        printf("\n");
        printf("Enter grade : ");
        scanf("%s",&student[i].grade);
        printf("\n");
    }

    printf("\n");

    printf("Enter Any Name to Find data : ");
    scanf("%s",sname);
    printf("\n");
    
    for(i=0;i<n;i++)
    {
        if(!strcmp(sname, student[i].name))
        {
            printf("Name : %s\n",student[i].name);
            printf("Marks : %d %d %d\n",student[i].marks[0],student[i].marks[1],student[i].marks[2]);
            printf("Grade : %c\n\n",student[i].grade);
        }
    }

    return 0;

}
