//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends




class Solution {
  public:
    /*int isPalindrome(int start,int end,string s){
        
        while(start<=end){
            if(s[start]!=s[end])return false;
            start++;
            end--;
        }
        return true;
    }*/
    int countPS(string &s) {
        // code here
        int count=0;
        int n=s.size();
        /*for(int i=0;i<n;i++){
            
            for(int j=i;j<n;j++){
                
                if(j-i+1>=2){
                    if(isPalindrome(i,j,s))count++;
                }
            }
        }*/
        
        for(int i=0;i<n;i++){
            //even case
            int left=i;
            int right=i+1;
            while(left>=0 && right<n && s[left]==s[right]){
                if(right-left+1>=2)count++;
                left--;
                right++;
            }
            
            //Odd case
            
            left=i-1;
            right=i+1;
            while(left>=0 && right<n && s[left]==s[right]){
                if(right-left+1>=2)count++;
                left--;
                right++;
            }
            
        }
        
        return count;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.countPS(s) << endl;
        cout << "~\n";
    }
    return 0;
}
// } Driver Code Ends