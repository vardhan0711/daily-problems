class Solution {
public:
    vector<int> sumZero(int n) {
        if (n == 1) {
            return {0};
        }
        vector<int> res(n);
        int el = 1;
        if (n & 1 != 1) {
            for (int i = 0; i < n - 1; i += 2) {
                res[i] = el;
                res[i + 1] = -el;
                el++;
            }
            res[n - 1] = {0};
        }
        else{
            for(int i=0;i<n-1;i+=2){
                res[i]=el;
                res[i+1]=-el;
                el++;
            }
        }

        return res;
    }
};