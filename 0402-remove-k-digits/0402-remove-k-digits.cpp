class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        
        for (char c : num) {
            while (k > 0 && !st.empty() && st.top() > c) {
                st.pop();
                k--;
            }
            st.push(c);
        }
        
        // If k still > 0, remove from the end
        while (k > 0 && !st.empty()) {
            st.pop();
            k--;
        }
        
        // Build the result string
        string ans;
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        
        // ✅ Trim leading zeros
        int pos = 0;
        while (pos < ans.size() && ans[pos] == '0') pos++;
        ans = ans.substr(pos);
        
        // ✅ Handle empty result
        if (ans.empty()) return "0";
        
        return ans;
    }
};