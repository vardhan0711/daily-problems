class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        res.reserve(nums.size() / 3);  // avoid repeated reallocations

        for (int i = 0; i < nums.size(); i += 3) {
            // check we have at least 3 elements left
            if (i + 2 >= nums.size() || nums[i + 2] - nums[i] > k) {
                return {};  // can't form valid group
            }
            res.push_back({nums[i], nums[i + 1], nums[i + 2]});
        }
        return res;
    }
};
