class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        
        int starti = entrance[0];
        int startj = entrance[1];

        queue<pair<int,int>> q;
        q.push({starti,startj});

        int n = maze.size();
        int m = maze[0].size();

        vector<vector<bool>> visited(n,vector<bool>(m,false));

        int step = 0;
        while(!q.empty()) {
            
            int size = q.size();
            while(size--) {

                int i = q.front().first;
                int j = q.front().second;
                q.pop();

                if(i != starti or j != startj) {
                    if(i-1 < 0 || j-1 < 0 || i+1 >= n || j+1 >= m)
                    return step;
                }

                if(i+1 < maze.size() and maze[i+1][j] != '+' and !visited[i+1][j]) {
                    q.push({i+1,j});
                    visited[i+1][j] = true;
                }
                if(i-1 >= 0 and maze[i-1][j] != '+' and !visited[i-1][j]) {
                    q.push({i-1,j});
                    visited[i-1][j] = true;
                }
                if(j+1 < maze[i].size() and maze[i][j+1] != '+' and !visited[i][j+1]) {
                    q.push({i,j+1});
                    visited[i][j+1] = true;
                }
                if(j-1 >= 0 and maze[i][j-1] != '+' and !visited[i][j-1]) {
                    visited[i][j-1] = true;
                    q.push({i,j-1});
                }
            }

            step++;
        }

        return -1;
    }
};