#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node{
    int reg;
    char name[20];
};
void main(){
    struct node stud[20];
    struct node temp[10]; 
    FILE *f,*fin;char s[20];
    f=fopen("student.txt","w");
    if(f==NULL){
        puts("Could not open files");
        exit(0);
    }
    int n;printf("no of student ");
    scanf("%d",&n);
    printf("enter the data of %d stud\n",n);
    for(int i=0;i<n;i++){
        printf("\nenter name of %d student:",i+1);
        scanf("%s",stud[i].name);
        // gets(stud[i].name);
        printf("\nenter reg of %d student:",i+1);
        scanf("%d",&stud[i].reg);
    }
fwrite(stud,sizeof(struct node),n,f);
fclose(f);
fin=fopen("student.txt","r");
if(fin==NULL){
        puts("Could not open files");
        exit(0);
    }
for(int i=0;i<n;i++){
        fread(&temp[i],sizeof(struct node),1,fin);
        printf("%d\n",temp[i].reg);
        puts(temp[i].name);printf("\n");
    }
fclose(fin);
}