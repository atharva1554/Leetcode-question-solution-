class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int ans=-1;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                if(nums[j]>nums[i])
                {
                    ans=max(ans,nums[j]-nums[i]);
                }
            }
        }
        return ans;
    }
};