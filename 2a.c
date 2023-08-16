#include <stdio.h>
void toh(char src,char dest,char temp,int n){
    if(n==1){
        printf("%d disk moved from %c to %c\n",n,src,dest);
        return;
    }
    toh(src,temp,dest,n-1);
    printf("%d disk moved from %c to %c\n",n,src,dest);
    toh(temp,dest,src,n-1);
}
int main(){
    toh('s','d','t',3);
}