#include <stdio.h>
#include <stdlib.h>
#define Size 4
int queue[Size];
int front=-1,rear=-1;
void insert(){
    if(rear==(Size-1)){
        printf("queue full\n");
        return;
    }
    int d;
    printf("enter data:");
    scanf("%d",&queue[++rear]);
}
int delete(){
    if(front==rear){
        printf("empty queue\n");
        return -1;
    }
    front++;
    if(front==rear){
        front=-1;
        rear=-1;
    }
    return queue[front];
}
void display(){
    for(int i=front+1;i<=rear;i++){
        printf("%d ",queue[i]);
    }
}
void main(){
    int s;
    while(1){
        printf("enter 1 to insert\n2 to delete\n3 to display\n");
        scanf("%d",&s);
        switch(s){
            case 1:insert();break;
            case 2:printf("deleted element is %d\n",delete());break;
            case 3:display();break;
            case 4:exit(0);
        }
    }
}