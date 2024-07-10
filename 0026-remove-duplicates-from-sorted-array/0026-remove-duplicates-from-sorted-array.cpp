class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int>a;
        int n=nums.size();
        a.push_back(nums[0]);
        for(int i=0;i<n;i++)
        {
             if(a.back()!=nums[i])
             {
                a.push_back(nums[i]);
             }
        }
        nums=a;
        return a.size();
    }
};