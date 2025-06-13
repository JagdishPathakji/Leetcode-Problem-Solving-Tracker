class Solution {
public:

    bool checkdiagonal(int i, int j, int n, vector<string> &board) {

        // upper left diagonal , there must be no queen
        int row = i;
        int col = j;

        while(row > -1 and col > -1) {
            if(board[row][col] == 'Q')
            return false;

            row = row - 1;
            col = col - 1;
        }

        // upper right diagonal, there must be no queen
        row = i;
        col = j;

        while(row > -1 and col < n) {
            if(board[row][col] == 'Q')
            return false;

            row = row - 1;
            col = col + 1;
        }   

        return true;
    }

    void find(int row, int n, vector<string> &board, vector<vector<string>> &ans, vector<bool> &column) {

        // base case
        if(row == n) {
            ans.push_back(board);
            return;
        }

        for(int j=0; j<n; j++) {
            if(column[j] == 0 and checkdiagonal(row,j,n,board)) {
                column[j] = 1;
                board[row][j] = 'Q';
                find(row+1,n,board,ans,column);
                board[row][j] = '.';
                column[j] = 0;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        
        vector<vector<string>> ans;
        vector<string> board(n);
        
        for(int i=0; i<n; i++)
        for(int j=0; j<n; j++) 
        board[i].push_back('.');

        // to check two queens not in same col.
        vector<bool> column(n,false);
        // for row it can be done without extra vector.
        // for diagonal we need to check manually using loop

        find(0,n,board,ans,column);

        return ans;
    }
};