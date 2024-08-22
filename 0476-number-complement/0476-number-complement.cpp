class Solution {
public:
    vector<int> binary(int a)
    {
        vector<int>ans;
        int x=a;
        while(x>0)
        {
            ans.push_back(x%2);
            x=x/2;
        }
        reverse(ans.begin(),ans.end());
        cout<<a<<endl;
        for(int i=0;i<ans.size();i++)
        {
            cout<<ans[i]<<" ";
        }
        cout<<endl;
        return ans;
    }
   long long int binarytodecimal(vector<int>binary)
    {
        reverse(binary.begin(),binary.end());
        long long int ans=0;
      long long int  x=1;
        for(int i=0;i<binary.size();i++)
        {
           
            ans+=(x*binary[i]);
            
            x*=2;
        }
        return ans;
    }
    int findComplement(int num) {
        vector<int>a=binary(num);
        for(int i=0;i<a.size();i++)
        {
            if(a[i]==1)
            {
                a[i]=0;
            }
            else
            {
                a[i]=1;
            }
        }
            return binarytodecimal(a);
    }
};