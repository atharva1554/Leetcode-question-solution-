class Solution {
public:
    int lengthOfLongestSubstring(string s) {
      
        int n=s.size();
        int maxi=0;
       for(int j=0;j<s.size();j++)
       {   map<char,int>mpp;
          int count=0;
         for(int i=j;i<n;i++)
        {
            mpp[s[i]]++;
            if(mpp[s[i]]==2)
            {
                break;
            }
            count++;
        }
        maxi=max(maxi,count);
       }
        return maxi;
    }
};