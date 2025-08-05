class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int res = 0;
        int left = 0;
        int curr = 0;
        for (int right = 0; right < nums.size(); ++right) {
            while ((curr & nums[right]) != 0) {
                curr ^= nums[left];
                ++left;
            }
            curr |= nums[right];
            res = max(res, right - left + 1);
        }
        return res;
    }
};
