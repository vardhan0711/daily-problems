class Solution {
public:
    void backtrack(int start, vector<int>& candidates, int target, vector<int>& curr, vector<vector<int>>& res) {
        if (target == 0) {
            res.push_back(curr);
            return;
        }
        if (target < 0) return;

        for (int i = start; i < candidates.size(); i++) {
            curr.push_back(candidates[i]);
            backtrack(i, candidates, target - candidates[i], curr, res); // reuse allowed
            curr.pop_back(); // backtrack
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> curr;
        backtrack(0, candidates, target, curr, res);
        return res;
    }
};