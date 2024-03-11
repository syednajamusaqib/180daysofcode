class Solution {
public:
    string customSortString(string order, string s) {
        vector<int> freq(26);

        for(int i = 0;i < s.size();i++){
            freq[s[i]-'a']++;
        }

        string ans ="";
        for(int i = 0;i < order.size();i++){
            ans.append(freq[order[i]-'a'], order[i]);
            freq[order[i]-'a']=0;
        }

        for(int i = 0;i < 26;i++){
            ans.append(freq[i], 'a'+i); 
        }
        return ans; 
    }
};
