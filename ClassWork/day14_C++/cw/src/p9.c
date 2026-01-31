#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Employee
{
    int emp_id;
    int emp_sal;
    char emp_gen;
    char emp_name[50];
}EMP;


void disp(const EMP );

void tokenizeLine(char *, EMP *);

int main()
{
    FILE *fp=NULL;
    char line[100];
    
    EMP e;
    fp = fopen("./data/Employee.txt","r");

    if(fp == NULL)
    {
        printf("\nUnable to open the file\n");
        exit(EXIT_FAILURE);
    }

    
    memset(line,'\0',sizeof(line));
    fscanf(fp,"%[^\n]s",line);
    fprintf(stdout,"\n%s\n",line);
    
    fclose(fp);

    

    tokenizeLine(line,&e);

    disp(e);

    fp = fopen("./data/Employee.txt","w");

    if(fp == NULL)
    {
        printf("\nUnable to open the file\n");
        exit(EXIT_FAILURE);
    }    
    
    fprintf(fp,"%d,%s,%c,%d\n",e.emp_id,e.emp_name,e.emp_gen,(e.emp_sal*2));


    fclose(fp);

    printf("\n\n");

    return 0;
}


void tokenizeLine(char *line, EMP *e)
{
    char *token=NULL;
    //tokenizng the content of line to emp st
    token = strtok(line,"|");
    strcpy(e->emp_name, token);
    token = strtok(NULL, "|");
    e->emp_id = atoi(token);
    token = strtok(NULL,"|");
    e->emp_gen = token[0];
    token = strtok(NULL,"|");
    e->emp_sal = atoi(token);
}

void disp(const EMP e)
{
    printf("\n===========================\n");
    printf("\nEmployee Details are\n");
    printf("\nEmpID: %d",e.emp_id);
    printf("\nName: %s",e.emp_name);
    printf("\nGender: %c",e.emp_gen);
    printf("\nSalary: %d",e.emp_sal);
    printf("\n===========================\n");

}