class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        int n=nums2.size();
        for(int i=0;i<nums1.size();i++)
        {
            for(int j=0;j<n;j++)
            {   int x=0;
                if(nums1[i]==nums2[j])
                {
                    for(int k=j;k<n;k++)
                    {   
                        if(nums2[k]>nums1[i])
                        {
                            ans.push_back(nums2[k]);
                            x=1;
                             break;
                        }
                        
                    }
                    if(x==0)
                    {
                        ans.push_back(-1);
                    }
                   
                   
                }
    
            }
        }
        return ans;
    } 
};