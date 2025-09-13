class Solution {
public:
    int recursion(int i,vector<vector<int>>&dp,int amount,vector<int>& coins){
        if(i==0){
            return (amount%coins[0]==0);

        }
        if (dp[i][amount] != -1) return dp[i][amount];
        int take=0;
        int notTake=recursion(i-1,dp,amount,coins);
        if(amount>=coins[i])take=recursion(i,dp,amount-coins[i],coins);
        return dp[i][amount]=take+notTake;
    }

    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return recursion(n-1,dp,amount,coins);
    }
};