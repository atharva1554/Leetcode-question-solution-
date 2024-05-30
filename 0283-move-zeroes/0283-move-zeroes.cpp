class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        vector<int>a;
        int t=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]!=0)
            {
                a.push_back(nums[i]);
            }
            else
            {
                t++;
            }
        }
        for(int i=0;i<n-t;i++)
        {
            nums[i]=a[i];
        }
        for(int i=n-t;i<n;i++)
        {
            nums[i]=0;
        }
    }
};