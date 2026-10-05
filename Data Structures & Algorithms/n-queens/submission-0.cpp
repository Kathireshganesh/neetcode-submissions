class Solution {
public:
     vector<vector<string>> ans;

     bool isSafe(vector<string>& board,int row,int col,int n){
        for(int r=0;r<row;r++){
            if(board[r][col]=='Q')
                return false;
        }
            for(int r=row-1,c=col-1;r>=0 && c>=0 ;r--,c--){
                if(board[r][c]=='Q')
                  return false;
            }

            for(int r=row-1,c=col+1;r>=0 && c<n;r--,c++){
                if(board[r][c]=='Q')
                   return false;
            }
            return true;
        }
     
    void backtrack(int row,vector<string>& board,int n){

        if(row==n){
            ans.push_back(board);
            return;
        }

        for(int col=0;col<n;col++){
            if(!isSafe(board,row,col,n))
               continue;

            board[row][col]='Q';

            backtrack(row+1,board,n);

            board[row][col]='.';
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n,string(n,'.'));

        backtrack(0,board,n);

        return ans;
    }
};
