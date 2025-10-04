//similar to LIS 
//TC=O(n^2) && SC=O(n^2){for 2D dp array}

class Solution {
public:
    int dfs(vector<vector<int>>& pairs,int i,int p,vector<vector<int>>&mem){
        int n=pairs.size();
        if(i>=n)return 0;
        int take=0;
        int p_ind=p+1;
        if(mem[i][p_ind]!=-1)return mem[i][p_ind];
        if(p==-1||pairs[p][1]<pairs[i][0]){
            take=1+dfs(pairs,i+1,i,mem);
        }
        int skip=dfs(pairs,i+1,p,mem);
        return mem[i][p_ind]= max(take,skip);

    }
    int findLongestChain(vector<vector<int>>& pairs) {
        int n=pairs.size();
        sort(pairs.begin(),pairs.end());
        vector<vector<int>>mem(n+1,vector<int>(n+1,-1));
        return dfs(pairs,0,-1,mem);
    }
};