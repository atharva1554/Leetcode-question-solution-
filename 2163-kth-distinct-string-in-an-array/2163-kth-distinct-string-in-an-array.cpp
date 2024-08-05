class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        map<string,int>mpp;
        for(int i=0;i<arr.size();i++)
        {
            mpp[arr[i]]++;
        }
        vector<string>ans;
        for(int i=0;i<arr.size();i++)
        {
            if(mpp[arr[i]]==1)
            {
                ans.push_back(arr[i]);
            }
        }
        if(ans.size()<k)
        {
            return "";
        }
        else
        {
            return ans[k-1];
        }

    }
};