class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int ans=nums[0];
        int cnt=nums[0];
        for(int i=1;i<nums.size();i++)
        {   
            if(nums[i-1]<nums[i])
            {
                cnt+=nums[i];
            }
            else
            {
                cnt=nums[i];
            }
            ans=max(ans,cnt);
        }
        return ans;
    }
};