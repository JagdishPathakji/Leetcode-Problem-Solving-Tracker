class Solution {
public:
    int numEnclaves(vector<vector<int>>& board) {
        
        queue<pair<int,int>> q;
        int row = board.size();
        int col = board[0].size();
        

        for(int i=0; i<col; i++) {
            if(board[0][i] == 1) {
                board[0][i] = 2;
                q.push({0,i});
            }
            if(board[row-1][i] == 1) {
                board[row-1][i] = 2;
                q.push({row-1,i});
            }
        }

        for(int j=1; j<row-1; j++) {
            if(board[j][0] == 1) {
                board[j][0] = 2;
                q.push({j,0});
            }
            if(board[j][col-1] == 1) {
                board[j][col-1] = 2;
                q.push({j,col-1});
            }
        }

        int x[4] = {0,0,1,-1};
        int y[4] = {1,-1,0,0};

        while(!q.empty()) {

            auto pair = q.front();
            q.pop();

            int i = pair.first;
            int j = pair.second;

            for(int k=0; k<4; k++) {
                if(i+x[k] < row and j+y[k] < col and i+x[k] >= 0 and j+y[k] >= 0 and board[i+x[k]][j+y[k]] == 1) {
                    board[i+x[k]][j+y[k]] = 2;
                    q.push({i+x[k],j+y[k]});
                }
            }
        }

        int count = 0;
        for(int i=0; i<row; i++) {
            for(int j=0; j<col; j++) {
                if(board[i][j] == 1) {
                    count++;
                }
            }
        }

        return count;
    }
};