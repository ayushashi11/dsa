#include <stdio.h>
#include <stdlib.h>

void inline_merge_sort(int *array, int start, int end){
    int *left, *right;
    if(end-start<=1){
        return;
    }
    printf("%d %d ", start, end);
    int mid = (start+end)/2;
    left = (int *)malloc((mid-start)*sizeof(int));
    right = (int *)malloc((end-mid)*sizeof(int));
    for(int i=start; i<mid; i++){
        left[i] = array[i];
        printf("left %d\n",array[i]);
    }
    for(int i=mid;i<end; i++){
        right[i-mid] = array[i];
        printf("right %d\n",array[i]);
    }
    inline_merge_sort(left, start, mid);
    inline_merge_sort(right, 0, end-mid);
    int i=0,j=0,k=0,imax=mid,jmax=end-mid;
    while (i<imax && j<jmax)
    {
        if(left[i]<right[j]) array[k]=left[i++];
        else array[k]=right[j++];
        k++;
    }
    while(i<imax){
        array[k++]=left[i++];
    }
    while(j<jmax){
        array[k++]=right[j++];
    }
}

int main(){
    int arr[]={3,4,2,1,5}, len=5;
    inline_merge_sort(arr,0,len);
    for(int i=0;i<len;i++){
        printf("%d\t",arr[i]);
    }
    printf("\n");
    return 0;
}