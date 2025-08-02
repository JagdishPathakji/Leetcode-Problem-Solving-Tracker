class Solution {
public:

    bool check(int i, int j, int n, int m) {
        if(i < 0 || j < 0 || i >= n || j >= m)
        return false;

        return true;
    }

    bool containsCycle(vector<vector<char>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> visited(n,vector<bool>(m,false));
        vector<int> dx = {0,0,-1,1};
        vector<int> dy = {-1,1,0,0};

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(!visited[i][j]) {
                    queue<pair<pair<int,int>,pair<int,int>>> q;
                    q.push({{i,j},{-1,-1}});

                    while(!q.empty()) {

                        int row = q.front().first.first;
                        int col = q.front().first.second;

                        int prev_row = q.front().second.first;
                        int prev_col = q.front().second.second;

                        q.pop();
                        visited[row][col] = true;

                        for(int k=0; k<4; k++) {
                            int new_row = dx[k] + row;
                            int new_col = dy[k] + col;

                            if(new_row != prev_row or new_col != prev_col) {
                                if(check(new_row,new_col,n,m) and !visited[new_row][new_col] and grid[row][col] == grid[new_row][new_col]) {
                                    visited[new_row][new_col] = true;
                                    q.push({{new_row,new_col},{row,col}});
                                }
                                else if(check(new_row,new_col,n,m) and grid[row][col] == grid[new_row][new_col] and visited[new_row][new_col]) {
                                    return true;
                                }
                            }
                        }
                    }
                }
            }
        }

        return false;
    }
};