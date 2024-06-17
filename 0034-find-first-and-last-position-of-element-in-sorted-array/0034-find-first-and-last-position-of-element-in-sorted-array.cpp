class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int low=0;
        int high=nums.size()-1;
        int f=-1;
        int s=-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(nums[mid]>=target)
            {
               if(nums[mid]==target)
               {
                 f=mid;
                
               }
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        low=0;
        high=nums.size()-1;
        s=f;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(nums[mid]<=target)
            {
               if(nums[mid]==target)
               {
                 s=mid; 
               }
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }


return{f,s};
    }
};