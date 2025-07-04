class Solution {
public:
    char nextchar(char c) {
        return (c == 'z') ? 'a' : c + 1;
    }

    char kthCharacter(long long k, vector<int>& operations) {
        vector<long long> lens(operations.size() + 1, 1);
        int n = operations.size();
        // Precompute lengths after each operation (cap at k)
        for (int i = 0; i < n; ++i) {
            if (operations[i] == 0) {
                lens[i + 1] = min(lens[i] * 2, k);
            } else {
                lens[i + 1] = min(lens[i] * 2, k);
            }
        }
        char c = 'a';
        for (int i = n - 1; i >= 0; --i) {
            if (operations[i] == 0) {
                if (k > lens[i]) k -= lens[i];
            } else {
                if (k > lens[i]) {
                    k -= lens[i];
                    c = nextchar(c);
                }
            }
        }
        return c;
    }
};