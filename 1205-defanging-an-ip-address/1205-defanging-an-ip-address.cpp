class Solution {
public:
    string defangIPaddr(string address) {
        int len=address.length();
        string result="";
        for(int i=0;i<len;i++)
        {
            if(address[i]=='.')
                result=result+"[.]";
            else
                result=result+address[i];
        }
        return result;
    }
};