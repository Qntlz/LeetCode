/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int* sumArr = (int*)malloc(2*sizeof(int));

    for(int i = 0; i < numsSize; i++)
    {
        for(int j = i + 1; j < numsSize; j++)
        {
            if(nums[i] + nums[j] == target)
            {
                sumArr[0] = i;
                sumArr[1] = j;
                *returnSize = 2;
                return sumArr;
            }
        }
    }
    *returnSize = 0;
    return NULL;
}