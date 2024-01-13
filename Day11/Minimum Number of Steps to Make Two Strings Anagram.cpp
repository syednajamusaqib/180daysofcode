class Solution {
public:
    int minSteps(string s, string t) {
        int mp[26] = {0}; 
        int ans = 0;

        for(auto ch: s) mp[ch-'a']++; 
        for(auto ch: t){
            if(mp[ch-'a'] != 0){
                mp[ch-'a']--;
            }
        }
        for(auto it: mp){ 
            ans += it;
        }
        return ans;
    }
};
