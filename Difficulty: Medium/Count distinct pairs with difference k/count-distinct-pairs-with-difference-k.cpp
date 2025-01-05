//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
	public:
	int TotalPairs(vector<int>nums, int k){
	  // Code here
        int n = nums.size();
        int i = 0;
        int j = 1;
        int count = 0;
        sort(nums.begin(), nums.end());

        while (j < n) {
            int diff = nums[j] - nums[i];
            if (diff == k) {
                count++;
                i++;
                j++;
                while (i < n && nums[i] == nums[i - 1])
                    i++;
                while (j < n && nums[j] == nums[j - 1])
                    j++;
            }
            else if (diff < k) {
                j++;
            }
            else {
                i++;
            }

            if (i >= j) {
                j++;
            }
        }

        return count;
    }
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, k;
		cin >> n >> k;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution ob;
		int ans = ob.TotalPairs(nums, k);
		cout << ans <<"\n";
	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends