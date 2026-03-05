class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        
        int n = tasks.size();
        vector<vector<int>> sorted_tasks;

        for(int i=0; i<tasks.size(); i++) {
            int start_time = tasks[i][0];
            int processing_time = tasks[i][1];

            sorted_tasks.push_back({start_time,processing_time,i});
        }

        sort(begin(sorted_tasks),end(sorted_tasks));

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        long long int current_time = 0;
        int idx = 0;

        vector<int> ans;
        while(idx < n || !pq.empty()) {

            if(pq.empty() && current_time < sorted_tasks[idx][0]) {
                current_time = sorted_tasks[idx][0];
            }

            while(idx < n && current_time >= sorted_tasks[idx][0]) {
                pq.push({sorted_tasks[idx][1],sorted_tasks[idx][2]});
                idx++;
            }

            auto peek = pq.top();
            pq.pop();

            int processtime = peek.first;
            int index = peek.second;

            current_time += processtime;
            ans.push_back(index);
        }

        return ans;
    }
};