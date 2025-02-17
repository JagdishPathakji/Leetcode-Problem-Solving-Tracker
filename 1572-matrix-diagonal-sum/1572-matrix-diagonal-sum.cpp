class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        
        int rows = mat.size();
        int cols = mat[0].size();
        int sum = 0;

        for(int i=0; i<rows; i++) {
            for(int j=0; j<cols; j++) {
                if(i == j) {
                    sum = sum + mat[i][j];
                }
                if(i+j == rows-1) {
                    sum = sum + mat[i][j];
                }
            }
        }

        if(rows%2 != 0)
        sum = sum - mat[rows/2][cols/2];

        return sum;

    }
};