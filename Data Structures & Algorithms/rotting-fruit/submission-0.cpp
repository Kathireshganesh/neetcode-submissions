class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        int fresh=0;
        queue<pair<int,int>> q;

        for(int row=0;row<r;row++){
            for(int col=0;col<c;col++){
                if(grid[row][col]==2){
                    q.push({row,col});
                }

                if(grid[row][col]==1)
                   fresh++;
            }
        }

        int dr[]={-1,1,0,0};
        int dc[]={0,0,-1,1};
        int minutes=0;
        while(!q.empty() && fresh>0){
            int n=q.size();
        
            for(int i=0;i<n;i++){
                auto [r1,c1]=q.front();
                q.pop();
              for(int k=0;k<4;k++){
                int nr=r1+dr[k];

                int nc=c1+dc[k];

                if(nr<0 || nr>=r || nc<0 || nc>=c) continue;

                if(grid[nr][nc]!=1) continue;
                q.push({nr,nc});
                grid[nr][nc]=2;

                fresh--;
            }


            }
            minutes++;
        }
        if(fresh>0)
           return -1;
        return minutes;
    }
};
