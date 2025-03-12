//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

/*you are required to complete this method*/
class Solution {
  public:
    int convertFive(int n) {
        // Your code here
        if(n==0)
        {
            return 5;
        }
        stack<int>st;
        int ans=0;
        int rem=0;
        while(n!=0)
        {
            rem=n%10;
            if(rem==0)
            {
                st.push(5);
            }
            else
            {
                st.push(rem);
            }
            n=n/10;
        }
        while(!st.empty())
        {
            ans=ans*10+st.top();
            st.pop();
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.convertFive(n) << endl;

        cout << "~"
             << "\n";
    }
}
// } Driver Code Ends