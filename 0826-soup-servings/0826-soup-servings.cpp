class Solution {
public:
    vector<vector<double>> dp;

    double func(int sA, int sB) {
        if (sA <= 0 && sB <= 0) return 0.5;
        if (sA <= 0) return 1.0;
        if (sB <= 0) return 0.0;

        if (dp[sA][sB] != -1.0) return dp[sA][sB];

        double res = 0.25 * (
            func(sA - 4, sB) +
            func(sA - 3, sB - 1) +
            func(sA - 2, sB - 2) +
            func(sA - 1, sB - 3)
        );
        dp[sA][sB] = res;
        return res;
    }

    double soupServings(int n) {
        if (n > 5000) return 1.0;

        int val = (n + 24) / 25; // number of 25-ml units
        dp.assign(val + 1, vector<double>(val + 1, -1.0));
        return func(val, val);
    }
};
