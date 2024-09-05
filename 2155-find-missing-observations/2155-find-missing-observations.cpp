class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size(), sum_m = 0, sum_n = 0, total_sum = 0;
        vector<int> ans;
        for(int i=0; i<m; i++) // Calculate the sum of given m observations
            sum_m += rolls[i];
        
        total_sum = (m+n)*mean;  // Total sum is sum of roll observation for both m and n
        if(total_sum<=sum_m)    return {}; // If total_sum is smaller than any of the sum then return {}
        
        sum_n = total_sum - sum_m; //Calculate sum of n observations
        if(sum_n > (n*6) || sum_n<n)    return {}; // If sum_n is gretaer than highest possible value or lower than least possible value then return {}
        
        int rem = sum_n%n, min = sum_n/n; // Calculate the minimum distribution of value and also the remainder to be later distributed
        for(int i=0; i<n; i++){
            ans.push_back(min);
            if((rem--)>0) // As long as we have remainder left, increment values by 1
                ans[i]++;
        }
        return ans;
    }
};