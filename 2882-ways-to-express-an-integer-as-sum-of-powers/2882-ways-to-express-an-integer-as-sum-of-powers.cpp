class Solution {
public:
    int numberOfWays(int n, int x) {
        const int MOD = 1e9 + 7;
        vector<vector<int>> dp(n + 1, vector<int>(n + 2, 0));
        for (int j = 1; j <= n + 1; ++j)
            dp[0][j] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = n; j >= 1; --j) {
                long long power = (pow(j, x));
                dp[i][j] = dp[i][j + 1];
                if (i >= power)
                    dp[i][j] = (dp[i][j] + dp[i - power][j + 1]) % MOD;
            }
        }
        return dp[n][1];
    }
};