class Solution {
public:
        struct Data {
        int value;
        int arr_No;
        int ind_No;
        Data(int v1, int v2, int v3) : value(v1), arr_No(v2), ind_No(v3) {}
    };

    struct Compare {
        bool operator()(Data lhs, Data rhs) {
            return lhs.value > rhs.value;
        }
    };
    vector<int> smallestRange(vector<vector<int>>&arr) 
    {
        int rows=arr.size();
        int cols=arr[0].size();
        priority_queue<Data, vector<Data>, Compare> pq;
        //store the first k elements in the pq ie the id 0 if each array
        int max_ele=INT_MIN;
        int min_ele=INT_MAX;
        for(int i=0;i<rows;i++)
        {
            Data d1(arr[i][0],i,0);
            pq.push(d1);
            max_ele=max(max_ele,arr[i][0]);
            min_ele=min(min_ele,arr[i][0]);
        }
        int range_start=min_ele;
        int range_end=max_ele;
        int min_range=max_ele-min_ele;//initial range
        while(true)
        {
            int arr_ind=pq.top().arr_No;
            int next_ind=pq.top().ind_No+1;
            pq.pop();
            if(next_ind==arr[arr_ind].size())//max_size reached
                break;
            int next_val=arr[arr_ind][next_ind];//next element in the array
            max_ele=max(max_ele,next_val);//update max
            Data d(next_val,arr_ind,next_ind);//push the data in the queue
            pq.push(d);
            int new_min_ele=pq.top().value;//new min value
            int range=max_ele-new_min_ele;
            if(range<min_range)//update the range start and range end
            {
                range_start=new_min_ele;
                range_end=max_ele;
                min_range=range;
            }
        }
        vector<int>ans;
        ans.push_back(range_start);
        ans.push_back(range_end);
        return ans;

    }
};