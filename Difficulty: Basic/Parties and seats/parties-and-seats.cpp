//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

/* print the name of the parties along with seats
   they got in election and print the maximum seat
   received
*/
void Election2019(char party[], int seats[], int n) {
    // Map to store the total seats for each party
    map<char, int> mpp;
    
    // Summing up the seats for each party
    for (int i = 0; i < n; i++) {
        mpp[party[i]] += seats[i];  // Add seats to the corresponding party
    }
    
    int ans = 0;
    // Iterate over the map to print party and their seat count
    for (auto it : mpp) {
        cout << it.first << " " << it.second << endl;
        ans = max(ans, it.second);  // Track the maximum number of seats
    }

    // Output the maximum number of seats
    cout << ans << endl;
}

//{ Driver Code Starts.
    
int main() {
	
		int t; 
		cin>>t;
		while(t--)
		{
		    int n; 
		    cin>>n;
		    char party[n];
		    int seats[n];
		    for(int i = 0; i < n; i++)
		        cin>>party[i]; 
		     
		    for(int i = 0; i < n; i++)
		        cin>>seats[i];
		     
		    Election2019(party, seats, n);
		
cout << "~" << "\n";
}
}
// } Driver Code Ends