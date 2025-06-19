class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        
        unordered_map<int,int> mp;
        for(int i=0; i<nums.size(); i++)
        mp[nums[i]]++;

        vector<int> ans;
        for(auto it = mp.begin(); it != mp.end(); it++) {
            if(ans.size() == 2) return ans;
            else if(it->second == 1)
            ans.push_back(it->first);
        }

        return ans;
    }
};