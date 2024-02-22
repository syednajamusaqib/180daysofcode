class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> count(n + 1, 0); 

        for (const auto& relation : trust) {
            count[relation[0]]--;  
            count[relation[1]]++;  
        }
        for (int i = 1; i <= n; ++i) {      
            if (count[i] == n - 1) {
                return i;
            }
        }
        return -1;    
    }
};
