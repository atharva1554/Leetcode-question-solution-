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
            cin >> A[i];
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i]<< " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    int countPairs(int N, vector<string> &nums, string target) {
        // code here
        unordered_map <string , int> hash;
        
        for(int i=0;i<N;i++)
        {
            hash[nums[i]]++;
        }
        
        int n = target.size();
        int ans = 0;
        
        for(int i=0;i<n;i++)
        {
            string s1 = target.substr(0,i);
            string s2 = target.substr(i);
            
            if(s1 == s2)
                ans += hash[s1] * (hash[s1] - 1);
            else
                ans += hash[s1] * hash[s2];
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        vector<string> nums;
        for(int i=0;i<N;i++){
            string temp;
            cin>>temp;
            nums.push_back(temp);
        }
        string target;
        cin>>target;
        
        Solution obj;
        int res = obj.countPairs(N, nums, target);
        
        cout<<res<<endl;
        
    
cout << "~" << "\n";
}
}

// } Driver Code Ends