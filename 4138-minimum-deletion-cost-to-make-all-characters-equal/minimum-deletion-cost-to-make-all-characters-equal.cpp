class Solution {
public:
    long long minCost(string s, vector<int>& cost) {
        
        unordered_map<char,long long> mp;

        long long maxi = INT_MIN;
        long long total = 0;
        for(int i=0; i<s.size(); i++) {
            mp[s[i]] += cost[i];
            maxi = max(maxi,mp[s[i]]);
            total += cost[i];
        }

        return total-maxi;
    }
};