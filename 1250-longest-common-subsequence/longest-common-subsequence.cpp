class Solution {
public:

    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();

        vector<int> dp(m+1,0);

        int curr,prev;
        for(int i=1; i<=n; i++) {
            curr = 0, prev = 0;
            for(int j=1; j<=m; j++) {
                prev = curr;
                curr = dp[j];
                if(text1[i-1] == text2[j-1])
                dp[j] = 1 + prev;
                else
                dp[j] = max(dp[j],dp[j-1]);
            }
        }

        return dp[m];
    }   
};