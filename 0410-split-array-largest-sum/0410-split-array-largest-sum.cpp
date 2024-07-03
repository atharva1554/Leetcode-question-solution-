class Solution {
public:
int split(vector<int>&a,int sum)
{
    int n=a.size();
    int ans=1;
    int load=0;
    for(int i=0;i<n;i++)
    {
        if(load+a[i]<=sum)
        {
            load=load+a[i];
        }
        else
        {
            ans++;
            load=a[i];
        }
    }
    return ans;
}
    int splitArray(vector<int>& nums, int k) {
        int low=nums[0];
        int high=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            low=max(low,nums[i]);
            high=high+nums[i];
        }
        while(low<=high)
        {
            int mid=(low+high)/2;
            int ans=split(nums,mid);
            if(ans>k)
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