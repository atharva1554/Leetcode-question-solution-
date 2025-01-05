//{ Driver Code Starts


#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
public:
    vector<int> numberWithNoConsecutiveOnes(int n) {
        vector<int> ans;
        int limit = (1 << n);  // This is equivalent to 2^n
        
        // Loop through all numbers from 1 to 2^n - 1
        for (int i = 1; i < limit; i++) {
            // If the number does not have consecutive 1's, add it to the answer
            if ((i & (i >> 1)) == 0) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		vector<int>ans = ob.numberWithNoConsecutiveOnes(n);
		for(auto i: ans)
			cout << i <<" ";
		cout << "\n";
	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends