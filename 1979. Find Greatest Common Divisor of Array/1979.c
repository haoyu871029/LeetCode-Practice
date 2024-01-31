#include <limits.h> //support INT_MAX and INT_MIN
#include <stdio.h> //support printf

int findGCD(int* nums, int numsSize) {
    int min_num = INT_MAX;
    int max_num = INT_MIN;
    for (int i = 0; i<numsSize; i++) {
        if (nums[i] < min_num) {
            min_num = nums[i];
        }
        if (nums[i] > max_num) {
            max_num = nums[i];
        }
    }
    if (max_num%min_num == 0){
        return min_num;
    }
    /* Euclidean Algorithm */
    int a = max_num;
    int b = min_num;
    while (b != 0){
        int tmp = b;
        b = a % b;
        a = tmp;
    }
    return a;
}

int main(){
    int nums[] = {2,5,6,9,10};
    int numsSize = sizeof(nums)/sizeof(nums[0]);
    int result = findGCD(nums, numsSize);
    printf("result = %d\n", result);
    return 0;
}

//compile: gcc 1979.c -o 1979
//execute: ./1979