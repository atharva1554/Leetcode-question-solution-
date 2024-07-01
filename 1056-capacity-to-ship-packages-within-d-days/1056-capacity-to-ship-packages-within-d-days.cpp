class Solution {
public:
int d(vector<int>&w,int wt)
{
    int n=w.size();
    int day=1;
    int load=0;
    for(int i=0;i<n;i++)
    { 
         if(load+w[i]>wt)
         {
            day=day+1;
            load=w[i];
         }
         else
         {
            load=load+w[i];
         }
         
    }
    
    return day;
}
    int shipWithinDays(vector<int>& weights, int days) {
        int low=INT_MIN;
        int high=0;
        for(int i=0;i<weights.size();i++)
        { 
           high=high+weights[i]; 
            low=max(low,weights[i]);
        }
       if(days==1)
       {
        return high;
       }
       
        while(low<=high)
        {
            int mid=(low+high)/2;
            int ans=d(weights,mid);
            if(ans<=days)
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