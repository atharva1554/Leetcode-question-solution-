class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
       vector<int>ans;
       vector<int>n(nums);
       for(int i=0;i<nums.size();i++)
       {
          n.push_back(nums[i]);
       }
       for(int i=0;i<nums.size();i++)
       { int cnt=0;
        for(int j=i;j<n.size();j++)
        {
            if(n[j]>nums[i])
            {
                ans.push_back(n[j]);
                cnt=1;
                break;
            }
        }
        if(cnt==0)
        {
            ans.push_back(-1);
        }
       }
       return ans;
    }
};