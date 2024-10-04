class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char>st;
        long long  n=num.size();
        for(long long i=0;i<n;i++)
        {
            while(!st.empty()&&((st.top()-'0')>(num[i]-'0'))&&k>0)
            {
                st.pop();
                k=k-1;
            }
            st.push(num[i]);

        }
        while(k>0)
        {
            st.pop();
            k=k-1;
        }

        if(st.empty())
        {
            return "0";
        }
        string ans="";
       
        while(!st.empty())
        {
            ans+= st.top();
            st.pop();
        }

        while (!ans.empty() && ans.back() == '0') {
            ans.pop_back();
        }
        reverse(ans.begin(), ans.end());
        if (ans.empty()) {
            return "0";
        }
       
        return ans;
    }
};