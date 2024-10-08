class Solution {
public:
int sol(vector<int>&num,int t)
{
    int n=num.size();
    if(t<0)
    {
        return 0;
    }
    for(int i=0;i<n;i++)
    {
        num[i]=num[i]%2;
    }
    int l=0,r=0,cnt=0,sum=0;
    while(r<n)
    {
        sum=sum+num[r];
        while(sum>t)
        {
            sum=sum-num[l];
            l=l+1;
        }
        cnt=cnt+(r-l+1);
        r=r+1;
    }
    return cnt;
}
    int numberOfSubarrays(vector<int>& nums, int k) {
        return sol(nums,k)-sol(nums,k-1);
    }
};