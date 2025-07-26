class Solution {
public:

    bool check(int i, int j, int n, int m) {
        if(i < 0 || j < 0 || i >= n || j >= m)
        return false;

        return true;
    }

    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        
        int n = board.size();
        int m = board[0].size();
        vector<vector<bool>>visited(n,vector<bool>(m,false));
    
        queue<pair<int,int>> q;
        q.push({click[0],click[1]});

        vector<int> dx = {-1,-1,-1,0,0,1,1,1};
        vector<int> dy = {-1,0,1,-1,1,-1,0,1};

        while(!q.empty()) {
            
            auto pair = q.front();
            q.pop();

            int i = pair.first;
            int j = pair.second;

            if(board[i][j] == 'M') {
                board[i][j] = 'X';
                break;
            }

            int mines = 0;
            for(int k=0; k<8; k++) {
                if(check(i+dx[k],j+dy[k],n,m) && board[i+dx[k]][j+dy[k]] == 'M') {
                    mines++;
                }
            }

            if(mines == 0) {
                board[i][j] = 'B';

                for(int k=0; k<8; k++) {
                    if(check(i+dx[k],j+dy[k],n,m) && board[i+dx[k]][j+dy[k]] == 'E') {
                        board[i+dx[k]][j+dy[k]] = 'B';
                        q.push({i+dx[k],j+dy[k]});
                    }
                }
            }
            else {
                board[i][j] = mines + '0';
            }
        }

        return board;
    }   
};