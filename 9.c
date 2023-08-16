#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
struct node{
    int data;
    struct node *left;
    struct node *right;
};
typedef struct node*NODE;
NODE create_tree(char postfix[]){
    char symbol;NODE temp,stack[20];int j=-1;
    for(int i=0;(symbol=postfix[i])!=0;i++){
        temp=malloc(sizeof(struct node));
        temp->right=temp->left=NULL;temp->data=symbol;
        if(isalnum(symbol)){
            stack[++j]=temp;
        }
        else{
            temp->right=stack[j--];
            temp->left=stack[j];
            stack[j]=temp;
        }
    }return stack[j];

}
float eval(NODE root){
    float num;
    switch(root->data){
        case '+':return eval(root->left)+eval(root->right);break;
        case '-':return eval(root->left)-eval(root->right);break;
        case '*':return eval(root->left)*eval(root->right);break;
        case '/':return eval(root->left)/eval(root->right);break;
        case '^':return pow(eval(root->left),eval(root->right));
        default:if(isalpha(root->data)){
            printf("\n enter the value of %c",root->data);
            scanf("%f",&num);return num;
        
        }else{
            return root->data-'0';
        }
    }
}
int main()

{NODE root=NULL;   char postfix[20];float result;
    printf("enter the postfix expression");
    scanf("%s",postfix);
    root=create_tree(postfix);
    result=eval(root);
    printf("%.3f",result);
}