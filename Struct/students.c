#include<stdio.h>
#include<stdlib.h>
#include<string.h>


struct Student
{
    char name[20];
    int marks;
    char grade;
} student[50];

int n = 0;

void getdetails(char sname[])
{
    printf("\n");
    int i,found=0;

    if(n==0)
    {
        printf("\nNo Student is added!\n");
    }
    else
    {
        for(i=0;i<n;i++)
        {
            if(!strcmp(sname, student[i].name))
            {
                printf("Name : %s\n",student[i].name);
                printf("Marks : %d\n",student[i].marks);
                printf("Grade : %c\n\n",student[i].grade);
                found = 1;
            }
        }

        if(found==0)
        {
            printf("\nNo student with that name found\n");
        }
    }
    
}

void getstudents()
{
    printf("\n");
    int i;

    if(n==0)
    {
        printf("\nNo Students are added to show!\n");
    }
    else
    {
        for(i=0;i<n;i++)
        {
            printf("Name : %s\n",student[i].name);
            printf("Marks : %d\n",student[i].marks);
            printf("Grade : %c\n\n",student[i].grade);
        }
    }
}

void addstudent()
{
    printf("Enter Student Name : ");
    scanf("%s",student[n].name);
    printf("\n");
    printf("Enter marks of student : ");
    scanf("%d",&student[n].marks);
    printf("\n");
    printf("Enter grade : ");
    scanf("%s",&student[n].grade);
    printf("\nStudent Added Successfully\n\n");

    n++;
}

void topper()
{
    int i,max=student[0].marks,index;

    if(n==0)
    {
        printf("\nIf there are no students, how can we decide the topper?\n");
    }
    else
    {
        for(i=0;i<n;i++)
        {
            if(max<student[i].marks)
            {
                max = student[i].marks;
                index = i;
            }
        }

        printf("\nTopper : %s\n",student[index].name);
    }
    


}

int main()
{
    char sname[50];
    int choice;
    char quit='a';

    while(quit!='q')
    {
        printf("[+] 1. Add Student Details\n");
        printf("[+] 2. View All Student Details\n");
        printf("[+] 3. Search Student Details\n");
        printf("[+] 4. Name of the topper\n");
        printf("Enter your choice : ");
        scanf("%d",&choice);
        printf("\n\n");

        switch(choice)
        {
            case 1: addstudent();
                    break;

            case 2: getstudents();
                    break;

            case 3: printf("Enter the Student Name to find : ");
                    scanf("%s",sname);
                    getdetails(sname);
                    break;

            case 4: topper();
                    break;
            
            default:printf("\nThat's rude!!\n");
                    break;
        }

        printf("\nHit any key to continue or press 'q' to quit\n");
        quit = getch();
        
    }



    return 0;
}
