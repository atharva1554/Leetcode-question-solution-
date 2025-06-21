class Solution {
  public:
 int catchThieves(vector<char> &arr, int k) {
        // [p t t p] -> keep police and thieves seperately
        queue<int> q;
        int n = arr.size();
        // peeche m maximum and aage m minimum
        
        for (int i = 0; i < n; i++){
            if (arr[i] == 'T'){
                q.push(i);
            }
        }
        
        int count = 0;
        for (int i = 0; i < n; i++){
            if (arr[i] != 'P') continue;
            
            while (!q.empty()){
                int idx = q.front();
                
                if (idx < i && (i - idx > k)){
                    q.pop();
                }
                else if ((idx < i && (i - idx <= k)) || (idx > i && (idx - i <= k))){
                    q.pop();
                    count++;
                    break;
                }
                else{
                    break;
                }
            }
        }
        
        return count;
    }
};