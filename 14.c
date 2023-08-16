#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void main(){
    FILE *f1,*f2,*f3,*fin1,*fin2,*fin3;
    char data1[20],data2[20];char ch1,ch2,ch3;
    f1=fopen("1.txt","w");
    f2=fopen("2.txt","w");
    if(f1==NULL || f2==NULL){
        puts("COuld not open file 1");
        exit(0);
    }
    printf("enter data for file 1");
    gets(data1);
    printf("enter data for file 2");
    gets(data2);
    fprintf(f1,"%s",data1);
    fprintf(f2,"%s",data2);
    fclose(f1);
    fclose(f2);
    fin1=fopen("1.txt","r");
    fin2=fopen("2.txt","r");
    f3=fopen("3.txt","w");
    if(fin1==NULL || fin2==NULL || f3==NULL){
        puts("COuld not open file 2");
        exit(0);
    }
    ch1=fgetc(fin1);
    ch2=fgetc(fin2);
    while(ch2!=EOF){
        if(ch1!=ch2){
            fputc(ch2,f3);
        }
        ch1=fgetc(fin1);
    ch2=fgetc(fin2);
    }
    fclose(fin1);
    fclose(fin2);
    fclose(f3);
    fin3=fopen("3.txt","r");
    if(fin3==NULL){
        puts("COuld not open file 3");
        exit(0);
    }
    ch3=fgetc(fin3);
    if(ch3==EOF){
        puts("NO diff");
        exit(0);
    }
    while(ch3!=EOF){
        printf("%c",ch3);
        ch3=getc(fin3);
    }
    fclose(fin3);
}