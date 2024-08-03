class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        sort(arr.begin(),arr.end());
        sort(target.begin(),target.end());
        int cnt=0;
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i]!=target[i])
            {
                cnt=1;
            }
        }
        if(cnt==1)
        {
            return false;
        }
        return true;
    }
};