class Solution {
public:

    void find(int i, int j, int index, vector<vector<char>> &board, string &word, vector<vector<bool>> &visited, bool &found, string &temp) {

        if(found)
        return;

        if(temp == word) {
            found = true;
            return;
        }

        if(board[i][j] == word[index]) {
        
            visited[i][j] = true;   
                    
            if(i-1 >= 0 and !visited[i-1][j] and index+1 < word.size() and board[i-1][j] == word[index+1]) {
                temp.push_back(word[index+1]);
                find(i-1,j,index+1,board,word,visited,found,temp);
                temp.pop_back();
            }
            if(j-1 >= 0 and !visited[i][j-1] and index+1 < word.size() and board[i][j-1] == word[index+1]) {
                temp.push_back(word[index+1]);
                find(i,j-1,index+1,board,word,visited,found,temp);
                temp.pop_back();
            }
            if(i+1 < board.size() and !visited[i+1][j] and index+1 < word.size() and board[i+1][j] == word[index+1]) {
                temp.push_back(word[index+1]);
                find(i+1,j,index+1,board,word,visited,found,temp);
                temp.pop_back();
            }
            if(j+1 < board[i].size() and !visited[i][j+1] and index+1 < word.size() and board[i][j+1] == word[index+1]) {
                temp.push_back(word[index+1]);
                find(i,j+1,index+1,board,word,visited,found,temp);
                temp.pop_back();
            }

            visited[i][j] = false;
                
        }
            
    }

    bool exist(vector<vector<char>>& board, string word) {
        
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n,false));
        bool found = false;
        string temp = "";

        for(int i=0; i<board.size(); i++) {
            for(int j=0; j<board[i].size(); j++) {
                if(board[i][j] == word[0]) {
                    temp.push_back(word[0]);
                    find(i,j,0,board,word,visited,found,temp);
                    temp.pop_back();
                }
            }
        }

        return found;
    }
};