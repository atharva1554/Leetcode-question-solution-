class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int minus=0;
        int positive=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<0)
            {
               minus++;
            }
            else if(nums[i]>0)
            {
                positive++;
            }
        }
        return max(minus,positive);
    }
};