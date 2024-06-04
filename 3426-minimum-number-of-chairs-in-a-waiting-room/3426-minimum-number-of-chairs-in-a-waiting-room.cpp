class Solution {
public:
    int minimumChairs(string s) {
        int maxi=INT_MIN;
        int t=0;
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            if(s[i]=='E')
            {
                t++;
            }
            else
            {
                t--;
            }
            maxi=max(t,maxi);
        }
        return maxi;
        
    }
};