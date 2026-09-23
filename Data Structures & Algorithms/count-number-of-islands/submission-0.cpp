class Solution {
public:
    void solve(vector<vector<char>>& grid,int row,int col){
          
        int r=grid.size();
        int c=grid[0].size();

        if(row<0 || row>=r || col<0 ||col>=c||grid[row][col]=='0') return;

        grid[row][col]='0';

        solve(grid,row-1,col);
        solve(grid,row+1,col);
        solve(grid,row,col-1);
        solve(grid,row,col+1);


        
    }
    int numIslands(vector<vector<char>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        int island=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]=='1'){
                    island++;
                    solve(grid,i,j);
                }
            }
        }
        return island;
    }
};
