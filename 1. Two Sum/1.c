/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#include <stdio.h>
#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    *returnSize = 2; //caller 在外面可以利用 returnSize 這個指標做額外利用

    int *array = (int*)malloc(2*sizeof(int));

    for (int i=0; i<numsSize; i++){
        for(int j=1+i; j<numsSize; j++){ 
        //不會有前面的 element 沒有檢查到的問題，因為前面已經檢查過了
        //ex. nums = [2,7,11,15,19], target = 22
        //檢查到 11 時，只會去看 15 和 19，但不用擔心 2 和 7，因為當初檢查 2 和 7 時就確認不滿足了。
            if(nums[i] + nums[j] == target){
                array[0]=i;
                array[1]=j;
                return array;
            }
        }   
    }
    return NULL;
}

int main(){
    int nums[4] = {2,7,11,15};
    int target = 9;
    int returnSize;
    int *array = twoSum(nums, 4, target, &returnSize);
    if (array == NULL){
        printf("NULL");
    }
    else{
        printf("%d %d\n", array[0], array[1]);
    }
    return 0;
}

// compile: gcc 1.c -o 1_c
// run: ./1_c