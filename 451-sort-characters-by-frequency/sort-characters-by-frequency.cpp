class Solution {
public:
    string frequencySort(string s) {
        
        string ans;
        unordered_map<char,int> mp;

        for(int i=0; i<s.size(); i++)
        mp[s[i]]++;

        priority_queue<pair<int,char>> pq;

        for(auto it = mp.begin(); it != mp.end(); it++) {
            pq.push({it->second,it->first});
        }

        while(!pq.empty()) {
            
            int occurance = pq.top().first;
            char c = pq.top().second;

            while(occurance--) 
            ans += c;

            pq.pop();
        }

        return ans;
    }
};