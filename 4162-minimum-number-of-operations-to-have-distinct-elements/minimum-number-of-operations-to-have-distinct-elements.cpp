class Solution {
public:
    int minOperations(vector<int>& nums) {

        if(nums.size() == 1)
        return 0;
        
        unordered_map<int,bool> mp;
        int idx = -1;
        for(int i=nums.size()-1; i>=0; i--) {
            if(mp.find(nums[i]) == mp.end()) {
                 mp[nums[i]] = true;   
            }
            else {
                idx = i;
                break;
            }
        }
        
        if(idx == -1)
        return 0;
        
        return ceil((idx+1)/3.0);
    }
};