class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n =nums.size();
        int j=0;
        int t;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==0)
            {
                 t=nums[j];
                nums[j]=0;
                nums[i]=t;
                j++;
            }
        }
        for(int i=j;i<n;i++)
        {
            if(nums[i]==1)
            {
                t=nums[j];
                nums[j]=1;
                nums[i]=t;
                j++;
            }
        }
    }
};