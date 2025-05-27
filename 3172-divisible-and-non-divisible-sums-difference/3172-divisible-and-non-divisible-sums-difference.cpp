class Solution {
public:
    int differenceOfSums(int n, int m) {
        long long a=0;
        long long b=0;
        long long x=0;
        while(x<=n)
        {
            if(x%m!=0)
            {
                a=a+x;
            }
            else
            {
                b=b+x;
            }
            x++;
        }
        return a-b;
    }
};