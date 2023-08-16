#include <stdio.h>
#include <stdlib.h>
struct node{
    struct node *prev;
    struct node *next;
    int data;
};
typedef struct node*NODE;
NODE head=NULL;
NODE getnode(){
    NODE temp=malloc(sizeof(struct node));
    temp->prev=NULL;
    temp->next=NULL;
    return temp;
}
void insert_at_last(NODE temp){
    NODE itr=head;
        while(itr->next!=NULL){
            itr=itr->next;
        }
        itr->next=temp;
        temp->prev=itr;
}
void insert(int k){
    int d;printf("enter data:");scanf("%d",&d);
    NODE temp=getnode();temp->data=d;
    if(head==NULL){
        head=temp;
        return;
    }
    if(k==1){
        insert_at_last(temp);
    }
    else{
        int pos;printf("\nenter position:");
        scanf("%d",&pos);
        if(pos==1){
            temp->next=head;
            head->prev=temp;
            head=temp;
            return;
        }
        NODE itr=head;
        while(pos>1 && itr!=NULL){
            itr=itr->next;
            pos--;
        }
        if(itr==NULL){
            insert_at_last(temp);return;
        }
        itr->prev->next=temp;
        temp->prev=itr->prev;
        temp->next=itr;
        itr->prev=temp;
    }
}
void delete(){
    int d;printf("enter position:");
    scanf("%d",&d);
    NODE temp=head;
    if(d==1){
        head=head->next;
        head->prev=NULL;printf("%d is succesfully deleted",temp->data);
        free(temp);return;
    }
    while(d>1){
        temp=temp->next;
        d--;
        if(temp==NULL){
        printf("invalid pos");return;
    }
    }
    if(temp->next==NULL){
        temp->prev->next=NULL;
    }
    else{temp->prev->next=temp->next;
    temp->next->prev=temp->prev;}
    
    printf("%d is succesfully deleted",temp->data);
    free(temp);
}
void display(){
    if(head==NULL){
        printf("empty");return;
    }
    NODE p=head;
    while(p!=NULL){
        printf("%d \t",p->data);
        p=p->next;
    }}
int main(){
    int option;
while(1)
{
 printf("\nDoubly linked list operations\n");
 printf("1.Insert\n2.Delete\n3.Display\n4.Exit\n");
 printf("Enter your choice: ");
 scanf("%d",&option);
 switch(option)
 {
 case 1:printf("enter 1 for inserting in rear\n2 for pos:");int d;scanf("%d",&d);
 insert(1);
 break;
 case 2:delete();
 break;
 case 3: display();
 break;
 case 4: exit(0);
 default: printf("Invalid choice\n");
 }
}
}

