class Solution {
public:
    string losingPlayer(int x, int y) {
        int cnt=0;
        int a=x;
        int b=y;
        while((a>0)&&(b>3))
        {
            a--;
            b=b-4;
            cnt++;
        }
        if(cnt%2==1)
        {
           
             return "Alice";
        }
        else
        {
            return"Bob";
        }
        
    }
};