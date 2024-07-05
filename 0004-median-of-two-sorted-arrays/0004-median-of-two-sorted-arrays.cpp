class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size();
        int n=nums2.size();
        if(m>=n)
        {
            for(int i=0;i<n;i++)
            {
                nums1.push_back(nums2[i]);
            }
            sort(nums1.begin(),nums1.end());
            if((m+n)%2!=0)
            {
                   return (float )nums1[(m+n)/2];
            }
            else
            {
                return (float )(nums1[(m+n-1)/2]+nums1[(m+n+1)/2])/2;
            }
           
        }
        else
        {
            for(int i=0;i<m;i++)
            {
                nums2.push_back(nums1[i]);
            }

              sort(nums2.begin(),nums2.end());
             if((m+n)%2!=0)
            {
                   return(float ) nums2[(m+n)/2];
            }
            else
            {
                return (float )(nums2[(m+n-1)/2]+nums2[(m+n+1)/2])/2;
            }
        }
        
        return 0;
    }
};