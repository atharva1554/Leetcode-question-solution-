class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n=nums.size();
        long long int total=0;
        int a=0;
        int b=0;
        for(int i=0;i<n;i++)
        {    a=b=nums[i];
            for(int j=i+1;j<n;j++)
            {  a=max(a,nums[j]);
               b=min(b,nums[j]);
                total=total+(a-b);
            }
        }
        return total;
    }
};