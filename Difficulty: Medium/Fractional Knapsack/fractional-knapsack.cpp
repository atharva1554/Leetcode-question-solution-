//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

class Solution {
  public:
    // Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        // Your code here
        vector<double>per;
        for(int i=0;i<wt.size();i++)
        {
            per.push_back(double(double( val[i]) /double(wt[i])));
        }
        vector<vector<double>>t;
        for(int i=0;i<per.size();i++)
        {
            t.push_back({per[i],val[i],wt[i]});
        }
        sort(t.begin(),t.end());
        reverse(t.begin(),t.end());
        // for(int i=0;i<t.size();i++)
        // {
        //     cout<<t[i][0]<<" "<<t[i][1]<<" "<<t[i][2]<<endl;
        // }
        int x=0;
        int i=0;
        double ans=0;
         for(int i=0;i<t.size();i++)
        {
            if(x+t[i][2]<=capacity)
            {
                x=x+t[i][2];
                ans=ans+t[i][1];
                
            }
            else
            {
                ans=ans+double(capacity-x)*t[i][0];
                break;
            }
            
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    // taking testcases
    cin >> t;
    cin.ignore(); // to ignore the newline after the number of test cases
    cout << setprecision(6) << fixed;

    while (t--) {
        // Reading the value array
        vector<int> values;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            values.push_back(number);
        }

        // Reading the weight array
        vector<int> weights;
        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> number) {
            weights.push_back(number);
        }

        // Reading the capacity
        int w;
        cin >> w;
        cin.ignore(); // to ignore the newline after capacity

        // function call
        Solution ob;
        cout << ob.fractionalKnapsack(values, weights, w) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends