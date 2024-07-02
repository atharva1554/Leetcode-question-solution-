class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n=arr.size();
        for(int i=0;i<arr.size();i++)
        {
            n=max(n,arr[i]);
        }
         n=arr.size()+k;
        vector<int>a;
        for(int i=1;i<=n;i++)
        {
            a.push_back(i);
        }
        for(int i=0;i<arr.size();i++)
        {
            for(int j=0;j<a.size();j++)
            {
                if(arr[i]==a[j])
                {
                    a[j]=-1;
                }
            }
        }
        sort(a.begin(),a.end());
       reverse(a.begin(),a.end());
        while(a.back()<1)
        {
            a.pop_back();
        }
        reverse(a.begin(),a.end());
        return a[k-1];

    }
};