class Solution {
public:
    void rotate(vector<int>& nums, int k) {
     int n=nums.size();
     vector<int>a;
     a=nums;
     if(k%n==0)
     {
       k=0;     
    }
    else
    {
        k=k%n;
    }
   for(int i=0;i<k;i++)
   {
    nums.pop_back();
   }
     nums.insert(nums.begin(),a.begin()+(n-k),a.end());
    
    }
};