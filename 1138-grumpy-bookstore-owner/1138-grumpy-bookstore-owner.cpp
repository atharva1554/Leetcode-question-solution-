class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n=customers.size();
        int sum=0;
        int ans=INT_MIN;
        if(n<=minutes)
        {
            for(int i=0;i<n;i++)
            {
                sum=sum+customers[i];
            }
            return sum;
        }
         
        else
        {
            for(int i=0;i<n;i++)
            {
                if(grumpy[i]==0)
                {
                    sum=sum+customers[i];
                }
                
            }
            for(int i=0;i<n;i++)
            {
                int maxi=sum;
                int t=minutes;
                if(grumpy[i]==1)
                {  int j=i;
                    while(t--&&j<=n-1)
                    {
                        if(grumpy[j]==1)
                        {
                            maxi=maxi+customers[j];
                        }
                        j++;
                    }
                   
                }
                 ans=max(maxi,ans);
            }
            return ans;
        }
    }
};