class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>> ans;
        vector<int> lostOne;
        vector<int> lostNone;
        int n = matches.size();
        int m = matches[0].size();
        map<int, int> loser;
        map<int, int> winner;

        for(int i = 0; i < n; i++){
            loser[matches[i][1]]++;
        }

        for(int i = 0; i < n; i++){
            winner[matches[i][0]]++;
        }

        // Checking for exactly one lost one's
        for(auto it: loser){
            if(it.second == 1){
                lostOne.push_back(it.first);
            }
        }
        // Checking for unbeatables
        for(auto it: winner){
            if(loser.find(it.first) == loser.end()){
                lostNone.push_back(it.first);
            }
        }

        ans.push_back(lostNone);
        ans.push_back(lostOne);
        return ans;
    }
};
