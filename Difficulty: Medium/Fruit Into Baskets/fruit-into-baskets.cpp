//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int totalFruits(vector<int> &arr) {
        int cnt=0;
        int n=arr.size();
        for(int i=0;i<n;i++)
        {  
            int x=arr[i];
            int y=0;
            for(int j=i;j<n;j++)
            {    
                if(arr[j]==x)
                {  cnt=max(cnt,j-i+1);
                    continue;
                }
                if(arr[j]!=x&& y==0)
                {  cnt=max(cnt,j-i+1);
                    y=arr[j];
                }
                if(arr[j]==y)
                {  cnt=max(cnt,j-i+1);
                    continue;
                }
                else if(arr[j]!=y && arr[j]!=x)
                {   
                   
                    break;
                }
                
            }
        }
        return cnt;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore any newline character left in the buffer
    while (t--) {
        string line;
        getline(cin, line); // Read the entire line of input
        stringstream ss(line);
        vector<int> arr;
        int num;

        // Parse the input line into integers and add to the vector
        while (ss >> num) {
            arr.push_back(num);
        }
        Solution ob;
        int ans = ob.totalFruits(arr);

        cout << ans << endl;
    }
    return 0;
}

// } Driver Code Ends