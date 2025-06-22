class Solution {
public:

    int find(int i, string &s1, int j, string &s2, vector<vector<int>> &dp) {

        if(j == 0) return 1;
        if(i == 0) return 0;

        if(dp[i][j] != -1)
        return dp[i][j];

        if(s1[i-1] == s2[j-1]) {
            return dp[i][j] = find(i-1,s1,j-1,s2,dp) + find(i-1,s1,j,s2,dp);
        }
        else {
            return dp[i][j] = find(i-1,s1,j,s2,dp);
        }

    };

    int numDistinct(string s1, string s2) {
        
        int n = s1.size();
        int m = s2.size();
        vector<unsigned long long int>dp(m+1,0);
        dp[0] = 1;

        for(int i=1; i<=n; i++) {
            for(int j=m; j>=1; j--) {
                 if(s1[i-1] == s2[j-1]) {
                    dp[j] = dp[j-1] + dp[j];
                }
            }
        }

        return (int)dp[m];
    }
};