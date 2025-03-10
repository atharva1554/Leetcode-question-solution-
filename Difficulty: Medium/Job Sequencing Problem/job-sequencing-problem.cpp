//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


// } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    
     bool static comparitor(struct Job one,  Job two){
        if( one.profit>two.profit) return true;
        return false;
    }
    
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        int cnt=0,profit=0;
        sort(arr,arr+n,comparitor);
        int ans=1;
        for(int i=0;i<n;i++) ans=max(ans,arr[i].dead);
        vector<int> deadline(ans+2,0);
        
        for(int i=0;i<n;i++){
            // cout<<arr[i].id<<" ";
            for(int j=arr[i].dead;j>0;j--){
                if(deadline[j]==0){
                    deadline[j]=arr[i].id;
                    cnt++;
                    profit+=arr[i].profit;
                    break;
                }
            }
        }
        // cout<<endl;
        // for(auto i: deadline) cout<<i<<" ";
        vector<int> fans;
        fans.push_back(cnt);
        fans.push_back(profit);
        return fans;
    } 
};

//{ Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}



// } Driver Code Ends