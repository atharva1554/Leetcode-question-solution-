#include<bits/stdc++.h>
class Solution {
public:
    int myAtoi(string s) {
      double n=s.size();
        int x=0;
        int y=0;
       
      double ans=0;
        for(double i=0;i<s.size();i++)
        {
           if(y==0 &&s[i]=='-')
           {
            x=1;
            y++;
           }
         else  if(y==0 && s[i]=='+')
           {
            x=0;
            y++;
           }
           else if(y==0 &&s[i]==' ')
           {
            ans=ans*10;
            ans=ans+0;
           }
           else if(y==0 && ( (int(s[i]))>=48 &&(int(s[i]))<=57   ))
           {
            ans=ans+(s[i]-'0');
            y++;
           }
           else if(int(s[i]<48)||int(s[i])>57)
           {
            break;
           }
           else
           {
            ans=ans*10;
            ans=ans+(s[i]-'0');
           }
           
        }
        if(x==1)
        {
            ans=ans*-1;
            if(ans<-2147483648)
            {
                ans=-2147483648;
            }
            return ans;
        }
        else
        {
            if(ans>2147483647)
            {
                ans=2147483647;
            }
            return ans;
        }
    }
};