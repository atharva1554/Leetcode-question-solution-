class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
       set<int>st(arr.begin(),arr.end());
       unordered_map<int,int>mp;
       int i=1;
       for(auto it:st){
        mp[it]=i++;
       }
        for(int i=0;i<arr.size();i++){
            arr[i]=mp[arr[i]];
        }
        return arr;
    }
};