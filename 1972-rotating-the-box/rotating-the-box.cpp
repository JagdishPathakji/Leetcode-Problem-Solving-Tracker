class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        
        int row = boxGrid.size();
        int col = boxGrid[0].size();

        vector<vector<char>> grid(col, vector<char>(row));

        // rotate 90° clockwise
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                grid[j][row - 1 - i] = boxGrid[i][j];
            }
        }

        // main kam
        for(int i=col-2; i>=0; i--) {
            for(int j=0; j<row; j++) {
                if(grid[i][j] == '#') {
                    int k = i+1;
                    bool move = false;
                    while(k < col && grid[k][j] == '.') {
                        move = true;
                        k++;
                    }
                    grid[k-1][j] = '#';

                    if(move) {
                        grid[i][j] = '.';
                    }
                }
            }
        }

        return grid;
    }
};