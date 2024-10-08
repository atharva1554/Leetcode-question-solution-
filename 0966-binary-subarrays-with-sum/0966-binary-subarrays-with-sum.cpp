class Solution {
public:
int solution(vector<int>& num, int g)
{
     int l=0,r=0,sum=0,cnt=0;
     if(g<0)
     {
        return 0;
     }
        while(r<num.size())
        {
            sum=sum+num[r];
            while(sum>g)
            {
                sum=sum-num[l];
                l=l+1;
            }
            cnt=(cnt+(r-l+1));
            r=r+1;
        }
        return cnt;
}
    int numSubarraysWithSum(vector<int>& nums, int goal) {
       return solution(nums,goal)-solution(nums,goal-1);
    }
};