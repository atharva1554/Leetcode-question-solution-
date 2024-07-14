#include<bits/stdc++.h>
class Solution {
public:
    string largestOddNumber(string num) {
        int j=-1;
        for(int i=0;i<num.size();i++)
        {  char a=num[i];
            int n=int(a-'0');
            if(n%2!=0)
            {
                j=i;
            }
        }
        cout<<j;
        if(j==-1)
        {
            return "";
        }
        return num.substr(0,1+j);
    }
};