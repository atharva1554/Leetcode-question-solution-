class Solution {
public:
  long long int s(vector<int>&nums, long long int d)
  {  long long int ans=0;
    for(int i=0;i<nums.size();i++)
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
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low=1;
        int high=0;
        for(int i=0;i<nums.size();i++)
        {
            high=max(high,nums[i]);
        }
        while(low<=high)
        {
            long long int mid=(low+high)/2;
            long long int ak=s(nums,mid);
            if(ak>threshold)
            {
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        return low;
    }
};