class Solution {
public:
    void solve(vector<vector<char>>& board) {
        
        int row = board.size();
        int col = board[0].size();

        queue<pair<int,int>> q;
        for(int i=0; i<col; i++) {
            if(board[0][i] == 'O')
            q.push({0,i});
            if(board[row-1][i] == 'O')
            q.push({row-1,i});
        }

        for(int i=0; i<row; i++) {
            if(board[i][0] == 'O')
            q.push({i,0});
            if(board[i][col-1] == 'O')
            q.push({i,col-1});
        }

        while(!q.empty()) {

            auto node = q.front();
            q.pop();

            int i = node.first;
            int j = node.second;

            board[i][j] = 'K';

            if(i+1 < board.size() and board[i+1][j] == 'O') {
                q.push({i+1,j});
                board[i+1][j] = 'K';
            }

            if(i-1 >= 0 and board[i-1][j] == 'O') {
                q.push({i-1,j});
                board[i-1][j] = 'K';
            }

            if(j-1 >= 0 and board[i][j-1] == 'O') {
                q.push({i,j-1});
                board[i][j-1] = 'K';
            }

            if(j+1 < board[i].size() and board[i][j+1] == 'O') {
                q.push({i,j+1});
                board[i][j+1] = 'K';
            }
        }

        for(int i=0; i<row; i++) {
            for(int j=0; j<col; j++) {
                if(board[i][j]  == 'K')
                board[i][j] = 'O';
                else if(board[i][j] == 'O')
                board[i][j] = 'X';
            }
        }
    }
};