class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> mp;
        unordered_set<int> st;
        // Store Frequency of each element in map
        for(auto it: arr) mp[it]++;
        // Store value of map in set
        for(auto x: mp) st.insert(x.second);
        // If both map and set have equal size it means 
        // There are unique number of occurences in array
        return mp.size() == st.size();
    }
};
