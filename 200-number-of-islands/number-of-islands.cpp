class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        
        int count = 0;
        queue<pair<int,int>> q;

        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[i].size(); j++) {

                if(grid[i][j] == '1') {

                    grid[i][j] = '0';
                    q.push({i,j});
                    
                    while(!q.empty()) {
                        
                        auto node = q.front();
                        int r = node.first;
                        int c = node.second;
                        q.pop();

                        if(r + 1 < grid.size() && grid[r+1][c] == '1') {
                            grid[r+1][c] = '0';
                            q.push({r+1,c});
                        }

                        if(c + 1 < grid[i].size() && grid[r][c+1] == '1') {
                            grid[r][c+1] = '0';
                            q.push({r,c+1});
                        }

                        if(r - 1 >= 0 && grid[r-1][c] == '1') {
                            grid[r-1][c] = '0';
                            q.push({r-1,c});
                        }

                        if(c - 1 >= 0 && grid[r][c-1] == '1') {
                            grid[r][c-1] = '0';
                            q.push({r,c-1});
                        }
                    }

                    count++;
                }

            }
        }

        return count;
    }
};