class Solution {
public:

    vector<int> findPSE(vector<int> A) {
        stack <int> st;
        st.push(-1);
    
        vector<int> Ans(A.size());
    
        for(int i =0; i < A.size(); i++) {
        
            while(st.top() != -1 && A[st.top()] > A[i]){
                st.pop();
            }
            Ans[i] = st.top();
            st.push(i);
        }
        return Ans;
    }


    vector<int> findNSE(vector<int> A) {
        stack <int> st;
        st.push(A.size());
    
        vector<int> Ans(A.size());
    
        for(int i =A.size() - 1; i >= 0; i--) {
        
            while(st.top() != A.size() && A[st.top()] >= A[i]){
                st.pop();
            }
            Ans[i] = st.top();
            st.push(i);
        }
        return Ans;
    }

    int sumSubarrayMins(vector<int>& arr) {
        
        int n = arr.size();
        int minSum = 0;
        int MOD = int(1e9 + 7);

        vector<int> NSE = findNSE(arr);
        vector<int> PSE = findPSE(arr);

        for(int i =0; i < n; i++) {

            int left = i - PSE[i];
            int right = NSE[i] - i;
            long long tempAns = ((long long)left*right*arr[i]) % MOD;
            minSum = (minSum + (int)tempAns) % MOD;
        }
        return minSum;
    }
};