class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
          auto it = unique(strs.begin(),strs.end());
          strs.erase(it, strs.end()); 
        sort(strs.begin(),strs.end());
        int n=strs.size();
        int m=strs[0].size();
        if(n==1)
        {
            return strs[0];
        }
        int x=0;
        for(int i=0;i<=m;i++)
        {   
            char a=strs[0][i];
            int cnt=0;
            for(int j=0;j<n;j++)
            {
                 if(a==strs[j][i])
                 {
                    cnt++;
                 }
            }
            if(cnt!=n)
            {    
                x=i;
                 break;
            }
        }
        return strs[0].substr(0,x);
    }
};