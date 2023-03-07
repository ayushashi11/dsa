#include<stdlib.h>
#include<stdio.h>

int main(){
    int *arr= (int*)malloc(69*sizeof(int));
    arr[0]=0;
    printf("%d",*arr);
    return 0;
}