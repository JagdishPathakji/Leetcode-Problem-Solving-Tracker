class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
        
        vector<vector<int>> ret;
        map<int,int> mp;

        for(int i=0; i<items1.size(); i++) {
            mp.insert({items1[i][0],items1[i][1]});
        }

        for(int i=0; i<items2.size(); i++) {
           auto it = mp.find(items2[i][0]);
            if(it != mp.end()) {
                it->second = it->second + items2[i][1];
            }
            else {
                mp.insert({items2[i][0],items2[i][1]});
            }
        }

        for(auto it : mp) {
            ret.push_back({it.first,it.second});
        }

        return ret;
    }
};