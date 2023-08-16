#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *left;
    struct node *right;
};
typedef struct node*NODE;
NODE getnode(){
    NODE temp=malloc(sizeof(struct node));
    temp->left=temp->right=NULL;
    return temp;
}
NODE create(NODE root){
    root=getnode();int d;
    printf("enter data:");
    scanf("%d",&root->data);
    printf("\n%d is succesfully inserted",root->data);
    printf("\nenter 1 to insert at left of %d else 0:",root->data);
    scanf("%d",&d);
    if(d==1){
        root->left=create(root->left);
    }else{
        root->left=NULL;
    }
    printf("\nenter 1 to insert at right of %d else 0:",root->data);
    scanf("%d",&d);
    if(d==1){
        root->right=create(root->right);
    }else{
        root->right=NULL;
    }

}
void preorder(NODE root){
    if(root!=NULL){
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void inorder(NODE root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}
void postorder(NODE root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}
void main(){
    NODE root=NULL;
    printf("tree traversal");
    root=create(root);
    printf("preorder traversal\n");
    preorder(root);
    printf("\ninorder traversal\n");
    inorder(root);
    printf("\npostorder\n");
    postorder(root);
}
