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

    int numDistinct(string s, string t) {
        
        int n = s.size();
        int m = t.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return find(n,s,m,t,dp);
    }
};