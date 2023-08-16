#include <stdio.h>
void main(){
    int arr[]={12,23,44,55,76,89},arr1[100];
    for(int i=0;i<=9;i++){
        arr1[i]=-1;
    }
    for(int i=0;i<6;i++){
        int result=arr[i]%10;
        arr1[result]=arr[i];
        printf("Location a1[%d] and value %d\n",result,arr1[result]);
    }
    printf("hash table:");
    for(int i=0;i<6;i++){
        printf("%d ",arr[i]);
    }
}