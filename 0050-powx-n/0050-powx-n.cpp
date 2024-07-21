class Solution {
public:
    double myPow(double x, int n) {
        double ans=1;
        int y=0;
        if(n<0)
        {
            y=1;
            n=abs(n);
        }
        while(n>0)
        {
            if(n%2==1)
            {
                ans=ans*x;
                n=n-1;
            }
            else
            {
                n=n/2;
                x=x*x;
            }
        }
        if(y==0)
        {
            return ans;
        }
        else
        {
            return (1/ans);
        }
    }
};