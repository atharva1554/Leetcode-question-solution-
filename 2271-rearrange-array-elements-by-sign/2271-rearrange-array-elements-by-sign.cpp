class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>p;
        vector<int>n;
        int s=nums.size();
        for(int i=0;i<s;i++)
        {
            if(nums[i]<0)
            {
                n.push_back(nums[i]);
            }
            else
            {
                p.push_back(nums[i]);
            }

        }
        nums.clear();
        for(int i=0;i<p.size();i++)
        {
            nums.push_back(p[i]);
            nums.push_back(n[i]);
        }
        return nums;
    }
};