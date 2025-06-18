class Solution {
public:

    int find(int index1, string &text1, int index2, string &text2, vector<vector<int>> &dp) {

        if(index1 == 0 || index2 == 0)
        return 0;

        if(dp[index1][index2] != -1)
        return dp[index1][index2];

        if(text1[index1-1] == text2[index2-1])
        return dp[index1][index2] = 1 + find(index1-1,text1,index2-1,text2,dp);
        else
        return dp[index1][index2] = max(find(index1-1,text1,index2,text2,dp),find(index1,text1,index2-1,text2,dp));
    }

    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();

        vector<vector<int>>dp(n+1,vector<int>(m+1,0));

        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                if(text1[i-1] == text2[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
                else
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }

        return dp[n][m];
    }
};