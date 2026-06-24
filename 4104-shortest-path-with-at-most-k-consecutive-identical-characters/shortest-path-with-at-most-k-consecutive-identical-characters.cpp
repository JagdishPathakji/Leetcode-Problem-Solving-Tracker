class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {

        vector<vector<vector<int>>> adj(n);
        for(int i=0; i<edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];

            adj[u].push_back({v,w});
        }

        vector<vector<long long>> distance(n, vector<long long>(k+1,1e18));
        distance[0][1] = 0;

        priority_queue<pair<long long,pair<long long,long long>>, vector<pair<long long,pair<long long,long long>>>, greater<pair<long long,pair<long long,long long>>>> pq;
        pq.push({0,{0,1}});

        while(!pq.empty()) {

            auto node = pq.top();
            pq.pop();

            long long wt = node.first;
            long long u = node.second.first;
            long long c = node.second.second;
            
            if(wt > distance[u][c]) continue;

            if(u == n-1) return wt;

            for(int i=0; i<adj[u].size(); i++) {
                long long v = adj[u][i][0];
                long long w = adj[u][i][1];
                char ch = labels[v];
                long long newC = c;

                if(labels[u] == labels[v])
                newC = c+1;
                else
                newC = 1;
                
                if(newC <= k && (wt + w) < distance[v][newC]) {
                    pq.push({w+wt,{v,newC}});
                    distance[v][newC] = wt + w;
                }
            }

        }

        return -1;
    }
};