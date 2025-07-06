class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges) {

        if(edges.size() == 0 and n == 1) {
            return 0;
        }
        if(edges.size() == 0) {
            return -1;
        }
        
        vector<vector<pair<int,pair<int,int>>>> adjlist(n);
        
        for(int i=0; i<edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int s = edges[i][2];
            int e = edges[i][3];

            adjlist[u].push_back({v,{s,e}});
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
        vector<int> minTime(n,INT_MAX);
        minTime[0] = 0;
        q.push({0,0});

        while(!q.empty()) {

            int time = q.top().first;
            int node = q.top().second;
            q.pop();

            if(node == n-1) {
                return time;
            }

            // skip if node is already found to reduce time complexity
            if(time > minTime[node]) {
                continue;
            }
            
            for(int i=0; i<adjlist[node].size(); i++) {
                int v = adjlist[node][i].first;
                int start = adjlist[node][i].second.first;
                int end = adjlist[node][i].second.second;

                // condition not satisfied to move ahead
                if(time > end) continue;
                
                int nextTime = max(time,start) + 1;
                if(nextTime < minTime[v]) {
                    minTime[v] = nextTime;
                    q.push({nextTime,v});
                }
            }
            
        }

        return -1;
    }
};