class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        int n = grid.size();
        if(grid[0][0] == 1 || grid[n-1][n-1] == 1)
        return -1;

        queue<pair<int,int>> q;
        q.push({0,0});

        int count = 0;

        int rarr[] = {0,0,-1,-1,-1,1,1,1};
        int carr[] = {-1,1,-1,0,1,-1,0,1};

        vector<vector<bool>> visited(n, vector<bool> (n,false));
        visited[0][0] = true;

        while(!q.empty()) {

            count++;
            int size = q.size();
            
            while(size--) {

                auto node = q.front();
                q.pop();

                int r = node.first;
                int c = node.second;

                if(r == n-1 && c == n-1)
                return count;

                for(int i=0; i<8; i++) {
                    int newr = r + rarr[i];
                    int newc = c + carr[i];

                    if(newr >= 0 && newc >= 0 && newr < n && newc < n && grid[newr][newc] == 0 && visited[newr][newc] == false) {
                        visited[newr][newc] = true;
                        q.push({newr,newc});
                    }
                }
            }
        }
        
        return -1;
    }
};