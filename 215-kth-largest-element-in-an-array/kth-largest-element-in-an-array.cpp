class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {

        priority_queue<int> pq(nums.begin(),nums.end());

        int el = -1;
        while(k--) {
            el = pq.top();
            pq.pop();
        }

        return el;
    }
};