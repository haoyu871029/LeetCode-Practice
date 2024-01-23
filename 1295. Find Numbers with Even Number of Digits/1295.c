#include <stdio.h>

int findNumbers(int* nums, int numsSize) {
    int result = 0;
    for (int i=0; i<numsSize; i++){
        int tmp = nums[i];
        int digits = 0;
        while (tmp != 0){
            digits++;
            tmp /= 10;
        }
        if (digits%2 == 0){
            result++;
        }
    }
    return result;
}

int main(){
    int nums[] = {12,345,2,6,7896};
    int numsSize = sizeof(nums)/sizeof(nums[0]);
    int result = findNumbers(nums, numsSize);
    printf("%d\n", result);
    return 0;
}

// compile: gcc 1295.c -o 1295
// execute: ./1295