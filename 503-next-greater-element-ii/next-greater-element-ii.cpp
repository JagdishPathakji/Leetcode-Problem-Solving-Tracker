class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> ans(n,-1);
        stack<int> st;

        int i = 0;
        int c = 0;
        
        while(c < n*2) {

            while(!st.empty() && nums[i] > nums[st.top()]) {
                ans[st.top()] = nums[i];
                st.pop();
            }

            st.push(i);
            c++;
            i = (i+1)%n;
        }

        return ans;
    }
};