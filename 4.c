#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *link;
};
typedef struct node*NODE;
NODE front=NULL,rear=NULL;
NODE getnode(){
    struct node *temp;
    temp=malloc(sizeof(struct node));
    temp->link=NULL;
    return temp;
}
void enq(int s){
    printf("enter data:");
    int d;
    scanf("%d",&d);
    NODE temp=getnode();
    temp->data=d;
    if(front==NULL){
        front=rear=temp;
    }
    else if(s==1){
        temp->link=front;
        front=temp;
    }
    else{
        rear->link=temp;
        rear=temp;
    }
}
void deq(int j){
    if(front==NULL || rear==NULL){
        printf("empty\n");
        return;
    }
    else if(j==1){
        NODE temp=front;
        while(temp->link!=rear){
            temp=temp->link;
        }
        int x=rear->data;temp->link=NULL;
        free(rear);
        printf("deleted element is %d",x);
        rear=temp;
    }
    else{
        NODE temp=front;
        int x=temp->data;
        front=front->link;
        free(temp);
        printf("deleted element is %d\n",x);
    }
}
void display(){
    for(NODE i=front;i!=NULL;i=i->link){
        printf("%d ",i->data);
    }
}
void main(){
    int s;
    while(1){
        printf("1.ENTRY RESTRICTED OP\n 2.EXIT RESTRICTED OPERATION \n 3.DISPLAY \n 4.EXIT\n");
        scanf("%d",&s);
        switch(s){
            case 1:printf("\nEntry restricted operation:");
                    printf("1.insert\n 2.delete from rear\n 3. delete from front\n");
                    scanf("%d",&s);
                    switch(s){
                        case 1:enq(0);break;
                        case 2:deq(1);break;
                        case 3:deq(0);break;
                        default:printf("wrong choice");break;
                    }break;
            case 2:printf("\nExit restricted operation:");
                    printf("1.insert from rear\n 2. insert from front\n 3.delete");
                    scanf("%d",&s);
                    switch(s){
                        case 1:enq(0);break;
                        case 2:enq(1);break;
                        case 3:deq(0);break;
                        default:printf("wrong choice");break;
                    }break;
            case 3:display();break;
            case 4:exit(0);
            default:printf("wrong choice");break;
        }
    }
}