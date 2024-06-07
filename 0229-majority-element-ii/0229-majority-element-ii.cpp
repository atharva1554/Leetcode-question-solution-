class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int el1,el2,cnt1=0,cnt2=0;
        el1=INT_MIN;
        el2=INT_MIN;
        int n=nums.size();
        vector<int>a;
        for(int i=0;i<n;i++)
        {
            if(cnt1==0&&nums[i]!=el2)
            {
                cnt1=1;
                el1=nums[i];
            }
            else if(cnt2==0&&nums[i]!=el1)
            {
                cnt2=1;
                el2=nums[i];
            }
            else if(nums[i]==el1)
            {
                cnt1++;
            }
            else if(nums[i]==el2)
            {
                cnt2++;
            }
            else 
            {
                cnt1--;
                cnt2--;
            }

        }
        cnt1=0,cnt2=0;
        for(int i=0;i<n;i++)
        {
            if(el1==nums[i])
            {
                cnt1++;
            }
            if(el2==nums[i])
            {
                cnt2++;
            }
        }
        int min=int (n/3)+1;
        
        
            if(el1<el2)
            {   
                
               
              if(cnt1>=min)
                {
                     a.push_back(el1);
                }
                 if(cnt2>=min)
                {
                   a.push_back(el2);
                }
            }
            else 
            {
                 if(cnt2>=min)
                {
                   a.push_back(el2);
                }
              if(cnt1>=min)
                {
                     a.push_back(el1);
                }
               
            }
        
        return a;
    }
};