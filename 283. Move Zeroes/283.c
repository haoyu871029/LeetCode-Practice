#include <stdio.h>
#include <stdlib.h>

void moveZeroes(int* nums, int numsSize) {
    int i = 0;
    for(int j=0; j<numsSize; j++){
        if(nums[j] != 0){
            int temp = nums[j];
            nums[j] = nums[i];
            nums[i] = temp;
            i++;
        }
    }
}

int main(){
    int nums[] = {0,1,0,3,12};
    int numsSize = sizeof(nums)/sizeof(nums[0]);
    moveZeroes(nums, numsSize);
    for(int i=0; i<numsSize; i++){
        printf("%d ", nums[i]);
    }
    printf("\n");
    return 0;
}

// cd "283. Move Zeroes"
// compile: gcc 283.c -o 283
// execute: ./283