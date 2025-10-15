class Solution {
public:
    void solve(vector<vector<char>>& board) {

        queue<pair<int,int>> q;
        int row = board.size();
        int col = board[0].size();
        
        if(row == 1 && col == 1)
        return;

        for(int i=0; i<col; i++) {
            if(board[0][i] == 'O') {
                board[0][i] = 'Y';
                q.push({0,i});
            }
            if(board[row-1][i] == 'O') {
                board[row-1][i] = 'Y';
                q.push({row-1,i});
            }
        }

        for(int j=1; j<row-1; j++) {
            if(board[j][0] == 'O') {
                q.push({j,0});
                board[j][0] = 'Y';
            }
            if(board[j][col-1] == 'O') {
                q.push({j,col-1});
                board[j][col-1] = 'Y';
            }
        }

        int x[4] = {0,0,1,-1};
        int y[4] = {1,-1,0,0};

        while(!q.empty()) {

            auto pair = q.front();
            q.pop();

            int i = pair.first;
            int j = pair.second;

            board[i][j] = 'Y';

            for(int k=0; k<4; k++) {
                if(i+x[k] < row and j+y[k] < col and i+x[k] >= 0 and j+y[k] >= 0 and board[i+x[k]][j+y[k]] == 'O') 
                q.push({i+x[k],j+y[k]});
            }
        }

        for(int i=0; i<row; i++) {
            for(int j=0; j<col; j++) {
                if(board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }

        for(int i=0; i<row; i++) {
            for(int j=0; j<col; j++) {
                if(board[i][j] == 'Y') {
                    board[i][j] = 'O';
                }
            }
        }
    }
};