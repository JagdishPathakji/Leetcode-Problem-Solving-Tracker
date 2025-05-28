class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        
        long long ans = 0;

        priority_queue<int> pq(gifts.begin(),gifts.end());
        while(k-- and !pq.empty()) {
            int val = pq.top();
            pq.pop();
            pq.push(floor(sqrt(val)));
        }

        while(!pq.empty()) {
            ans += pq.top();
            pq.pop();
        }

        return ans;
    }
};