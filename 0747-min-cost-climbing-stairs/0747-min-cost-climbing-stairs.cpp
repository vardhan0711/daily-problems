class Solution {
public:
    int recursion(vector<int>& cost,int n,int i, vector<int>&mem){
        if(i>=n)return 0;
        if(mem[i]!=-1)return mem[i];
        int one=recursion(cost,n,i+1,mem);
        int two=recursion(cost,n,i+2,mem);
        return mem[i]=cost[i]+min(one,two);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int>mem(n,-1);
        return min(recursion(cost,n,0,mem),recursion(cost,n,1,mem));
    }
};
