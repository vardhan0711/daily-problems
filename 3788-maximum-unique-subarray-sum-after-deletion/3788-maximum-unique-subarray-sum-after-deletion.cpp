class Solution {
public:
    int maxSum(vector<int>& nums) {
        unordered_set<int> st;
        int sum = 0;
        int mxNeg = INT_MIN;

        for (int num : nums) {
            if (num > 0) {
                st.insert(num);
            } else {
                mxNeg = max(mxNeg, num);
            }
        }

        for (int val : st) {
            sum += val;
        }

        if (!st.empty())
            return sum;
        else
            return mxNeg;
    }
};
