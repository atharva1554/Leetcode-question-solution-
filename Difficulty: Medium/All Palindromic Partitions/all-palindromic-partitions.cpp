class Solution {
  public:
  bool checkpalindrome(string&s)
  {
      int n=s.length();
      for(int i=0;i<n/2;i++)
      {
          if(s[i]!=s[n-1-i])
          {
              return false;
          }
      }
      return true;
  }
  
  void rec(int idx,string&s ,vector<string>&temp,vector<vector<string>>&ans)
  {
      if(idx==s.length())
      {
          ans.push_back(temp);
          return;
      }
      int n=s.length();
      for(int j=idx;j<n;j++)
      {
          int len=j-idx+1;
          string curr=s.substr(idx,len);
          if(checkpalindrome(curr))
          {
              temp.push_back(curr);
              rec(j+1,s,temp,ans);
              temp.pop_back();
          }
      }
  }
    vector<vector<string>> palinParts(string &s) {
        // code here
        vector<vector<string>>ans;
        vector<string>temp;
        rec(0,s,temp,ans);
        return ans;
        
    }
};