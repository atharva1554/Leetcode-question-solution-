//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int getMaxArea(vector<int> &arr) {
        // Your code here
        
        int n=arr.size();
        int mini=*min_element(arr.begin(),arr.end());
        int area=0;
        int i=0;
        
        while(i<n){
            int k=i-1 , j=i+1;
            if(arr[i]==mini){
                area=max(area,arr[i]*n);
                i++;
                continue;
            }
            while(k>=0 and arr[i]<=arr[k]) k--;
            while(j<n and arr[i]<=arr[j]) j++;
            
            area=max(area,arr[i]*(j-k-1));
            i++;
        }
        
        return area;
        
    }
};



//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.getMaxArea(arr);
        cout << res << endl;
        cout << "~" << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends