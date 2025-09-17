class Solution {
public:
    void change(vector<vector<char>>& board,int i,int j){
        int n=board.size();
        int m=board[0].size();
        if(i<0||i>=n||j<0||j>=m||board[i][j]!='O'){
            return ;
        }
        board[i][j]='A';
        change(board,i+1,j);
        change(board,i-1,j);
        change(board,i,j+1);
        change(board,i,j-1);
    }
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();  
        for(int i=0;i<n;i++){
            if(board[i][0]=='O'){
                change(board,i,0);
            }
            if(board[i][m-1]=='O'){
                change(board,i,m-1);
            }
        }    
        for(int j=0;j<m;j++){
            if(board[0][j]=='O'){
                change(board,0,j);
            }
            if(board[n-1][j]=='O'){
                change(board,n-1,j);
            }
        }    
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O'){
                    board[i][j]='X';
                }
                else if(board[i][j]=='A'){
                    board[i][j]='O';
                }
            }
        }          

    }
};