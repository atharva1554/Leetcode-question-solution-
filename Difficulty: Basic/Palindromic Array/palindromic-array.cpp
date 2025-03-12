//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

/*Complete the function below*/


/*Complete the function below*/

class Solution {
  public:
    bool isPalinArray(vector<int> &arr) {
        // code here
        int n=arr.size();
        
        for(int i=0;i<n;i++)
        {
            int rem, ans=0, num=arr[i];
            while(arr[i]!=0)
            {
                rem=arr[i]%10;
                arr[i]/=10;
                ans=ans*10+rem;
            }
            
            if(ans!=num)
            return 0;
            
            
        }
        
        return 1;
        
       
        
            
        // }
        
       
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
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;

        cout << (ob.isPalinArray(arr) ? "true" : "false") << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends