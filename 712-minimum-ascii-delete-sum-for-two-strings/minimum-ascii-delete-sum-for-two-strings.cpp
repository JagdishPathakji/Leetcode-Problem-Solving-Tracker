class Solution {
public:
    string s1, s2;
    vector<vector<int>> memo;

    int dp(int i, int j) {
        if (i == s1.size()) {
            int sum = 0;
            for (int k = j; k < s2.size(); k++) sum += s2[k];
            return sum;
        }
        if (j == s2.size()) {
            int sum = 0;
            for (int k = i; k < s1.size(); k++) sum += s1[k];
            return sum;
        }

        if (memo[i][j] != -1) return memo[i][j];

        if (s1[i] == s2[j]) {
            memo[i][j] = dp(i + 1, j + 1);
        } else {
            memo[i][j] = min(
                s1[i] + dp(i + 1, j),
                s2[j] + dp(i, j + 1)
            );
        }
        return memo[i][j];
    }

    int minimumDeleteSum(string str1, string str2) {
        s1 = str1;
        s2 = str2;
        memo.assign(s1.size(), vector<int>(s2.size(), -1));
        return dp(0, 0);
    }
};
