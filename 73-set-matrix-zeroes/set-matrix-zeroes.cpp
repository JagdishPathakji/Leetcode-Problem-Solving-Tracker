class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        int r = matrix.size();
        int c = matrix[0].size();

        vector<bool> rows(r,false);
        vector<bool> cols(c,false);

        for(int i=0; i<r; i++) {
            for(int j=0; j<c; j++) {
                if(matrix[i][j] == 0) {
                    rows[i] = true;
                    cols[j] = true;
                }
            }
        }

        for(int i=0; i<r; i++) {
            for(int j=0; j<c; j++) {
                if(rows[i]) {
                    matrix[i][j] = 0;
                }
                else if(cols[j]) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};