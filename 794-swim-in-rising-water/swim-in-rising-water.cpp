class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> distance(n, vector<int>(m,INT_MAX));
        vector<vector<bool>> explored(n, vector<bool>(m,false));
        
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        pq.push({grid[0][0],{0,0}});
        distance[0][0] = 0;

        while(!pq.empty()) {

            int wt = pq.top().first;
            int i = pq.top().second.first;
            int j = pq.top().second.second;

            pq.pop();
            
            if(explored[i][j])
            continue;

            explored[i][j] = 1;

            if(i+1 < grid.size() and distance[i+1][j] > max(grid[i+1][j],wt)) {
                distance[i+1][j] = max(grid[i+1][j],wt);
                pq.push({distance[i+1][j],{i+1,j}});
            }
            if(i-1 >= 0 and distance[i-1][j] > max(grid[i-1][j],wt)) {
                distance[i-1][j] = max(grid[i-1][j],wt);
                pq.push({distance[i-1][j],{i-1,j}});
            }
            if(j-1 >= 0 and distance[i][j-1] > max(grid[i][j-1],wt)) {
                distance[i][j-1] = max(grid[i][j-1],wt);
                pq.push({distance[i][j-1],{i,j-1}});
            }
            if(j+1 < grid[i].size() and distance[i][j+1] > max(grid[i][j+1],wt)) {
                distance[i][j+1] = max(grid[i][j+1],wt);
                pq.push({distance[i][j+1],{i,j+1}});
            }

        }

        return distance[n-1][m-1];
    }
};