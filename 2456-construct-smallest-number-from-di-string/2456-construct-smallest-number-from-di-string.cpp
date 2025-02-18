class Solution {
public:
    string smallestNumber(string& pattern) {
        const int n=pattern.size();
        vector<char> succD(n, 0);
        succD.back()+=(pattern.back()=='D');
        for(int i=n-2; i>=0; i--)
            succD[i]=(pattern[i]=='D')?succD[i+1]+1:0;
        string ans(n+1, ' ');
        iota(ans.begin(), ans.end(), '1');
        for(int i=0; i<n; i++){
            if (pattern[i]=='D'){
                reverse(ans.begin()+i, ans.begin()+i+1+succD[i]);
            }
            i+=succD[i];
        }
        return ans;
    }
};