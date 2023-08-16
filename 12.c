#include <stdio.h>
void main(){
    int arr[]={22,32,55,76,66,89,99,11,22,33},arr1[10];
    for(int i=0;i<=9;i++){
        arr1[i]=-1;
    }
    for(int i=0;i<10;i++){
        int k=arr[i]%10;
        if(arr1[k]==-1){
            arr1[k]=arr[i];
            printf("Location is arr1[%d] result is %d\n",k,arr1[k]);
        }
        else{
            int j=k+1;
            while(1){
                if(arr1[j]==-1 && j<=9){
                    arr1[j]=arr[i];
                    printf("Location is arr1[%d] result is %d\n",j,arr1[j]);
                    break;
                }
                else{
                    if(j<9){
                        j++;
                    }
                    else{
                        j=0;
                    }
                }
            }
        }
    }
    
}