class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        
        int i = 0;
        int j = 0;
        int maxwindowlength = 0;

        multiset<int> s;

        while(j < nums.size()) {

            s.insert(nums[j]);

            if(abs(*s.begin()-(*prev(s.end()))) <= limit) {
                maxwindowlength = max(maxwindowlength,j-i+1);
            }
            else {
                while(abs(*s.begin()-(*prev(s.end()))) > limit) {
                    s.erase(s.find(nums[i]));
                    i++;
                }
            }

            j++;
        }

        return maxwindowlength;
    }
};