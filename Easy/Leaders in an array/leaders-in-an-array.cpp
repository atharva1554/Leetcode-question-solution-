//{ Driver Code Starts
// C++ program to remove recurring digits from
// a given number
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
    

class Solution{
    //Function to find the leaders in the array.
    public:
    vector<int> leaders(int a[], int n){
        // Code herev
        vector<int>b;
        int c=0;
        int maxi=0;
        for(int i=0;i<n;i++)
        {  int x=0;
          int k=i;
            for(int j=n-1;j>k;j--)
            {
                if(a[i]<a[j])
                {
                    x=1;
                    k=j;
                   
                }
            }
            if(x==0)
            {
                b.push_back(a[i]);
            }
        }
        return b;
    }
};

//{ Driver Code Starts.

int main()
{
   long long t;
   cin >> t;//testcases
   while (t--)
   {
       long long n;
       cin >> n;//total size of array
        
        int a[n];
        
        //inserting elements in the array
        for(long long i =0;i<n;i++){
            cin >> a[i];
        }
        Solution obj;
        //calling leaders() function
        vector<int> v = obj.leaders(a, n);
        
        //printing elements of the vector
        for(auto it = v.begin();it!=v.end();it++){
            cout << *it << " ";
        }
        
        cout << endl;

   }
}

// } Driver Code Ends