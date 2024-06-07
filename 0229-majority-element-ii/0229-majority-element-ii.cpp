class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int>a;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            int count=(n/3)+1;
            for(int j=0;j<n;j++)
            {
                if(nums[i]==nums[j])
                {
                    count--;
                }
            }
            if(count<=0)
            {   int x=0;
               for(int k=0;k<a.size();k++)
               {
                 if(nums[i]==a[k])
                 {
                    x=1;
                 }
               }
               if(x==0)
               {
                 a.push_back(nums[i]);
               }
            }
        }
        return a;
    }
};