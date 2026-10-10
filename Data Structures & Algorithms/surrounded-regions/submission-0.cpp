class Solution {
public:
    int r,c;
    void dfs(vector<vector<char>>& board,int row,int col){
            if(row<0 || col<0 || row>=r || col>=c) return;

        if(board[row][col]!='O')
            return ;

        board[row][col]='K';

        dfs(board,row-1,col);
        dfs(board,row+1,col);
        dfs(board,row,col-1);
        dfs(board,row,col+1);
    }

    void solve(vector<vector<char>>& board) {
        
         r=board.size();
         c=board[0].size();

        for(int col=0;col<c;col++){
            dfs(board,0,col);
            dfs(board,r-1,col);

        }

        for(int row=0;row<r;row++){
            dfs(board,row,0);
            dfs(board,row,c-1);
        }
        
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
               if(board[i][j]=='O')
                  board[i][j]='X';
               else if(board[i][j]=='K')
                  board[i][j]='O';
                   
            }
        }
    }
};
