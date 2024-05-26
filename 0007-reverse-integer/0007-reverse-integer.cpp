class Solution {
public:
    int reverse(int x) {
       long int n=x;
        long int d=0;
        do{
          n=n/10;
          d++;
        }while(n!=0);
         n=x;
      long  int t=0;
      long  int y=0;
        for(int i=0;i<d;i++)
        {
          t=n%10;
          n=n/10;
          y=y+(pow(10,(d-i-1))*t);
        }
       if((pow(-2,31)<=y)&&(y<=(pow(2,31)-1)))
       {
        return y;
       }
       else
       {
        return 0;
       }
    }
};