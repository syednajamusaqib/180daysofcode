class Solution {
public:
    int mod = 1e9+7;
    int dp[51][51][51];
    int solve(int m, int n, int move, int i, int j){
        if(i>=m || i<0 || j>=n || j<0)
            return 1;
        if(move <= 0) 
            return 0;

        if(dp[i][j][move] != -1)
            return dp[i][j][move];

        long res = 0;
        res += solve(m,n,move-1,i+1,j);
        res += solve(m,n,move-1,i-1,j);
        res += solve(m,n,move-1,i,j+1);
        res += solve(m,n,move-1,i,j-1);

        return dp[i][j][move] = res % mod;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(dp,-1,sizeof(dp));
        return solve(m,n,maxMove,startRow,startColumn) % mod;
    }
};
