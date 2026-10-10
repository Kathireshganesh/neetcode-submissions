class Solution {
public:
   int r,c;
   void solve(vector<vector<int>>& heights,vector<vector<bool>>& visited,int row,int col){
             

             if(row < 0 || col<0|| row >=r || col >= c ) return;
             if(visited[row][col]) return;

             visited[row][col]=true;
             int dr[]={-1,1,0,0};
             int dc[]={0,0,-1,1};

             for(int i=0;i<4;i++){
                int nr=row+dr[i];
                int nc=col+dc[i];

                if (nr < 0 || nc < 0 || nr >= r || nc >= c)
                continue;
                if(visited[nr][nc]) continue;
                if(heights[nr][nc] < heights[row][col]) continue;

                solve(heights,visited,nr,nc);
             } 
   }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        r=heights.size();
        c=heights[0].size();
        vector<vector<bool>> pacific(r,vector<bool>(c,false));
        vector<vector<bool>> atlantic(r,vector<bool>(c,false));

        for(int col=0;col<c;col++){
            solve(heights,pacific,0,col);
            solve(heights,atlantic,r-1,col);
        }

        for(int row=0;row<r;row++){
            solve(heights,pacific,row,0);
            solve(heights,atlantic,row,c-1);
        }
       vector<vector<int>> ans;
      for(int row=0;row<r;row++){
        for(int col=0;col<c;col++){
            if(pacific[row][col] && atlantic[row][col])
                ans.push_back({row,col});
        }
      }
      return ans;

    }
};
