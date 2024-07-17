class Solution {
public:
int sol(int n)
{
    int ans=0;
    while(n>0)
    {
        if(n%2!=0)
        {
            ans++;
        }
        n=n/2;
    }
    return ans;
}
    int minBitFlips(int start, int goal) {
        int ans=start^goal;
        int d=sol(ans);
        return d;
    }
};