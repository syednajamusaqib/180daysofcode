class Solution {
public:
    int k[3] = {0,-1,1};
    int dp[71][71][71];
    int solve(vector<vector<int>>& grid,int i, int c1,int c2, int m, int n){
        // Base Cases
        if(i == m || c1 < 0 || c2 < 0 || c1 >= n || c2 >= n)  
            return 0;
        if(dp[i][c1][c2] != -1)
            return dp[i][c1][c2];
        
        int ans = 0;

        for(int x = 0; x < 3; x++){
            for(int y = 0; y < 3; y++){
                // 9 Recursive calls for two robots
                ans = max(ans,solve(grid,i+1,c1 + k[x], c2 + k[y], m, n));
            }
        }

        // Handling the case where both robots share common cell
        ans += (c1 == c2) ? (grid[i][c1]) : grid[i][c1] + grid[i][c2];

        return dp[i][c1][c2] = ans;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));
        int rows = grid.size();
        int cols = grid[0].size();
        return solve(grid,0,0,cols-1,rows,cols);
    }
};
