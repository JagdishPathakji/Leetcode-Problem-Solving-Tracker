class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        
        // flip bits of row if 1st bit of row is zero
        // flip bits of col if 1's are less than 0's

        // logic for rows
        for(int i=0; i<grid.size(); i++) {
            if(grid[i][0] == 0) {
                for(int j=0; j<grid[i].size(); j++) {
                    grid[i][j] = !grid[i][j];
                }
            }
        }

        // logic for cols
        for(int i=0; i<grid[0].size(); i++) {
            int zero=0,one=0;
            for(int j=0; j<grid.size(); j++) {
                if(grid[j][i] == 0)
                zero++;
                if(grid[j][i] == 1)
                one++;
            }

            if(zero >= one) {
                for(int j=0; j<grid.size(); j++) {
                    grid[j][i] = !grid[j][i];
                }
            }
        }

        // find number in integer and do total
        int total = 0;
        for(int i=0; i<grid.size(); i++) {
            int number = 0;
            for(int j=0; j<grid[i].size(); j++) {
                number += grid[i][j] * pow(2,grid[i].size()-j-1);
            }
            total += number;
        }

        return total;
    }
};