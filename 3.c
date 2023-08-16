#include <stdio.h>
#include <string.h>
char stack[100],infix[100],postfix[100];
int top=-1;int j=0;
void push(char x){
    stack[++top]=x;
}
char pop(){
    return stack[top--];
}
int precedence(char symbol){
    switch(symbol){
        case'^':return 4;
        case'*':case'/':return 3;
        case '+':case'-':return 2;
        default:return 0;
    }
}
void in_to_pos(){
    char temp,symbol;
    for(int i=0;i<strlen(infix);i++){
        symbol=infix[i];
        switch(symbol){
            case '(':
                push(symbol);break;
            case ')':temp=pop();while(temp!='('){
                        postfix[j++]=temp;
                        temp=pop();}break;
            case'^':
            case'*':case'/':
            case '+':case'-':
            while(top!=-1 && precedence(stack[top])>=precedence(symbol)){
                postfix[j++]=pop();
            }push(symbol);break;
            default:
                postfix[j++]=symbol;break;
        }
    }while(top!=-1){
        postfix[j++]=pop();
    }
}
void main(){
    printf("enter the infix exp:");
    gets(infix);
    strrev(infix);
    for(int i=0;i<strlen(infix);i++){
        if(infix[i]=='('){
            infix[i]=')';
        }
        else if(infix[i]==')'){
            infix[i]='(';
        }
    }
    in_to_pos();
    strrev(postfix);
    puts(postfix);
}