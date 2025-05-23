class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {

        queue<pair<int,int>> q;
        for(int i=0; i<mat.size(); i++) {
            for(int j=0; j<mat[i].size(); j++) {
                if(mat[i][j] == 0)
                q.push({i,j});
                else
                mat[i][j] = INT_MAX;
            }
        }

        while(!q.empty()) {

            auto node = q.front();
            q.pop();

            int i = node.first;
            int j = node.second;

            if(i-1 >= 0 and mat[i-1][j] != 0) {
                if(mat[i-1][j] > mat[i][j] + 1) {
                    mat[i-1][j] = mat[i][j]+1;
                    q.push({i-1,j});
                }
            }
            if(i+1 < mat.size() and mat[i+1][j] != 0) {
                if(mat[i+1][j] > mat[i][j] + 1) {
                    mat[i+1][j] = mat[i][j] + 1;
                    q.push({i+1,j});
                }
            }
            if(j-1 >= 0 and mat[i][j-1] != 0) {
                if(mat[i][j-1] > mat[i][j] + 1) {
                    mat[i][j-1] = mat[i][j] + 1;
                    q.push({i,j-1});
                }
            }
            if(j+1 < mat[i].size() and mat[i][j+1] != 0) {
                if(mat[i][j+1] > mat[i][j] + 1) {
                    mat[i][j+1] = mat[i][j] + 1;
                    q.push({i,j+1});
                }
            }
        }

        return mat;
    }
};