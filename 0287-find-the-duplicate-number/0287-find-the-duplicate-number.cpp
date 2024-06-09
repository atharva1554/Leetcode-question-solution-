class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        map<int,int>mpp;
        int a;
        for(int i=0;i<nums.size();i++)
        {
            mpp[nums[i]]++;
            if(mpp[nums[i]]==2)
            {
                a= nums[i];
            }
        }
    
        return a;
    }
};