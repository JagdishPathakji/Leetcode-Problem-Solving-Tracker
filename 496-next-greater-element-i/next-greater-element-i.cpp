class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        int n = nums1.size();
        int m = nums2.size();
        vector<int> ans(n);
        unordered_map<int,int> mp;
        stack<int> st;

        for(int i=0; i<m; i++) {

            while(!st.empty() && nums2[i] > nums2[st.top()]) {
                mp[nums2[st.top()]] = nums2[i];
                st.pop();
            }

            st.push(i);
        }

        for(int i=0; i<n; i++) {
            if(mp.find(nums1[i]) != mp.end())
            ans[i] = mp[nums1[i]];
            else
            ans[i] = -1;
        }

        return ans;
    }
};