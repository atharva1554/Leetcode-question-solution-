class Solution {
public:
    int missingInteger(vector<int>& nums) {
        //sort(nums.begin(),nums.end());
        int sum=nums[0];
        int ans=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i-1]+1==nums[i])
            {
                sum=sum+nums[i];
            }
            else
            { 
                sum=0;
                break;

            }
            ans=max(ans,sum);
            
        }
       int n=nums.size();
       int x=ans;
       sort(nums.begin(),nums.end());
       int i=0;
       while(i<nums.size())
       {
        if(nums[i]<x)
        {
            i++;
        }
        else if(nums[i]==x)
        {
            x++;
            i++;
        }
        else
        {
            break;
        }

       }
       return x;
    }
};