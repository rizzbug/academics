#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    int RT;
    struct node *left;
    struct node *right;
};

typedef struct node*NODE;
void inorder(NODE);
NODE head=0;
NODE inorder_successor(NODE);
NODE getnode(){
    NODE temp=malloc(sizeof(struct node));
    temp->left=0;temp->right=0;
    return temp;
}
void insert_left(NODE head,int item){ 
    NODE temp=getnode();
    temp->right=head;
    temp->data=item;temp->RT=1;
    head->left=temp;
}
void insert_right(NODE head,int item){
    NODE temp=getnode();
    temp->data=item;
    temp->right=head->right;
    head->right=temp;
    temp->RT=1;head->RT=0;

}
NODE create(NODE head,int item){
    NODE temp,ptr;
    if(head->left==0){
        insert_left(head,item);
        return head;
    }
    temp=head->left;
    while(temp!=head){
        if(item<(temp->data) && temp->left!=0){
            temp=temp->left;
        }
        else if(item>(temp->data)&& temp->RT==0){
            temp=temp->right;
        }
        else if(temp->data==item){
            printf("duplicates not allowed");
            return head;
        }
        else{
            break;
        }
    }
    if(item>(temp->data)){
        insert_right(temp,item);
        return head;
    }
    else{
        insert_left(temp,item);
        return head;
    }
}
void inorder(NODE head){
    if(head->left==0){
        printf("NO item");
        exit(0);
    }
    NODE temp=head;
    while(1){
        temp=inorder_successor(temp);
        if(temp==head){
            return;
        }
        printf("%d=>",temp->data);
    }
}
NODE inorder_successor(NODE ptr){
    NODE temp=ptr->right;
    if(ptr->RT==1){
        return temp;
    }
    while(temp->left!=0){
        temp=temp->left;
    }
    return temp;
}
void main()
{int ch;int n;int i;int item;
NODE head;
head=malloc(sizeof(struct node));
head->right=head;
head->left=0;
head->RT=0;
while(1)
{

 printf("\n1.Create tree\n2.Inorder\n3.Exit\n");
 printf("Enter the choice\n");
 scanf("%d",&ch);
 switch(ch)
 {
 case 1:printf("Enter num of nodes to create\n");
 scanf("%d",&n);
 for(i=1;i<n+1;i++)
 {

 printf("Enter %d data\n",i);
 scanf("%d",&item);
 head=create(head,item);
 }
 break;
 case 2:inorder(head);
 break;
 case 3:exit(0);
 default: printf("Wrong choice\n");
 break;
 }
 }
}