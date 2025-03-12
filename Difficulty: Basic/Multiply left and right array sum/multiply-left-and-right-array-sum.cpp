//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

//  Function to multiply the sum of first half of the array with the sum of second half
//  of the array
class Solution {
  public:
    int multiply(vector<int> &arr) {
        // code here
        int n=arr.size();
        int sum1=0;
        int sum2=0;
        for(int i=0;i<n/2;i++)
        {
            sum1+=arr[i];
        }
        for(int i=n/2;i<n;i++)
        {
            sum2+=arr[i];
        }
        return sum1*sum2;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) // while testcases exist
    {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        cout << ob.multiply(arr) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends