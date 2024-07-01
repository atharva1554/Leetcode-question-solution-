class Solution {
    long long int t(vector<int>&nums,long long int  d)
    {
        int n=nums.size();
       long long int  ans=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]%d==0)
            {
                ans=ans+(nums[i]/d);
            }
            else
            {
                ans=ans+(nums[i]/d)+1;
            }
        }
        return ans;
    }
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low=1;
        int high=0;
        for(int i=0;i<nums.size();i++)
        {
           
            high=max(high,nums[i]);
        }
        while(low<=high)
        {
           long long int  mid=(low+high)/2;
           long long int  ans=t(nums,mid);
            if(ans<=threshold)
            {
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return low;
    }
};