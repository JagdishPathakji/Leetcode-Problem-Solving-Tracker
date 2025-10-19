class Solution {
public:

    struct cmp {
        // cmp(a,b) == true  → a has **lower priority** than b
        // cmp(a,b) == false → a has **higher priority** than b    
        bool operator()(const pair<int,string> &a, const pair<int,string> &b) {
            if(a.first != b.first) return a.first > b.first;   // max-heap by frequency
            return a.second < b.second;                        // tie-break: smaller lex comes first
        }
    };

    vector<string> topKFrequent(vector<string>& words, int k) {
        
        vector<string> ans;
        unordered_map<string,int> mp;

        for(int i=0; i<words.size(); i++) {
            mp[words[i]]++;
        }

        priority_queue<pair<int,string>, vector<pair<int,string>>, cmp> pq;

        for(auto it = mp.begin(); it != mp.end(); it++) {
            pq.push({it->second,it->first});

            if(pq.size() > k)
            pq.pop();
        }

        while(k--) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        reverse(ans.begin(),ans.end());
        return ans;
    }
};