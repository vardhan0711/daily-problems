//dfs is best because of easier code and small gird size so it will require small 
//recursion stack space 
//TC->O(N*M) AND SC->O(N*M){recursion stack space}

class Solution {
public:
    int dfs(vector<vector<int>>& grid,int r,int c){
        int n=grid.size();
        int m=grid[0].size();
        if(r<0||r>=n||c<0||c>=m||grid[r][c]==0){
            return 0;
        }    
        grid[r][c]=0;
        int currArea=1;
        int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for(int i=0;i<4;i++){
            currArea+=dfs(grid,r+dirs[i][0],c+dirs[i][1]);
        }
        return currArea;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int area=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    area=max(area,dfs(grid,i,j));
                }
            }
        }
        return area;
    }
};
