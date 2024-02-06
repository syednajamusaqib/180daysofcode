class Solution {
public:
    string newWord(string str){
        vector<int> freq(26,0);

        for(auto ch: str){
            freq[ch-'a']++;
        }

        string result = "";

        for(int i = 0; i < 26; i++){
            if(freq[i] > 0){
                result += string(freq[i], i + 'a');
            }
        }
        return result;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        
        unordered_map<string,vector<string>> mp;

        for(int i = 0; i < strs.size(); i++){
            string word = newWord(strs[i]);

            mp[word].push_back(strs[i]);
        }
        for(auto str: mp){
            ans.push_back(str.second);
        }
        return ans;
    }
};
