class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int>ans;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(ans.empty())
            {
                ans.push_back(nums[i]);
            }
            else
            {
                if(ans.back()-nums[i]!=0)
                {
                    ans.push_back(nums[i]);
                }
            }
            cout<<ans.back()<<" ";
        }
        nums=ans;
        return ans.size();
    }
};