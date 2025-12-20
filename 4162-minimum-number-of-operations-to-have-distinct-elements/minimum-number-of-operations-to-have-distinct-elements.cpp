class Solution {
public:
    int minOperations(vector<int>& nums) {
        
        unordered_map<int,bool> mp;
        int idx = 0;
        for(int i=nums.size()-1; i>=0; i--) {
            if(!mp.count(nums[i])) {
                 mp[nums[i]] = true;   
            }
            else {
                idx = i;
                return ceil((idx+1)/3.0);
            }
        }

        return idx;
    }
};