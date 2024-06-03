class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int>mpp;
        
        int more=0;
        for(int i=0;i<nums.size();i++)
        {
            int num=nums[i];
            more=target-nums[i];
            if(mpp.find(more)!=mpp.end())
            {
                return{mpp[more],i};
            }
            mpp[num]=i;

        }
        return {-1,-1};
    }
};