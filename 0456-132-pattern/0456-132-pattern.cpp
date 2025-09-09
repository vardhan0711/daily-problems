class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n=nums.size();
        int s2=INT_MIN;
        stack<int>st;
        for (int i = n - 1; i >= 0; --i) {
            // if current value is less than a known '2', we have nums[i] < nums[k] < nums[j]
            if (nums[i] < s2) return true;

            // Pop elements smaller than nums[i] and update s2 with the popped value(s).
            // These popped values are candidates for '2' (they were to the right of i and < some j).
            while (!st.empty() && nums[i] > st.top()) {
                s2 = max(s2, st.top());
                st.pop();
            }
            // Push the current number as a new candidate for '3'
            st.push(nums[i]);
        }        
        return  false;
    }
};