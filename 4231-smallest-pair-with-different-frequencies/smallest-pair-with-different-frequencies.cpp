class Solution {
public:
    vector<int> minDistinctFreqPair(vector<int>& nums) {
        
        int x = INT_MAX;
        int y = INT_MAX;

        unordered_map<int,int> mp;
        for(int i=0; i<nums.size(); i++) {
            mp[nums[i]]++;
        }

        for(auto it = mp.begin(); it != mp.end(); it++) {
            for(auto it1 = mp.begin(); it1 != mp.end(); it1++) {
                if(it != it1) {
                    if(it->second != it1->second) {
                        if(it->first < it1->first) {
                            x = min(x,it->first);
                            y = min(y,it1->first);
                        }
                    }
                }
            }
        }

        if(x == INT_MAX && y == INT_MAX)
        return {-1,-1};

        return {x,y};
    }
};