class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int i = 0;
        int ind = 0;
        while (i < n) {
            char curr = chars[i];
            int cnt = 0;
            while (i < n && chars[i] == curr) {
                i++;
                cnt++;
            }

            chars[ind] = curr;
            ind++;
            if (cnt > 1) {
                string num = to_string(cnt);
                for (char ch : num) {
                    chars[ind] = ch;
                    ind++;
                }
            }
        }
        return ind;
    }
};