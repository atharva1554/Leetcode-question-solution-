class Solution {
public:
    int ans(int n)
    {
        int ans=0;
        while(n>0)
        {
            if(n%2==1)
            {
                ans++;
            }
            n=n/2;
        }
        return ans;
    }
    int minChanges(int n, int k) {
        if((n&k)!=k)
        {
            return -1;
        }
        int b=n^k;
        return ans(b);
    }
};