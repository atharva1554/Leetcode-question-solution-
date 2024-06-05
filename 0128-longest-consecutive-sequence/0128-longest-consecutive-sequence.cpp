class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int t=INT_MIN;
      
        int len=0;
         int count=0;
        for(int i=0;i<n;i++ )
        {
             
            if(t==nums[i]-1)
            {
                t=nums[i];
                count++;

            }
            else if(t!=nums[i])
            {  count=1;
                t=nums[i];
            }
            len=max(len,count);
        }
        return len;
    }
};