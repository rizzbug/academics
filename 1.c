#include <stdio.h>
#include <stdlib.h>
#define Size 4
int stack[Size];int top=-1;
void push(){
    if(top==(Size-1)){
        printf("Stack full\n");
        return;
    }
    printf("enter the data");
    int d;
    scanf("%d",&stack[++top]);
}
int pop(){
    if(top==-1){
        printf("stack empty\n");
        return -1;
    }
    top--;
    return stack[top+1];
}
void display(){
    for(int i=0;i<=top;i++){
        printf("%d ",stack[i]);
    }
}
void main(){
    int s;
    while(1){
        printf("enter 1 to push\n2 to pop\n3 to display");
        scanf("%d",&s);
        switch(s){
            case 1:push();break;
            case 2:printf("deleted element is %d\n",pop());break;
            case 3:display();
        }
    }
}