class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int maxDiag=0;
        int maxArea=0;
        for(auto &it:dimensions){
            int l=it[0];
            int w=it[1];
            int diag=l*l+w*w;
            int area=l*w;
            if(diag>maxDiag){
                maxDiag=diag;
                maxArea=l*w;
            }
            else if(
                diag==maxDiag
            ){
                maxArea=max(area,maxArea);
            }
        }
        return maxArea;
    }
};