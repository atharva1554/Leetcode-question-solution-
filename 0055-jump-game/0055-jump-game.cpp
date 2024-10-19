class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxi=0;
        int n=nums.size();
        if(n<2)
        {
            return true;
        }
        else if(nums[0]==0)
        {
            return false;
        }
        for(int i=0;i<n-1;i++)
        {
            int x=i+nums[i];
            if(x>=maxi)
            {
                maxi=x;
            }
            if(nums[i]==0 && maxi<=i)
            {
                return false;
            }
        }
        cout<<maxi;
        if(maxi>=n-1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};