class Solution {
  public:
    string caseSort(string& s) {
        // code here
        vector<char>upper;
        vector<char>lowwer;
        vector<int>a;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]>=65&&s[i]<=90)
            {
                a.push_back(1);
                upper.push_back(s[i]);
            }
            else if(s[i]>=97 && s[i] <=122)
            {
                a.push_back(0);
                lowwer.push_back(s[i]);
            }
        }
        sort(upper.begin(),upper.end());
        sort(lowwer.begin(),lowwer.end());
        int u=0,l=0;
        string ans="";
        for(int i=0;i<a.size();i++)
        {
            if(a[i]==0)
            {
                ans+=lowwer[l];
                l++;
                
            }
            else
            {
                ans+=upper[u];
                u++;
            }
        }
        return ans;
    }
};