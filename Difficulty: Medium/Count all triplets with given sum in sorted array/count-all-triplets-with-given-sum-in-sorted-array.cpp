//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int countTriplets(vector<int> &arr, int target) {
        int n = arr.size() ;
        int ans = 0 ;
        for(int i=0;i<n-2;i++){
            int j = i+1 ;
            int k = n-1 ;
            
            while(j < k){
                int sum = arr[i]+arr[j]+arr[k] ;
                if(sum == target) {
                    ans++ ;
                     int nextLeft = j + 1;
                while (nextLeft < k && arr[nextLeft] == arr[nextLeft - 1]) {
                    ans++;
                    nextLeft++;
                }

                k--; 
                }
               else if(sum > target) k-- ;
               else j++ ;
            }
        }
        return ans ;
    }
};

//{ Driver Code Starts.

vector<int> lineArray() {
    string line;
    getline(cin, line);
    stringstream ss(line);
    vector<int> arr;
    int num;
    while (ss >> num) {
        arr.push_back(num);
    }
    return arr;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr = lineArray();
        int target;
        cin >> target;
        cin.ignore();

        Solution ob;
        int res = ob.countTriplets(arr, target);
        cout << res << endl;
        cout << "~" << endl;
    }
}

// } Driver Code Ends