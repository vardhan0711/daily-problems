class Solution {
public:

    void dfs(vector<vector<int>>& stones,int ind,vector<bool>&vis){
        vis[ind]=true;
        for(int j=0;j<stones.size();j++){
            int r=stones[ind][0];
            int c=stones[ind][1];
            if((vis[j]==false)&&(stones[j][0]==r||stones[j][1]==c)){
                dfs(stones,j,vis);
            }
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        vector<bool>vis(n,false);
        int count=0;
        for(int i=0;i<n;i++){
            if(vis[i]==true){
                continue;
            }
            dfs(stones,i,vis);
            count++;
        }
        return n-count;
    }
};