class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        
        unordered_map<int,string> mp;
        priority_queue<int> pq(score.begin(),score.end()); // O(n) time

        vector<string> ans;
        while(!pq.empty()) {
            if(mp.size() == 0) {
                mp[pq.top()] = "Gold Medal";
            }
            else if(mp.size() == 1) {
                mp[pq.top()] = "Silver Medal";
            }
            else if(mp.size() == 2) {
                mp[pq.top()] = "Bronze Medal";
            }
            else {
                mp[pq.top()] = to_string(mp.size()+1);
            }

            pq.pop();
        }

        for(int i=0; i<score.size(); i++) {
            ans.push_back(mp[score[i]]);
        }

        return ans;
    }
};