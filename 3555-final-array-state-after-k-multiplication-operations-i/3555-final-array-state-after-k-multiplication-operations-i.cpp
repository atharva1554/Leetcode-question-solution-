class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        while(k--)
        {
            int x=0;
            for(int i=0;i<nums.size();i++)
            {
                if(nums[i]<nums[x])
                {
                    x=i;
                }
            }
            nums[x]=nums[x]*multiplier;
        }
        return nums;
    }
};