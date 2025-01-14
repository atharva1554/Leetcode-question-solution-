//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to find equilibrium point in the array.
    int findEquilibrium(vector<int> &arr) {
        int n=arr.size();
       vector<int> before(n);
       vector<int> after(n);
       int beforesum=0;
       int aftersum=0;
       before[0]=0;
       after[n-1]=0;
       for(int i=1;i<n;i++){
           beforesum+=arr[i-1];
           before[i]=beforesum;
       }
       for(int i=n-2;i>=0;i--){
           aftersum+=arr[i+1];
           after[i]=aftersum;
       }
       for(int i=0;i<n;i++){
           if(before[i]==after[i]){
               return i;
           }
       }
       return -1;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To discard any leftover newline characters
    while (t--)   // while testcases exist
    {
        vector<int> arr;
        string input;
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.findEquilibrium(arr) << endl;
        cout << "~" << endl;
    }
}
// } Driver Code Ends