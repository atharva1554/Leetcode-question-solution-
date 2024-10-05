class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> s11(26,0);
        if(s1.size()>s2.size()) return false;
        vector<int> s22(26,0);
        for(auto i:s1){
            s11[i-'a']++;
        }
        int k=s1.size();
        int l=0;
        int r=k-1;
        int n =s2.size();
        for(int i=0;i<=r;i++){
            s22[s2[i]-'a']++;
        }
        while(r<n){
            if(s11==s22) return true;
            else{
                r++;
                if(r==n) break;
                s22[s2[r]-'a']++;
                s22[s2[l]-'a']--;
                l++;
            }
        }
        return false;
    }
};