class Solution {
public:

    void find(int i, int j, vector<vector<int>> &grid, int &countvalid, int &count, int &total) {

        if(grid[i][j] == 2) {
            if(countvalid == total) {
                count++;
            }
            return;
        }

        total++;
        grid[i][j] = -1;

        if(i-1 >= 0 and grid[i-1][j] != -1) {
            find(i-1,j,grid,countvalid,count,total);
        }
        if(j-1 >= 0 and grid[i][j-1] != -1) {
            find(i,j-1,grid,countvalid,count,total);
        }
        if(i+1 < grid.size() and grid[i+1][j] != -1) {
            find(i+1,j,grid,countvalid,count,total);
        }
        if(j+1 < grid[i].size() and grid[i][j+1] != -1) {
            find(i,j+1,grid,countvalid,count,total);
        }
    
        grid[i][j] = 1;
        total--;
    }

    int uniquePathsIII(vector<vector<int>>& grid) {
        
        int countvalid = 0;
        int start_i = -1;
        int start_j = -1;
        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[i].size(); j++) {
                if(grid[i][j] == 0 or grid[i][j] == 1)
                countvalid++;
                if(grid[i][j] == 1) {
                    start_i = i;
                    start_j = j;
                }
            }
        }

        int count = 0;
        int total = 0;
        find(start_i,start_j,grid,countvalid,count,total);

        return count;
    }
};