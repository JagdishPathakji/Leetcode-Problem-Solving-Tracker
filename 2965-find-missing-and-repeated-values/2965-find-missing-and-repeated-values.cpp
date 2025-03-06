class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {

        int n = grid.size()*grid.size();
        vector<bool> v(n+1,false);

        int count = 1;
        int a;
        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[0].size(); j++) {
                if(v[grid[i][j]] == false)
                v[grid[i][j]] = true;
                else 
                a = grid[i][j];
            }
        }

        int b;
        for(int i=1; i<v.size(); i++) {
            if(v[i] == false) {
                b = i;
            }
        }

        return {a,b};

    }
};