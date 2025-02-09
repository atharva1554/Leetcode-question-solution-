int findMaxConsecutiveOnes(int* nums, int numsSize) {
    int ans=0;
    int cnt=0;
    for(int i=0;i<numsSize;i++)
    {
        if(nums[i]==0)
        {
            if(ans<=cnt)
            {
                ans=cnt;
            }
            cnt=0;
        }
        else
        {
            cnt++;
             if(ans<=cnt)
            {
                ans=cnt;
            }
        }
    }
    return ans;
}