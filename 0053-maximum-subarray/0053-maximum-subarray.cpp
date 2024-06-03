class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int N=nums.size();
          long long sum=0;
        int start=-1;
        int startindex=-1,endindex=-1;
        long long max=LONG_MIN;
        for(int i=0;i<N;i++)
        {
            if(sum==0)
            {
                start=i;
            }
            sum=sum+nums[i];
            if(sum>max)
            {
                max=sum;
                startindex=start;
                endindex=i;
            }
            if(sum<0)
            {
                sum=0;
            }  
        }
        return max;
    }
    
};