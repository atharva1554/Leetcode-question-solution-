class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
          long long int x=0;
          long long int y=0;
          for(int i=0;i<nums.size();i++)
          {
            if(nums[i]<=9)
            {
                x=x+nums[i];
            }
            else
            {
                y=y+nums[i];
            }
          }
          if(x==y)
          {
            return false;
          }
          return true;
    }
};