//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    vector<int> nthRowOfPascalTriangle(int n) {
        // code here
        vector<vector<int>>prr(20,vector<int>(20,0));
        prr[0][0]=1;
        for(int i=1;i<20;i++)
        {
            for(int j=0;j<=i;j++)
            {
                if(j==0)
                {
                    prr[i][0]=1;
                    continue;
                }
                else
                {
                    prr[i][j]=prr[i-1][j]+prr[i-1][j-1];
                }
            }
        }
        vector<int>res;
        int index=n-1;
        for(int i=0;i<prr[index].size();i++)
        {
            if(prr[index][i]==0)
            break;
            res.push_back(prr[index][i]);
        }
        return res;
    }
};


//{ Driver Code Starts.

void printAns(vector<int> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.nthRowOfPascalTriangle(n);
        printAns(ans);

        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends