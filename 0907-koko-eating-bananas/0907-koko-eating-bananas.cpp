class Solution {
public:
  long long int hrs(vector<int>&piles,int x)
    {  long long int ans=0;
        for(int i=0;i<piles.size();i++)
        {
            if(piles[i]%x==0)
            {
                ans=ans+(piles[i]/x);
            }
            else
            {
                ans=ans+(piles[i]/x)+1;
            }
        }
        return ans;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int high=0;
        int low=1;
        for(int i=0;i<piles.size();i++)
        {
              high=max(high,piles[i]);
        }
        //int ans=high;
        while(low<=high)
        {
             long long int mid=(low+high)/2;
             long long int a=hrs(piles,mid);
            if(a<=h)
            {
                //ans= min(ans,mid);
                high=mid-1;
                
            }
            else 
            { // ans=min(ans,mid);
                low=mid+1;
            }
        }
       return low; 
    }
};