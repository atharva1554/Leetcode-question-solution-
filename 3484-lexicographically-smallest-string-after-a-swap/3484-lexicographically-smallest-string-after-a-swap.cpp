class Solution {
public:
    string getSmallestString(string s) {
        int n=s.size();
       
        for(int i=1;i<n;i++)
        {
            if(s[i]<s[i-1])
            {  
                if(s[i]%2==s[i-1]%2)
                {
                    char a=s[i];
                    s[i]=s[i-1];
                    s[i-1]=a;
                    break;
                }
            }
        }
        return s;
        
    }
};