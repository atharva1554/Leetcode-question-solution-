class Solution {
private:
    void fast(){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
public:
    int trap(vector<int>& height) {
        fast();
        stack<int> st;
        int res = 0;
        int n = height.size();
        for (int i = 0; i < n; i++) {
            while (!st.empty() && height[i] > height[st.top()]) {
                int top = st.top();
                st.pop();
                if (st.empty()) break;
                int distance = i - st.top() - 1;
                int boundedHeight = min(height[i], height[st.top()]) - height[top];
                res += distance * boundedHeight;
            }
            st.push(i);
        }
        return res;
    }
};