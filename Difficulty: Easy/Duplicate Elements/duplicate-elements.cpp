//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }
 
    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends



class Solution {
public:
    void SortedDuplicates(int n, vector<int>& arr) {
        map<int, int> freqMap;
        vector<int> duplicates;

        // Count frequencies of each element
        for (int num : arr) {
            freqMap[num]++;
        }

        // Extract elements with frequency > 1
        for (auto it : freqMap) {
            if (it.second > 1) {
                duplicates.push_back(it.first);
            }
        }

        // Print the result
        if (duplicates.empty()) {
            cout << -1 << endl;
        } else {
            for (int num : duplicates) {
                cout << num << " ";
            }
            cout << endl;
        }
    }
};



//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n; 
        scanf("%d",&n);
        
        
        vector<int> arr(n);
        Array::input(arr,n);
        
        Solution obj;
        
        obj.SortedDuplicates(n, arr);
        
    }
}

// } Driver Code Ends