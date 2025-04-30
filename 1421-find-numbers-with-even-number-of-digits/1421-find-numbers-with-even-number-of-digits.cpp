class Solution {
public:
    int sol(int num)
    {
        int digit=0;
        while(num)
        {
            num=num/10;
            digit++;
        }
        if(digit%2==0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    int findNumbers(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
            if(sol(nums[i]))
            {
                ans++;
            }
        }
        return ans;
    }
};