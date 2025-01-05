//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int countFractions(int n, int numerator[], int denominator[]) {
        map<pair<int, int>, int> mpp;
        int ans = 0;

        for (int i = 0; i < n; i++) {
            int num = numerator[i];
            int den = denominator[i];

            // Reduce the fraction
            int gcd = __gcd(num, den);
            num /= gcd;
            den /= gcd;

            // Calculate complement (den - num) / den
            int comp_num = den - num;
            int comp_gcd = __gcd(comp_num, den);
            comp_num /= comp_gcd;
            den /= comp_gcd;

            // Check if complement exists in map
            if (mpp[{comp_num, den}] > 0) {
                ans += mpp[{comp_num, den}];
            }

            // Store the current fraction in the map
            mpp[{num, den}]++;
        }

        return ans;
    }
};


//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int numerator[n],denominator[n];
        for(int i=0;i<n;i++)
            cin>>numerator[i];
        for(int i=0;i<n;i++)
            cin>>denominator[i];
        Solution ob;
        int ans=ob.countFractions(n,numerator,denominator);
        cout<<ans<<endl;
    
cout << "~" << "\n";
}
}
// } Driver Code Ends