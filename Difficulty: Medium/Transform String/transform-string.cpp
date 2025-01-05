//{ Driver Code Starts
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


// } Driver Code Ends

class Solution
{
    /*
    
    Idea is to find the logest susequence of A that matches with suffix of A
    eg: A: eaghuk, B: dgeauk
    
    longest prefix of B that matches with longest subsequence of A is eauk
    
    so A's subsequence gh needs to be brought to front, hence ans is 2.
    
    */
    public:
    int transform (string A, string B)
    {
        
        vector<int> freq(256);
        for(char ch : A) freq[ch]++;
        
        for(char ch : B) freq[ch]--;
        
        for(int i: freq) {
            if(i != 0) return -1;
        }
        
        
        int ptrA = A.size() -1 , ptrB = B.size() -1;
        int ans = 0;
        
        while(ptrA >= 0 && ptrB >= 0) {
            while(ptrA >= 0 && A[ptrA] != B[ptrB]) {
                ptrA--;
                ans++;
            }
            ptrA--;
            ptrB--;
        }
        
        return ans;
    }
};


//{ Driver Code Starts.

int main () 
{
    int t; cin >> t;
    while (t--)
    {
        string A, B; 
        cin >> A >> B;
        Solution ob;
        cout <<ob.transform (A, B) << endl;
    
cout << "~" << "\n";
}
}
// } Driver Code Ends