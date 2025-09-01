class Solution {
public:
    int t[2001][2001];
    bool pal[2001][2001];  // store palindrome info

    void precomputePalindrome(const string &s) {
        int n = s.size();
        for (int i = 0; i < n; i++) pal[i][i] = true; // single chars
        for (int i = 0; i + 1 < n; i++) pal[i][i + 1] = (s[i] == s[i + 1]); // length 2

        for (int len = 3; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;
                pal[i][j] = (s[i] == s[j]) && pal[i + 1][j - 1];
            }
        }
    }

    int solve(const string &s, int i, int j) {
        if (pal[i][j]) return 0;  // already palindrome
        if (t[i][j] != -1) return t[i][j];

        int res = INT_MAX;
        for (int k = i; k < j; k++) {
            if (pal[i][k]) { // only cut if left side is palindrome
                res = min(res, 1 + solve(s, k + 1, j));
            }
        }
        return t[i][j] = res;
    }

    int minCut(string s) {
        int n = s.size();
        memset(t, -1, sizeof(t));
        memset(pal, 0, sizeof(pal));
        precomputePalindrome(s);
        return solve(s, 0, n - 1);
    }
};
