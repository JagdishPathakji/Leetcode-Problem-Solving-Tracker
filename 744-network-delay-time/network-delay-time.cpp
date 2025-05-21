class Solution {
public:

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        vector<vector<pair<int,int>>> adjlist(n+1);
        for(int i=0; i<times.size(); i++) {
            int u = times[i][0];
            int v = times[i][1];
            int w = times[i][2];

            adjlist[u].push_back({v,w});
        }

        vector<bool> explored(n+1,false);
        vector<int> distance(n+1,INT_MAX);

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,k});
        distance[k] = 0;

        while(!pq.empty()) {

            int node = pq.top().second;
            int w = pq.top().first;

            pq.pop();

            if(explored[node])
            continue;

            explored[node] = 1;

            for(int i=0; i<adjlist[node].size(); i++) {
                int neigh = adjlist[node][i].first;
                int weight = adjlist[node][i].second;

                if(!explored[neigh] and distance[neigh] > w + weight) {
                    distance[neigh] = w + weight;
                    pq.push({distance[neigh],neigh});
                }
            }
        }

        int max = INT_MIN;
        for(int i=1; i<=n; i++) {
            if(distance[i] == INT_MAX)
            return -1;
            if(max < distance[i])
            max = distance[i];
        }

        return max;
    }
};