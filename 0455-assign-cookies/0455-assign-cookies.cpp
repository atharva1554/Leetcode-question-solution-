class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int cnt=0;
        int j=0;
        for(int i=0;i<g.size();i++)
        {
            for(;j<s.size();j++)
            {
                if(g[i]<=s[j])
                {
                    s[j]=-1;
                    cnt++;
                    break;
                }
            }
        }
        return cnt;
    }
};