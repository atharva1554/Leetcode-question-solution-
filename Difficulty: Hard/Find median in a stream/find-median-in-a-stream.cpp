//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<double> getMedian(vector<int> &arr) {
        vector<double> ans;
        
        // double median = 0.0;
        priority_queue<int> mx;
        priority_queue<int,vector<int>,greater<int>> mn;
        
        mx.push(-1e9);
        mn.push(1e9);
        
        for(auto e:arr)
        {
            int x = mx.size();
            int y = mn.size();
            
            if(x == y)
            {
                if(e < mn.top())
                {
                    mx.push(e);
                    ans.push_back(mx.top());
                }
                else
                {
                    mn.push(e);
                    ans.push_back(mn.top());
                }
            }
            else if(x < y)
            {
                if(e < mn.top())
                {
                    mx.push(e);
                    ans.push_back((double)(mx.top()+mn.top())/2.0);
                }
                else
                {
                    mx.push(mn.top());
                    mn.pop();
                    mn.push(e);
                    ans.push_back((double)(mx.top()+mn.top())/2.0);
                }
            }
            else
            {
                if(e>mx.top())
                {
                    mn.push(e);
                    ans.push_back((double)(mx.top()+mn.top())/2.0);
                }
                else
                {
                    mn.push(mx.top());
                    mx.pop();
                    mx.push(e);
                    ans.push_back((double)(mx.top()+mn.top())/2.0);
                }
            }
        }
        
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        Solution ob;
        vector<double> ans = ob.getMedian(nums);
        cout << fixed << setprecision(1);
        for (auto &i : ans)
            cout << i << " ";
        cout << "\n";
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends