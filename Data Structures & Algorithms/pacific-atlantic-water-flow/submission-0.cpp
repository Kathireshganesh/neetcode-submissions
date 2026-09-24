class Solution {
   public:
    int rows, cols;

    void solve(vector<vector<int>>& heights, vector<vector<bool>>& visited, int r, int c) {
        visited[r][c] = true;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        for (int k = 0; k < 4; k++) {
            int nr = r + dr[k];
            int nc = c + dc[k];

            if (nr < 0 || nr >= rows || nc < 0 || nc >= cols) continue;
            if (visited[nr][nc]) continue;
            if (heights[nr][nc] < heights[r][c]) continue;

            solve(heights, visited, nr, nc);
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        rows = heights.size();
        cols = heights[0].size();

        vector<vector<bool>> atlantic(rows, vector<bool>(cols, false));

        vector<vector<bool>> pacific(rows, vector<bool>(cols, false));

        for (int col = 0; col < cols; col++) {
            solve(heights, pacific, 0, col);
        }

        for (int row = 0; row < rows; row++) {
            solve(heights, pacific, row, 0);
        }

        for (int col = 0; col < cols; col++) {
            solve(heights, atlantic, rows - 1, col);
        }

        for (int row = 0; row < rows; row++) {
            solve(heights,atlantic, row, cols - 1);
        }

        vector<vector<int>> ans;

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (pacific[r][c] && atlantic[r][c]) ans.push_back({r, c});
            }
        }

        return ans;
    }
};
