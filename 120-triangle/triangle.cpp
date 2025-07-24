class Solution {
public:

    int find(int i, int j, vector<vector<int>> &triangle, vector<vector<int>> &dp) {

        if(i >= triangle.size())
        return 0;
        if(j >= triangle[i].size())
        return 0;

        if(dp[i][j] != -1)
        return dp[i][j];

        return dp[i][j] = triangle[i][j] + min(find(i+1,j,triangle,dp),find(i+1,j+1,triangle,dp)); 
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        
        int n = triangle.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));

        for(int i=triangle.size()-1; i>=0; i--) {
            for(int j=0; j<triangle[i].size(); j++) {
                dp[i][j] = triangle[i][j] + min(dp[i+1][j],dp[i+1][j+1]);
            }
        }

        return dp[0][0];
        
    }
};