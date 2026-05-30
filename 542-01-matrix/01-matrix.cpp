class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {

        vector<vector<int>> ans(mat.size(), vector<int>(mat[0].size()));
        queue<pair<int,int>> q;

        for(int i=0; i<mat.size(); i++) {
            for(int j=0; j<mat[i].size(); j++) {
                if(mat[i][j] == 0) {
                    q.push({i,j});
                    ans[i][j] = 0;
                }
            }
        }

        int rarr[] = {0,0,1,-1};
        int carr[] = {1,-1,0,0};


        int target = 1;
        while(!q.empty()) {

            int size = q.size();
            while(size--) {

                auto node = q.front();
                q.pop();
                int r = node.first;
                int c = node.second;

                for(int i=0; i<4; i++) {
                    int newr = rarr[i] + r;
                    int newc = carr[i] + c;

                    if(newr >= 0 && newc >= 0 && newr < mat.size() && newc < mat[r].size() && mat[newr][newc] == 1) {
                        mat[newr][newc] = 0;
                        ans[newr][newc] = target;
                        q.push({newr,newc});
                    }
                }
            }

            target++;
        }

        return ans;
    }
};