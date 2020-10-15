#include <stdio.h>

void printArray(int array[],int length){
    for(int i=0;i<length;i++){
        printf("%d ",array[i]);
    }
    printf("\n");
}

int max(int array[],int length){
    int max = array[0];
    for(int i=1;i<length;i++){
        max = array[i] > max ? array[i] : max;
    }
    return max;
}

void countingSort(int array[],int length,int pos){
    int max = (array[0]/pos)%10;
    int result[length+1];
    int i;
    
    for(i=0;i<length;i++){
        max = ((array[i]/pos)%10) > max ? (array[i]/pos)%10 : max;
    }
    int counter[max+1];
    for(i=0;i<=max;i++){
        counter[i] = 0;
    }

    for(i=0;i<length;i++){
        counter[((array[i]/pos)%10)]++;
    }

    for(i=1;i<=max;i++){
        counter[i]+=counter[i-1];
    }

    for(i=length-1;i>=0;i--){
        result[counter[((array[i]/pos)%10)]] = array[i];
        counter[((array[i]/pos)%10)]--;
    }
    for(i=0;i<length;i++){
        array[i] = result[i+1];
    }
}

void radix(int array[],int length){
    int maxVal = max(array,length);

    for(int i=1; maxVal/i > 0; i*=10){
        countingSort(array,length,i);
    }
}

int main(){
    int array[]={ 12,112,134,231,1000,112,1,4,3,112,293,120,220,219,2002 };
    int length = sizeof(array)/sizeof(array[0]);
    radix(array,length);
    printArray(array,length);
}