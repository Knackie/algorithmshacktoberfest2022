#include<stdio.h>

int main(){
    int arr[7] = {2,4,7,1,3,6,5};
    int len = sizeof arr / sizeof arr[0];
    int min = arr[0];
    for(int i=1;i<len;i++){
        if(arr[i]<min){
            min = arr[i];
        }
    }
    printf("%d\n",min);
    return 0;
}