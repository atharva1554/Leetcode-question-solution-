class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n=nums.size();
        vector<int>ans;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==val)
            {
                n--;
            }
            else
            {
                ans.push_back(nums[i]);
            }
        }
        nums=ans;
        return n;
    }
};