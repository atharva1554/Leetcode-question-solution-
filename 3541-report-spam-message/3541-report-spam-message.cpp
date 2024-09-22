class Solution {
public:
    bool reportSpam(vector<string>& message, vector<string>& bannedWords) {
        int cnt=0;
        map<string,int>mpp;
        
            for(int j=0;j<bannedWords.size();j++)
            { 
              mpp[bannedWords[j]]++;
            }
            for(int i=0;i<message.size();i++)
            {
                if(mpp[message[i]]==0)
                {
                    continue;
                }
                else
                {
                    cnt++;
                }
            }
        
        if(cnt>1)
        {
            return true;
        }
        return false;
    }
};