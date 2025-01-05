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

#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
  public:
    vector<vector<int>> kTop(vector<int>& arr, int N, int K) {
        vector<vector<int>> result;
        unordered_map<int, int> freqMap;  // To store frequency of elements
        
        // Iterate over the array
        for (int i = 0; i < N; ++i) {
            // Update the frequency of the current element
            freqMap[arr[i]]++;
            
            // Create a vector of pairs (element, frequency) from the map
            vector<pair<int, int>> freqVec(freqMap.begin(), freqMap.end());
            
            // Sort the vector: 
            // First by frequency in descending order, then by element in ascending order
            sort(freqVec.begin(), freqVec.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
                if (a.second == b.second) {
                    return a.first < b.first;  // If frequencies are the same, sort by element value
                }
                return a.second > b.second;  // Otherwise, sort by frequency
            });
            
            // Collect the top K elements (or fewer if there are not enough distinct elements)
            vector<int> topK;
            for (int j = 0; j < min(K, (int)freqVec.size()); ++j) {
                topK.push_back(freqVec[j].first);
            }
            
            // Add the top K elements to the result
            result.push_back(topK);
        }
        
        return result;
    }
};



//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        int K;
        scanf("%d",&K);
        
        
        vector<int> a(N);
        Array::input(a,N);
        
        Solution obj;
        vector<vector<int>> res = obj.kTop(a, N, K);
        
        for(auto it:res)
            Array::print(it);
        
    
cout << "~" << "\n";
}
}

// } Driver Code Ends