class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five=0;
        int ten=0;
      
      int n=bills.size();
      for(int i=0;i<n;i++)
      {
        if(bills[i]==5)
        {
            five+=1;
        }
        else if(bills[i]==10)
        {
            if(five>0)
            {
                five=five-1;
                 ten++;
            }
            else
            {  
                cout<<"due to the 10";
                return false;
                
                break;
            }
        }
        else if(bills[i]==20)
        {
            
              if(five>0&&ten>0)
             {
                five=five-1;
                ten=ten-1;
             }
             else  if(five>2)
             {
                five=five-3;
             }
             else
             {
                cout<<"due to the 20"<<endl;
                cout<<"5: "<<five<<"  10 : "<<ten;
                return false;
                break;
             }
        }
      }
      return true;
    }
};