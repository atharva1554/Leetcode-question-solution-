class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int last_smaller=INT_MIN;
        int cnt=0,longest=0;
       
        for(int i=0;i<n;i++)
        {
            if(nums[i]-1==last_smaller)
            {
                cnt++;
                last_smaller=nums[i];
            }
            else if(last_smaller !=nums[i])
            {
                cnt=1;
                last_smaller=nums[i];
            }
            longest=max(cnt,longest);
        }
        return longest;
    }
};