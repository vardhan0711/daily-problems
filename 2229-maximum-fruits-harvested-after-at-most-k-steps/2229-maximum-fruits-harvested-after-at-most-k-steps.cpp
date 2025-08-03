//understood the approach but unable to code properly

class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int n = fruits.size();
        vector<int> pos(n), prefix(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            pos[i] = fruits[i][0];
            prefix[i + 1] = prefix[i] + fruits[i][1];
        }
        
        int res = 0;
        // Go left then right
        for (int l = 0; l < n && pos[l] <= startPos; ++l) {
            int leftSteps = startPos - pos[l];
            if (leftSteps > k) continue;
            int remain = k - 2 * leftSteps;
            int r = upper_bound(pos.begin(), pos.end(), startPos + max(remain, 0)) - pos.begin() - 1;
            res = max(res, prefix[r + 1] - prefix[l]);
        }
        // Go right then left
        for (int r = n - 1; r >= 0 && pos[r] >= startPos; --r) {
            int rightSteps = pos[r] - startPos;
            if (rightSteps > k) continue;
            int remain = k - 2 * rightSteps;
            int l = lower_bound(pos.begin(), pos.end(), startPos - max(remain, 0)) - pos.begin();
            res = max(res, prefix[r + 1] - prefix[l]);
        }
        return res;
    }
};