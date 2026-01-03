class Solution {
public:

    int M = 1e9 + 7;
    vector<string> ways = {
        "RYG","RGY","GYR","GRY","YGR","YRG", // all distinct
        "RGR","RYR","YRY","YGY","GYG","GRG"  // ABA patterns
    };

    vector<vector<int>> dp;

    int solve(int n, int prev) {

        // we found a way to paint entire matrix
        if(n == 0) 
        return 1;

        if(dp[n][prev] != -1)
        return dp[n][prev];

        int result = 0;
        for(int i=0; i<12; i++) {
            string prevpattern = ways[prev];
            string currpattern = ways[i];

            bool matches = false;
            for(int i=0; i<3; i++) {
                if(prevpattern[i] == currpattern[i]) {
                    matches = true;
                    break;
                }
            }

            if(!matches) {
                result = (result + solve(n-1,i)) % M;
            }
        }

        return dp[n][prev] = result;
    }

    int numOfWays(int n) {
        
        dp.resize(n, vector<int>(12,-1));
        int result = 0;
        // selecting first rows
        for(int i=0; i<12; i++) {
            // now using this first row, try to find out all possible and valid second row
            // continue this process till nth row, if we reach nth row, we get 1 way to paint the entire matrix of n x 3 size.
            result = (result+solve(n-1,i))%M;
        }

        return result;
    }
};