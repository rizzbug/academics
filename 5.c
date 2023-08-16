#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *next;
};
typedef struct node *NODE;
NODE tail=NULL;
NODE getnode(){
    NODE temp=malloc(sizeof(struct node));
    temp->next=NULL;
    return temp;
}
void insert_front(){
    int d;
    printf("enter data:");
    scanf("%d",&d);
    NODE temp=malloc(sizeof(struct node));
    temp->data=d;
    if(tail==NULL){
        tail=temp;
        tail->next=tail;
        return;
    }
    temp->next=tail->next;
    tail->next=temp;
}
void insert_rear(){
    insert_front();
    tail=tail->next;
}
void del_front(){
    int t=tail->next->data;
    if(tail->next==tail){
        printf("%d is succesflly deleted",t);
        free(tail);
        tail=NULL;
        return;
    }
    NODE temp=tail->next;
    tail->next=tail->next->next;
    free(temp);
    printf("%d is succesflly deleted",t);
}
void del_last(){int t=tail->data;
    NODE temp=tail->next;
    if(temp==tail){
        tail=NULL;
        free(temp);
        printf("%d is succesflly deleted",t);return;
    }
    while(temp->next!=tail){
        temp=temp->next;
    }
    temp->next=temp->next->next;
    // printf("%d",tail->next);
    free(tail);tail=temp;
    printf("%d is succesflly deleted",t);
}
void display(){
    if(tail==NULL){
        printf("empty cir list");
        return;
    }
    NODE temp=tail->next;
    while(temp!=tail){
        printf("%d\t",temp->data);
        temp=temp->next;
    }printf("%d\t",temp->data);
}
int main(){
    int i;
    while(1){ printf("enter the operation you want to do:\n");
    printf("1.Insert to rear\n2.Insert to front\n3.Delete from front\n4.Delete from rear\n5.Display\n6.Exit\n");
        scanf("%d",&i);
    switch(i){
        case 1:
            insert_rear();break;
        case 2:insert_front();break;
        case 3:
            del_front();break;
        case 4:
            del_last();break;
        case 5:
            display();break;
        case 6:exit(0);
        default:break;
    }}
}