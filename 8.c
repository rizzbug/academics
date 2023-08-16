//bst
#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *left;
    struct node *right;
};
typedef struct node *NODE;
NODE getnode(){
    NODE temp=malloc(sizeof(struct node));
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}
NODE insert(NODE root,int d){
    if(root==NULL){
        root=getnode();
        root->data=d;
        return root;
    }
    else if(root->data<d){
        root->right=insert(root->right,d);
    }
    else{
        root->left=insert(root->left,d);
    }
}
int min(NODE root){
    while(root->left!=NULL){
        root=root->left;
    }//
    return root->data;
}
NODE del(NODE root,int d){
    if(d<root->data){
        root->left=del(root->left,d);
    }
    else if(d>root->data){
        root->right=del(root->right,d);
    }
    else if(root->data==d){
        NODE temp;
        if(root->left==NULL){
            temp=root->right;free(root);return temp;//
        }
        else if(root->right==NULL){
            temp=root->left;free(root);return temp;//
        }
        else{
            int m=min(root->right);
            root->data=m;del(root->right,m);
            return root;
        }
    }
    else{
        printf("Not found");
        return root;
    }
}
int height(struct node* node)
{
    if (node == NULL)
        return 0;
    else {
        /* compute the height of each subtree */
        int lheight = height(node->left);
        int rheight = height(node->right);
        /* use the larger one */
        if (lheight > rheight)
            return (lheight + 1);
        else
            return (rheight + 1);
    }}
void printCurrentLevel(struct node* root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        printf("%d ", root->data);
    else if (level > 1) {
        printCurrentLevel(root->left, level - 1);
        printCurrentLevel(root->right, level - 1);
    }
}
void printLevelOrder(struct node* root)
{
    int h = height(root);
    int i;
    for (i = 1; i <= h; i++)
      {  printCurrentLevel(root, i);printf("\n");}
}
void inorder(NODE root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}
int main(){
    struct node *root=NULL;
    printf("enter the data for root node");
    int d;scanf("%d",&d);root=insert(root,d);
    while(1){
        printf("\nTree operations\n");
        printf("1.Insert\n2.Delete\n3.Display\n4.Exit\n");
        printf("Enter your choice: ");int option;
        scanf("%d",&option);
        switch(option){
            case 1:printf("\nenter data:");scanf("%d",&d);
                root=insert(root,d); break;
            case 2:scanf("%d",&d);root=del(root,d);break;
            case 3:inorder(root);break;
            case 4:exit(0);break;
            case 5:printLevelOrder(root);break;
        }
        }
}