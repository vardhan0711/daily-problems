//LIS + BS

class Solution {
public:
    static bool comp(const vector<int> &a, const vector<int> &b){
        if (a[0] == b[0]) return a[1] > b[1]; // same width -> larger height first
        return a[0] < b[0];
    }

    int maxEnvelopes(vector<vector<int>>& envelopes) {
        if (envelopes.empty()) return 0;
        sort(envelopes.begin(), envelopes.end(), comp);

        // extract heights
        vector<int> tails; // tails[k] = smallest possible tail value of an increasing subseq of length k+1
        for (auto &e : envelopes) {
            int h = e[1];
            auto it = lower_bound(tails.begin(), tails.end(), h);
            if (it == tails.end()) tails.push_back(h);
            else *it = h;
        }
        return (int)tails.size();
    }
};
