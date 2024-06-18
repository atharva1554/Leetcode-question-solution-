class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int value=0;
       
        for(int i=0;i<worker.size();i++)
        {    int m=0;
            for(int j=0;j<difficulty.size();j++)
            {
                if(worker[i]>=difficulty[j])
                {
                    m=max(m,profit[j]);
                }
            }
            value=value+m;
        }
        return value;
    }
};