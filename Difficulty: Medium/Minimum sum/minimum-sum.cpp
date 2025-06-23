class Solution {
  public:
    string addstring(string& num1,string& num2){
        string res;
        int carry=0;
        int n=num1.size();
        for(int i=n-1;i>=0;i--){
            int sum=(num1[i]-'0'+num2[i]-'0');
            res.push_back((sum+carry)%10+'0');
            carry=(sum+carry)/10;
        }
        if(carry)
         res.push_back('1');
        while(res.back()=='0')
         res.pop_back();
        reverse(res.begin(),res.end());
        return res;
    }
    string minSum(vector<int> &arr) {
        // code here
        sort(arr.begin(),arr.end());
        string num1="",num2="";
        int n=arr.size();
        if(n&1)
         num2.push_back('0');
        for(int i=0;i<n;i++){
            if(i&1)
             num2.push_back(arr[i]+'0');
            else
             num1.push_back(arr[i]+'0');
        }
        string res=addstring(num1,num2);
        return res;
    }
};