//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    string decodedString(string &s) {
        // code here
        stack<char> st;
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            
            if(s[i]!=']')
            {
                st.push(s[i]);
            }
            else
            {
                string val ="";
                while(!st.empty() && st.top()!='[')
                {
                    val+=st.top();
                    st.pop();
                }
                reverse(val.begin(),val.end());
                st.pop();
                string freq = "";
               while(!st.empty() && st.top()>='0' && st.top()<='9')
               {
                   char nos = st.top();
                   st.pop();
                   freq += nos;
               }
               reverse(freq.begin(),freq.end());
               int times = stoi(freq);
               for(int j=0;j<times;j++)
               {
                   for(char c:val)
                   {
                       st.push(c);
                   }
               }
            }
        }
        string res = "";
        while(!st.empty())
        {
            char val=st.top();
            st.pop();
            res+=val;
        }
        reverse(res.begin(),res.end());
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        Solution ob;
        cout << ob.decodedString(s) << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends