#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findErrorNums(int* nums, int numsSize, int* returnSize) {
    int* result = (int*)malloc(2*sizeof(int));
    *returnSize = 2;
    int* record = (int*)calloc(numsSize, sizeof(int));
    for (int i=0; i<numsSize; i++){
        record[nums[i]-1] += 1;
    }
    for (int i=0; i<numsSize; i++){
        if (record[i] == 2){
            result[0] = i+1;
        }
        else if (record[i] == 0){
            result[1] = i+1;
        }
    }
    free(record);
    return result;
}

int main(){
    int nums[] = {1,2,2,4};
    int numsSize = 4;
    int returnSize;
    int* result = findErrorNums(nums, numsSize, &returnSize);
    for (int i=0; i<returnSize; i++){
        printf("%d ", result[i]);
    }
    printf("\n");
    free(result);
    return 0;
}

//compile: gcc 645.c -o 645
//execute: ./645