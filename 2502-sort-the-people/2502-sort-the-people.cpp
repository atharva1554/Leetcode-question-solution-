class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        map<int,string>mpp;
        for(int i=0;i<names.size();i++)
        {
            mpp[heights[i]]=names[i];
        }
       // sort(mpp.begin(),mpp.end());
        vector<string>ans;
        for(auto it:mpp)
        {
            ans.push_back(it.second);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};