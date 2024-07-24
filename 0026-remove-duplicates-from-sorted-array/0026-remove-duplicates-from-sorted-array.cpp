class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int>ans;
        
        int cnt=0;
        for(int i=0;i<nums.size();i++)
        {
            int x=0;
            for(int j=0;j<ans.size();j++)
            {
                if(ans[j]==nums[i])
                {
                    x=1;
                    break;
                }
            }
            if(x==0)
            {
                ans.push_back(nums[i]);
            }
        }
        nums.clear();
          for(int i=0;i<ans.size();i++)
          {
            cnt++;
            nums.push_back(ans[i]);
          }
          return cnt;
    }
};