class Solution {
public:
    vector<int> resultsArray(vector<vector<int>>& queries, int k) {
        
        /*
        vector<int> ans;
        priority_queue<int, vector<int>, greater<int>> pq;
        int K = k;
        for(int i = 0; i<queries.size(); i++) {
            int u = queries[i][0];
            int v = queries[i][1];

            pq.push(abs(u)+abs(v));

            if(pq.size() < k)
            ans.push_back(-1);
            else {
                priority_queue<int, vector<int>, greater<int>> temp = pq;
                while(!temp.empty() and K--) {
                    if(K == 0)
                    ans.push_back(temp.top());

                    temp.pop();
                }
                K = k;
            }
        }

        return ans;
        */

        vector<int> ans;
        priority_queue<int> pq;
        for(int i=0; i<k and i < queries.size(); i++) {
            pq.push(abs(queries[i][0]) + abs(queries[i][1]));
            if(pq.size() == k) {
                ans.push_back(pq.top());
            }
            else {
                ans.push_back(-1);
            }
        }

        for(int i=k; i<queries.size(); i++) {
            if(abs(queries[i][0])+abs(queries[i][1]) < pq.top()) {
                pq.pop();
                pq.push(abs(queries[i][0])+abs(queries[i][1]));
            }   
            ans.push_back(pq.top());
        }

        return ans;
    }
};