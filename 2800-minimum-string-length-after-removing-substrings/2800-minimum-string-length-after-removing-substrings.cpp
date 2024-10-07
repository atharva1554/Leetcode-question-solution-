class Solution {
public:
    int minLength(string s) {
       int j = 0; 
       for(int i = 0; i<s.length(); i++){
        s[j] = s[i];
        if(j > 0 && ((s[j] == 'B' && s[j-1] == 'A') || (s[j] == 'D' && s[j-1] == 'C') )){
            j -= 2;
        }
        j++;
       }
       return j;
    }
};