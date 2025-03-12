//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    void binSort(vector<int> &arr) {
        // code here
        int x=0;
        for(int i=0;i<arr.size();i++)
        {
            x+=arr[i];
        }
        for(int i=arr.size()-x;i<arr.size();i++)
        {
            arr[i]=1;
        }
        for(int i=0;i<arr.size()-x;i++)
        {
            arr[i]=0;
        }
    }
};



//{ Driver Code Starts.

int main() {
    int t; // Number of test cases
    cin >> t;
    cin.ignore(); // Ignore the newline after the integer input
    while (t--) {
        vector<int> a;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num); // Read the array elements from input string

        Solution obj;
        obj.binSort(a);

        for (int i = 0; i < a.size(); i++) {
            if (i != 0)
                cout << " ";
            cout << a[i];
        }
        cout << endl;        // Ensure new line after each test case output
        cout << "~" << endl; // Ensure new line after each test case output
    }

    return 0;
}

// } Driver Code Ends