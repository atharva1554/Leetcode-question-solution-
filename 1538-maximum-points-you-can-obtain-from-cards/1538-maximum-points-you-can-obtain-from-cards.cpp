class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int lsum=0;
        int rsum=0;
        int maxisum=0;
        int sum=0;
        for(int i=0;i<k;i++)
        {
            lsum+=cardPoints[i];
        }
        int n= cardPoints.size();
        int rightindex=n-1;
        sum=lsum+rsum;
        maxisum=max(maxisum,sum);
        for(int i=k-1;i>=0;i--)
        {
            lsum=lsum-cardPoints[i];
            rsum=rsum+cardPoints[rightindex];
            rightindex-=1;
            sum=lsum+rsum;
            maxisum=max(maxisum,sum);

        }
        return maxisum;
    }
};