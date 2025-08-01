class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row( 1, 1);
        long long pre=1;
        for (int i = 1; i <= rowIndex; i++) {
            long long val=pre*(rowIndex-i+1)/i;
            row.push_back(val);
            pre = val;
        }
        return row;
    }
};