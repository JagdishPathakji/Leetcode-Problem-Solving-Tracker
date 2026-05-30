class Solution {
public:
    int numEnclaves(vector<vector<int>>& board) {
        
        queue<pair<int,int>> q;
        int n = board.size();
        int m = board[0].size();

        for(int i=0; i<n; i++) {
            if(board[i][0] == 1) {
                board[i][0] = 2;
                q.push({i,0});
            }
            if(board[i][m-1] == 1) {
                board[i][m-1] = 2;
                q.push({i,m-1});
            }
        }

        for(int i=0; i<m; i++) {
            if(board[0][i] == 1) {
                board[0][i] = 2;
                q.push({0,i});
            }
            if(board[n-1][i] == 1) {
                board[n-1][i] = 2;
                q.push({n-1,i});
            }
        }

        int rarr[] = {1,-1,0,0};
        int carr[] = {0,0,1,-1};

        while(!q.empty()) {

            auto node = q.front();
            q.pop();

            int r = node.first;
            int c = node.second;

            for(int i=0; i<4; i++) {
                int newr = rarr[i] + r;
                int newc = carr[i] + c;

                if(newr >= 0 && newc >= 0 && newr < n && newc < m && board[newr][newc] == 1) {
                    board[newr][newc] = 2;
                    q.push({newr,newc});
                }
            }
        }

        int count = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(board[i][j] == 1)
                count++;
            }
        }

        return count;        
    }
};