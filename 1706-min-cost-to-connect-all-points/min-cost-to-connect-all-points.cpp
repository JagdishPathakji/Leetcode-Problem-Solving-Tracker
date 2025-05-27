class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        
        int n = points.size();
        vector<vector<pair<int,int>>> adjlist(n);

        for(int i=0; i<points.size(); i++) {
            int u = points[i][0];
            int v = points[i][1];
            for(int j=i+1; j<points.size(); j++) {
                int u1 = points[j][0];
                int v1 = points[j][1];
                int wt = abs(u1-u)+abs(v1-v);
                adjlist[i].push_back({j,wt});
                adjlist[j].push_back({i,wt});
            }
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,0});
        int cost = 0;
        vector<bool> isMST(n,false);

        while(!pq.empty()) {

            int wt = pq.top().first;
            int node = pq.top().second;

            pq.pop();

            if(isMST[node])
            continue;

            isMST[node] = 1;
            cost += wt;

            for(int i=0; i<adjlist[node].size(); i++) {
                int neigh = adjlist[node][i].first;
                int weight = adjlist[node][i].second;
                if(!isMST[neigh])
                pq.push({weight,neigh});
            }

        }

        return cost;
    }
};