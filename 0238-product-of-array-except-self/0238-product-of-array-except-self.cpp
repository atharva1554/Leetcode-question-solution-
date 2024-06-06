class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>a;
        int mul;
      
       int d=0;
        int x;
        int y=0;
        if(nums[0]!=0)
       {
          mul=nums[0];
       }
       else
       {
        y=1;
        d=1;
        mul=nums[1];
       }
        if(d==0)
        {
            for(int i=1;i<n;i++)
        {   if(nums[i]!=0)
        {
            mul=mul*nums[i];
        }
        else
        {
            y++;
        }
        }
            
        }
        if(d==1)
        {
            for(int i=2;i<n;i++)
        {   if(nums[i]!=0)
        {
            mul=mul*nums[i];
        }
        else
        {
            y++;
        }
        }
        }
       if(y==0)
       {
         for(int i=0;i<n;i++)
        {
           if(nums[i]!=0)
           {
             x=mul/nums[i];
           }       
           else
           {
             x=mul;
           }
            a.push_back(x);
        }
       }
       else
       {
         for(int i=0;i<n;i++)
        {
           if(nums[i]!=0)
           {
             x=0;
           }       
           else
           {
             if(y<=1)
             {
                 x=mul;
             }
             else
             {
                x=0;
             }
           }
            a.push_back(x);
        }
       }
        return a;
    }
    
};