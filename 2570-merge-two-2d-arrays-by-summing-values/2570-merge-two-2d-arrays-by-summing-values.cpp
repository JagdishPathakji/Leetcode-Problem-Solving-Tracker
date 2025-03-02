class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        
        vector<vector<int>> ret;
        map<int,int> mp;

        for(int i=0; i<nums1.size(); i++) {
            mp.insert({nums1[i][0],nums1[i][1]});
        }

        for(int i=0; i<nums2.size(); i++) {
            auto it = mp.find(nums2[i][0]);
            if(it != mp.end()) {
                it->second = it->second + nums2[i][1];
            }
            else {
                mp.insert({nums2[i][0],nums2[i][1]});
            }
        }

        for(auto it : mp) {
            ret.push_back({it.first,it.second});
        }

        return ret;
    }
};