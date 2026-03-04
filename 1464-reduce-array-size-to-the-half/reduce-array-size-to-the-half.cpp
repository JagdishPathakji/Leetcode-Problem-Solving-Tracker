class Solution {
public:
    int minSetSize(vector<int>& arr) {
        
        unordered_map<int,int> mp;
        
        for(int i=0; i<arr.size(); i++)
        mp[arr[i]]++;

        priority_queue<int> pq;
        for(auto it = mp.begin(); it != mp.end(); it++) {
            pq.push(it->second);
        }

        int n = arr.size();
        int target = n/2;
        int ans = 0;

        while(n > target) {

            n -= pq.top();
            pq.pop();
            ans++;
        }

        return ans;
    }
};