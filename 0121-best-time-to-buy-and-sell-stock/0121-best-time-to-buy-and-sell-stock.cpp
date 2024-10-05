class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini=prices[0];
        int maxi=INT_MIN;
        for(int i=0;i<prices.size();i++)
        {
            int p=prices[i]-mini;
            maxi=max(p,maxi);
            mini=min(mini,prices[i]);
        }
        return maxi;
    }
};