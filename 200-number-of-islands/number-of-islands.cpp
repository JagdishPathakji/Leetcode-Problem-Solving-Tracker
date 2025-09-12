class Solution {
public:

    void DFS(int i, int j, vector<vector<char>> &grid) {

        grid[i][j] = -1;

        if(i+1 < grid.size() && grid[i+1][j] == '1') 
        DFS(i+1,j,grid);

        if(i-1 >= 0 and grid[i-1][j] == '1')
        DFS(i-1,j,grid);

        if(j+1 < grid[i].size() and grid[i][j+1] == '1')
        DFS(i,j+1,grid);

        if(j-1 >= 0 and grid[i][j-1] == '1')
        DFS(i,j-1,grid);
    }

    int numIslands(vector<vector<char>>& grid) {
        
        // int row = grid.size();
        // int col = grid[0].size();

        // queue<pair<int,int>> q;
        // vector<vector<bool>> visited(row, vector<bool>(col,false));

        // int noOfIslands = 0;
        // for(int i=0; i<grid.size(); i++) {
        //     for(int j=0; j<grid[i].size(); j++) {
        //         if(grid[i][j] == '1' and !visited[i][j]) {

        //             noOfIslands++;
        //             q.push({i,j});

        //             while(!q.empty()) {

        //                 auto node = q.front();
        //                 q.pop();

        //                 int i = node.first;
        //                 int j = node.second;

        //                 if(i+1 < grid.size() and !visited[i+1][j] and grid[i+1][j] == '1') {
        //                     visited[i+1][j] = 1;
        //                     q.push({i+1,j});
        //                 }

        //                 if(j+1 < grid[i].size() and !visited[i][j+1]  and grid[i][j+1] == '1') {
        //                     visited[i][j+1] = 1;
        //                     q.push({i,j+1});
        //                 }

        //                 if(i-1 >= 0 and !visited[i-1][j]  and grid[i-1][j] == '1') {
        //                     visited[i-1][j] = 1;
        //                     q.push({i-1,j});
        //                 }

        //                 if(j-1 >= 0 and !visited[i][j-1]  and grid[i][j-1] == '1') {
        //                     visited[i][j-1] = 1;
        //                     q.push({i,j-1});
        //                 }
        //             }
        //         }
        //     }
        // }

        // return noOfIslands;



        int row = grid.size();
        int col = grid[0].size();

        int noOfIslands = 0;

        for(int i=0; i<row; i++) {
            for(int j=0; j<col; j++) {
                if(grid[i][j] == '1') {
                    noOfIslands++;
                    DFS(i,j,grid);
                }
            }
        }

        return noOfIslands;
    }
};