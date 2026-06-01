class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        
        // we need multisource shortest path algorithm over here
        // we need to apply flyod warshall algorithm for this

        vector<vector<int>> distance(n, vector<int> (n,INT_MAX));

        for(int i=0; i<edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];

            distance[u][v] = w;
            distance[v][u] = w;
        }
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(i == j)
                distance[i][j] = 0;
            }
        }

        for(int k=0; k<n; k++) {
            for(int i=0; i<n; i++) {
                for(int j=0; j<n; j++) {
                    if(distance[i][k] == INT_MAX || distance[k][j] == INT_MAX)
                    continue;
                    distance[i][j] = min(distance[i][j],distance[i][k] + distance[k][j]);
                }
            }
        }

        vector<int> number(n);
        int minicount = INT_MAX;
        for(int i=0; i<n; i++) {
            int count = 0;
            for(int j=0; j<n; j++) {
                if(distance[i][j] <= distanceThreshold && i != j) {
                    count++;
                }
            }
            number[i] = count;
            minicount = min(minicount,count);
        }

        for(int i=n-1; i>=0; i--) {
            if(number[i] == minicount)
            return i;
        }

        return -1;
    }
};