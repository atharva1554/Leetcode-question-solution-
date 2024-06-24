class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
      int x,count=1;
       x=nums[0];
       vector<int>a;
       a.push_back(nums[0]);
      for(int i=1;i<nums.size();i++)
      {
        if(nums[i]!=x)
        {
            x=nums[i];
            count++;
            a.push_back(nums[i]);
        }
      }
      nums=a;
      return count;
    }
};