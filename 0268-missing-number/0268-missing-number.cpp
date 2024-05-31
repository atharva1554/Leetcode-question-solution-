class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int t=nums.size();
        for(int i=0;i<nums.size();i++)
        {
            if(i!=nums[i])
            {
                t=i;
                break;
            }
        }
        return t;
    }
};