class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        
        int r = grid.size();
        int c = grid[0].size();
        
        // Here, we cannot covert that O's which are at boundary to X's.
        // Thus we will do boundary traversal, find out O's and then apply bfs from that 
        // and convert it to T.
        // Now after that whichever O's are remaining can be converted to X's so do that
        // and convert the T's to O's and return the answer.
        
        // simply push all those elements for which bfs is required into the queue.
        
        queue<pair<int,int>> q;
        // first row
        for(int i=0; i<c; i++) {
            if(grid[0][i] == 1)
            q.push({0,i});
        }
        // first col
        for(int i=0; i<r; i++) {
            if(grid[i][0] == 1)
            q.push({i,0});
        }
        // last row
        for(int i=0; i<c; i++) {
            if(grid[r-1][i] == 1)
            q.push({r-1,i});
        }
        // last col
        for(int i=0; i<r; i++) {
            if(grid[i][c-1] == 1)
            q.push({i,c-1});
        }
        
        while(!q.empty()) {
            
            auto node = q.front();
            q.pop();
            
            int i = node.first;
            int j = node.second;
            
            grid[i][j] = 2;
            
            if(i+1 < grid.size() and grid[i+1][j] == 1) {
                q.push({i+1,j});
                grid[i+1][j] = 2;
            }
            if(j+1 < grid[i].size() and grid[i][j+1] == 1) {
                q.push({i,j+1});
                grid[i][j+1] = 2;
            }
            if(i-1 >= 0 and grid[i-1][j] == 1) {
                q.push({i-1,j});
                grid[i-1][j] = 2;
            }
            if(j-1 >= 0 and grid[i][j-1] == 1) {
                q.push({i,j-1});
                grid[i][j-1] = 2;
            }
        }
        
        int count = 0;
        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[i].size(); j++) {
                if(grid[i][j] == 1)
                count++;
            }
        }

        return count;
    }
};