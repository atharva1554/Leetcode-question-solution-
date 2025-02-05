class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        map<char,int>a;
         map<char,int>b;
        for(int i=0;i<s1.size();i++)
        {
            a[s1[i]]++;
            b[s2[i]]++;
        }
        for(auto it:a)
        {
            if(it.second!=b[it.first])
            {
                return false;
            }
        }
        int cnt=0;
        for(int i=0;i<s1.size();i++)
        {
            if(s1[i]!=s2[i])
            {
                cnt++;
                if(cnt>2)
                {
                    return false;
                }
            }
        }


        return true;
    }
};