class Solution {
public:

     int dfs(vector<vector<int>>& grid,int r,int c){
          int rows=grid.size();
          int cols=grid[0].size();

        if(r<0 || c<0 || r>=rows || c>= cols ||grid[r][c]==0){
            return 0;
        }
        int area=1;
        grid[r][c]=0;

       int dr[]={-1,1,0,0};
       int dc[]={0,0,-1,1};
        
        for(int i=0;i<4;i++)
          area+=dfs(grid,r+dr[i],c+dc[i]);

        return area;

     }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rows=grid.size();
        int cols=grid[0].size();
        int area=0;
        for(int r=0;r<rows;r++){
            for(int c=0;c<cols;c++){
                if(grid[r][c]==1){
                   int ans=dfs(grid,r,c);
                   area=max(area,ans);
                }
            }

        }
    return area;
    }
};
