class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n = tokens.size();
        int ans = 0;
        int score = 0;
        sort(tokens.begin(),tokens.end());
        int i = 0;
        int j = n - 1;

        while(i <= j){
            // Either we can sacrifice power to gain score
            if(power >= tokens[i]){
                power -= tokens[i];
                score++;
                i++;
                ans = max(ans,score);
            } // or we can increase our power aand sacrifice score
            else if(score > 0){
                power += tokens[j];
                score -= 1;
                j--;
            }else{
                return ans;
            }
        }
        return ans;
    }
};
