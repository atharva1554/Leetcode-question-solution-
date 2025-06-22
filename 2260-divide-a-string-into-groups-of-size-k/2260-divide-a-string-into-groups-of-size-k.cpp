class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
     vector<string>ans;
     int n=s.length();
     
     for(int i=0;i<n;i=i+k)
     {
        if(i+k<=n)
        {
            ans.push_back(s.substr(i,k));
            
          
        }
        else
        {
            string a=s.substr(i,n);
            for(int j=0;j<i+k-n;j++)
            {
                a=a+fill;
            }
            ans.push_back(a);
        }
     }
        return ans;
    }
};