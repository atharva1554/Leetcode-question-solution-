class Solution {
public:
    long long minCuttingCost(long long n, long long m, long long k) {
        if(n<=k&&m<=k)
        {
            return 0;
        }
        if(n>k)
        {
            long long x=n;
            while(x>k)
            {
                x--;
            }
             long long ans=x*(n-x);
            return ans;
        }
         if(m>k)
        {
            long long  x=m;
            while(x>k)
            {
                x--;
            }
            long long ans=x*(m-x);
            return ans ;
        }
        return 0;
    }
};