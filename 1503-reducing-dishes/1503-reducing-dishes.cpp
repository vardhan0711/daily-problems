class Solution {
public:
    int maxSatisfaction(vector<int>& v) {
        int n = v.size();
        sort(v.begin(), v.end());
        int idx = 0;
        int prefixSum = v[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            prefixSum += v[i];
            if (prefixSum < 0) {
                idx = i + 1;
                break;
            }
        }
        if (idx == n - 1)
            return 0;
        int ans = 0;
        int count = 1;
        for (int i = idx; i < n; i++) {
            ans += count * v[i];
            count++;
        }
        return ans;
    }
};
