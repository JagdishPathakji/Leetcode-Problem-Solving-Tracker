class Solution {
public:
    int edgeScore(vector<int>& edges) {
        
        map<int,long long> mp;
        for(int i=0; i<edges.size(); i++) {
            mp[edges[i]] += i;
        }

        int maxi = INT_MIN;
        int node = -1;
        for(auto it = mp.begin(); it != mp.end(); it++) {
            if(maxi < it->second) {
                node = it->first;
                maxi = it->second;
            }
        }

        return node;

    }
};