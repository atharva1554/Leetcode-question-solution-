class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        map<int,int>mpp;
        for(int i=0;i<nums.size();i++)
        {
            mpp[nums[i]]++;
        }
        nums.clear();
        for(auto it:mpp)
        {
            if(it.second>0)
            {
                if(it.second>=2)
                {
                    nums.push_back(it.first);
                    nums.push_back(it.first);
                }
                else
                {
                    nums.push_back(it.first);
                }
            }
        }
        return nums.size();
    }
};