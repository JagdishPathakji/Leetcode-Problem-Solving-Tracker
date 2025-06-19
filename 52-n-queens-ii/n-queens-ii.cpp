class Solution {
public:

    
        void find(int row, int n, vector<string> &board, set<vector<string>> &ans, vector<bool> &column, vector<bool> &leftdiagonal, vector<bool> &rightdiagonal) {

            // base case
            if(row == n) {
                ans.insert(board);
                return;
            }

            for(int j=0; j<n; j++) {
                if(column[j] == 0 and leftdiagonal[(n-1)+(j-row)] == 0 and rightdiagonal[row+j] == 0) {
                    column[j] = 1;
                    board[row][j] = 'Q';
                    leftdiagonal[(n-1)+(j-row)] = 1;
                    rightdiagonal[row+j] = 1;
                    find(row+1,n,board,ans,column,leftdiagonal,rightdiagonal);
                    board[row][j] = '.';
                    column[j] = 0;
                    leftdiagonal[(n-1)+(j-row)] = 0;
                    rightdiagonal[row+j] = 0;
                }
            }
        }

    

    int totalNQueens(int n) {
        
            set<vector<string>> ans;
            vector<string> board(n);
            
            for(int i=0; i<n; i++)
            for(int j=0; j<n; j++) 
            board[i].push_back('.');

            // to check two queens not in same col.
            // for row it can be done without extra vector.
            vector<bool> column(n,false);
            vector<bool> leftdiagonal(2*n-1,false);
            vector<bool> rightdiagonal(2*n-1,false);

            find(0,n,board,ans,column,leftdiagonal,rightdiagonal);

            return ans.size();    
    }
};