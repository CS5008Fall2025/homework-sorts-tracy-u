/*
* Name: Tracy U. 
* CS 5008, Fall 2025
* Assignment: Sorts
* Coding Challenge: https://leetcode.com/problems/sort-array-by-parity/description/
* What I learned: 
- As compared to other solutions, mine solution below was slower. I interpreted the 
challenge to require malloc-ing a new array, while faster solutions
returned the existing nums array in place. The looping was also approached differently
swapping instead of copying from one array into another. I see how much more 
efficient that approach is. 
*/



/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortArrayByParity(int* nums, int numsSize, int* returnSize) {
        int evens_index = 0;
        int end_index = numsSize - 1;
        *returnSize = numsSize;
        int* newArr = (int *)malloc(sizeof(int) * numsSize);
        
        for(int i = 0; i < numsSize; i++) {
            if(nums[i] % 2 == 0) {
                newArr[evens_index] = nums[i];
                evens_index++;
            } else {
                newArr[end_index] = nums[i];
                end_index--;
            }
        }
        return newArr;
}
