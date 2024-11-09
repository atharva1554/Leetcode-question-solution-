class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int>l;
        vector<int>r;
        int ans=0;
        l.push_back(1);
        r.push_back(1);
        for(int i=1;i<ratings.size();i++)
        {
            if(ratings[i]>ratings[i-1])
            {
                l.push_back(l.back()+1);
            }
            else
            {
                l.push_back(1);
            }
        }
        for(int i=ratings.size()-2;i>=0;i--)
        {
            if(ratings[i]>ratings[i+1])
            {
                r.push_back(r.back()+1);
            }
            else
            {
                r.push_back(1);
            }
        }
        reverse(l.begin(),l.end());
        for(int i=0;i<l.size();i++)
        {
            ans=ans+max(r[i],l[i]);
        }
        return ans;
    }
};