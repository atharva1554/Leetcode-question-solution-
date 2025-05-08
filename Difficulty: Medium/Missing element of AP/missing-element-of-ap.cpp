//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
    int findMissing(vector<int> &arr) {
        // code here
        int a=arr[0];
        int d=arr[1]-arr[0];
        int End=arr.size()-1;
        
        int Start=0;
        
        while(Start<=End){
            int Mid=Start+(End-Start)/2;
            
            if(arr[Mid]==a+d*Mid){  //mtlb mil gaya aage dekho
                Start=Mid+1;
            }else{
                End=Mid-1;   // nahi mila piche dekho
            }
        }
        return a+d*Start;  //return  karo value
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;

        getline(cin, input);

        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        cout << ob.findMissing(arr) << "\n";
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends