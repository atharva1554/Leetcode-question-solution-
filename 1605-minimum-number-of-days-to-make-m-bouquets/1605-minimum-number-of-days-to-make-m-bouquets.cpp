class Solution {
public:
  int f(vector<int>&a,int k,int d)
  {
    int n=a.size();
    int x=0;
    int count=0;
    for(int i=0;i<n;i++)
    {   
        if(a[i]<=d)
        {
            count++;
        }
        else
        {
            x=x+(count/k);
            count=0;
        } 
    }
    x=x+(count/k);
    return x;
  }
    int minDays(vector<int>& bloomDay, int m, int k) {
        if(bloomDay.size()<(long long int)m*k)
        {
            return -1;
        }
        int low=INT_MAX;
        int high=INT_MIN;
        for(int i=0;i<bloomDay.size();i++)
        {
            low=min(low,bloomDay[i]);
            high=max(high,bloomDay[i]);
        }
        while(low<=high)
        {
            int mid=(low+high)/2;
            int ans=f(bloomDay,k,mid);
            if(ans>=m)
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