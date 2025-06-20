class Solution {
  public:
    bool validgroup(vector<int> &arr, int k) {
        // code here
         int n=arr.size();
        if(n%k!=0)return 0;
        if(k==1)return 1;
        sort(begin(arr),end(arr));
        
        
        int len=1;
       
        multiset<int>ms;
         
        for(auto i:arr){
            ms.insert(i);
        }
        while(ms.size()>0){
            int len=1;
              int f=*ms.begin();
                ms.erase(ms.begin());
            while(len<k){
              
                auto fnd=ms.find(f+1);
                if(fnd==ms.end()){
                    return 0;
                }
                 f=*fnd;
                ms.erase(fnd);
               
               
                len++;
            }
           
        }
        return 1;
    }
};