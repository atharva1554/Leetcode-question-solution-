class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int n=arr.size();
        int cnt=0;
        for(int k=2;k<n;k++)
        {
            for(int j=0;j<k;j++)
            {
                for(int i=0;i<j;i++)
                {
                    if((abs(arr[i]-arr[j])<=a)&&(abs(arr[j]-arr[k])<=b)&&(abs(arr[i]-arr[k])<=c))
                    {
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }
};