#include <stdio.h>
#include <stdlib.h>
void main(){
    int arr[]={1,9,5,3,2,0};int j;
    for(int i=1;i<6;i++){
        int key=arr[i];
        for(j=i-1;j>=0 && key<arr[j];j--){
            arr[j+1]=arr[j];
        }arr[j+1]=key;
    }
    for(int i=0;i<6;i++){
        printf("%d",arr[i]);
    }
}