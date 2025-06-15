class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        
        queue<int> q;
        int flips = 0;

        for(int i=0; i<nums.size(); i++) {

            if(!q.empty() and q.front() < i) {
                q.pop();
            }

            int size = q.size();
            if(size%2 == 0) {
                if(nums[i] == 0) {
                    if(i+k-1 >= nums.size()) return -1;
                    q.push(i+k-1);
                    flips++;
                }
            }
            else {
                nums[i] = !nums[i];
                if(nums[i] == 0) {
                    if(i+k-1 >= nums.size()) return -1;
                    q.push(i+k-1);
                    flips++;
                }
            }
            
        }

        return flips;
    }
};