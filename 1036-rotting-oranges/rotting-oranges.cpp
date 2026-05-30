class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        queue<pair<int,int>> q;
        int rarr[] = {0,0,1,-1};
        int carr[] = {1,-1,0,0};

        int min = 0;
        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[i].size(); j++) {
                if(grid[i][j] == 2) {
                    q.push({i,j});                    
                }
            }
        }

        while(!q.empty()) {

            int size = q.size();
            bool infected = false;
            while(size--) {

                auto node = q.front();
                int r = node.first;
                int c = node.second;
                q.pop();

                for(int i=0; i<4; i++) {
                    int ri = rarr[i] + r;
                    int ci = carr[i] + c;

                    if(ri >= 0 && ri < grid.size() && ci >= 0 && ci < grid[r].size() && grid[ri][ci] == 1) {
                        infected = true;
                        grid[ri][ci] = 2;
                        q.push({ri,ci});
                    }
                }

            }
            
            if(infected)
            min++;
        }

        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[i].size(); j++) {
                if(grid[i][j] == 1)
                return -1;
            }
        }

        return min;
    }
};