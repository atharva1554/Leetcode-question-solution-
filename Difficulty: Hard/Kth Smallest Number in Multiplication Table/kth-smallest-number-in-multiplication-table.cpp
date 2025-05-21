class Solution {
  public:
    int kthSmallest(int m, int n, int k) {
       
        int l=1;
        int r=1e9;
        int ans;
        while(l<=r){
            int mid=l+(r-l)/2;
           
            int cnt=0;
            for(int i=1;i<=m;i++){
                cnt+=min(mid/i,n);    
               
            }

            if(cnt<k){
                l=mid+1;
            }
            else{
               
                ans=mid;
                r=mid-1;
            }
        }
        return ans;
    }
};