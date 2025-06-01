class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        int i = 0;
        int j = 0;

        int n = nums.size();
        vector<int> ans;
        multiset<int> st; 
        while(j < n) {

            st.insert(nums[j]);

            if(j-i+1 == k) {
                ans.push_back(*(prev(st.end())));
                st.erase(st.find(nums[i]));
                i++;
            }

            j++;
        }

        return ans;
    }
};