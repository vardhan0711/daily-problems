class Solution {
public:
    const int MOD=1e9+7;
    int solve(vector<vector<int>>&dp,int n,int k,int x){
        if(n==0)return 1;
        if(n<0||pow(k,x)>n)return 0;
        if(dp[n][k]!=-1)return dp[n][k];
        int pick=solve(dp,n-pow(k,x),k+1,x);
        int notPick=solve(dp,n,k+1,x);
        return dp[n][k]=(pick+notPick)%MOD;
    }
    int numberOfWays(int n, int x) {
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solve(dp,n,1,x);
    }
};