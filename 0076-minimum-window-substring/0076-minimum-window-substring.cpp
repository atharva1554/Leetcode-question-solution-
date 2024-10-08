class Solution {
public:
    string minWindow(string s, string t) {
        
        int n = t.size();
        int m = s.size();
        int r=0,l=0,minl=INT_MAX;
        int count = 0;
        int sindex = -1;
        int hash[256] ={0};
        //hash mai t ki sari value bhrenge 
        for(int i=0;i<n;i++){
            hash[t[i]]++;
        }
       while(r<m){
        hash[s[r]]--;
        //+ve val dekhne ke baad 
        if(hash[s[r]]>=0){
            count = count +1;
           // hash[s[r]]--;
        }
        //we want to shrink and check 
        while(count == n){
            //index or min ka dhyaan rakhna hai 
            if(r-l+1 < minl){
                minl = r-l+1;
                //starting index
                sindex = l;
            }
            hash[s[l]]++;  //restore hash
            if(hash[s[l]]>0){
                count-- ;
            }
            l++;
        }
        r++;

       }
       return sindex==-1?"":s.substr(sindex,minl);
    }
};