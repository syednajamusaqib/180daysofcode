class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n,vector<bool>(n,false));
        int count = 0;

        for(int L = 1; L <= n; L++){
            for(int i = 0; i + L - 1 < n; i++){
                int j = i + L - 1;
                if(i == j){ // For 1 size Substrngs
                    dp[i][j] = true;
                }else if(i+1 == j){ // For 2 size Substrings
                    dp[i][j] = (s[i] == s[j]);
                }else{
                    dp[i][j] = (s[i] == s[j] && dp[i+1][j-1]);
                }

                if(dp[i][j]) count++;
            }
        }
        return count;
    }
};
