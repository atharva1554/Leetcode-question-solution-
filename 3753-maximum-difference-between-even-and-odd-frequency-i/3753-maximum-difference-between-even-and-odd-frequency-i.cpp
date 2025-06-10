class Solution {
public:
    int maxDifference(string s) {
        map<char,int>mpp;
        for(int i=0;i<s.length();i++)
        {
            mpp[s[i]]++;
        }
        int o1=INT_MAX;
        int e1=INT_MAX;
        int e2=INT_MIN;
        int o2=INT_MIN;
        for(auto it:mpp)
        {
            if(it.second%2==0)
            {
                e1=min(e1,it.second);
                e2=max(e2,it.second);
            }
            else
            {
                o1=min(o1,it.second);
                o2=max(o2,it.second);
            }
            cout<<it.second<<" ";
        }
        int ans=max((o2-e1),(o1-e2));
        cout<<"\ne1 "<<e1;
        cout<<"\ne2 "<<e2;
        cout<<"\no1 "<<o1;
        cout<<"\no2 "<<o2;
    return ans;
    }
    
};