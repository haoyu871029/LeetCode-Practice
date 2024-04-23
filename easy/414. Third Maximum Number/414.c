#include <stdio.h>

int thirdMax(int* nums, int numsSize) {
    int temp;
    for(int i=0; i<numsSize; i++){
        for(int j=i+1; j<numsSize; j++){
            if(nums[i] < nums[j]){
                temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
            }
        }
    }
    //此時 nums 中的元素已由大至小排序好

    if(numsSize < 3) //第三大數字不存在情況一: 本來就只有<3個數字
        return nums[0]; //max_num

    int count = 1;
    for(int i=0; i<numsSize-1; i++){
        if(nums[i] != nums[i+1])
            count++;
        if(count == 3)
            return nums[i+1];
    }

    if(count < 3) //第三大數字不存在情況二: 只有第一名或只能排出前兩名
        return nums[0]; //max_num

    return 0; //不會到這裡，只是為了編譯能過
}

int main(){
    int nums[] = {2, 2, 3, 1};
    int numsSize = 4;
    printf("%d\n", thirdMax(nums, numsSize)); //1
    return 0;
}

//compile: gcc 414.c -o 414
//execute: ./414
