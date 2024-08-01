class Solution {
public:
    int countSeniors(vector<string>& details) {
        int cnt=0;
        for(int i=0;i<details.size();i++)
        {
            if(int(details[i][11]-'0')>=6)
            {
               if(int(details[i][11]-'0')==6 &&int(details[i][12]-'0')==0)
               {
                continue;
               }
               else
               {
                cnt++;
               }
               
            }
        }
        return cnt;
        
    }
};