class Solution {
  public:
   int minValue(string &s, int k) {
        if(k>=s.length())return 0;
        vector<int>hash(26,0);
        for(auto l : s){
            hash[l-'a']++;
        }
        int ans=0;
       priority_queue<int>q;
       for(auto i:hash){
           if(i!=0)q.push(i);
       }
       while(k){
           int a=q.top();
           q.pop();
           q.push(--a);
           k--;
       }
       while(q.size()>0){
           ans+=(q.top()*q.top());
           q.pop();
       }
       return ans;
    }
};