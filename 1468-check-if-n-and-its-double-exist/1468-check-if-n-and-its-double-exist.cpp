class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        int x=0;
        int n=arr.size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(arr[i]==2*arr[j]&&i!=j)
                {
                    x=1;
                }
            }
        }
        if(x==1)
        {
            return true;
        }
        return false;
        
    }
};