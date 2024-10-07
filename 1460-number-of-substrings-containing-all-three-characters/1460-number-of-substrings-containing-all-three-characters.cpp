class Solution {
public:
    int numberOfSubstrings(string s) {
        int cnt=0;
        int last[3]={-1};
        int n=s.size();
         int mini=0;
        for(int i=0;i<n;i++)
        {
            last[s[i]-'a']=i;
            if(last[0]!=-1 && last[1]!=-1 && last[2]!=-1)
            {
              mini =min(last[0],mini);
               mini =min(last[1],mini);
                mini =min(last[2],mini);
                cnt=cnt+mini+1;
            }
        }
        return cnt;
    }
};