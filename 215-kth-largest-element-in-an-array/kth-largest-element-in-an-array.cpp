class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        priority_queue<int> pq(nums.begin(),nums.end());

        while(k-- and !pq.empty()) {
            if(k == 0)
            return pq.top();

            pq.pop();
        }

        return -1;
    }
};