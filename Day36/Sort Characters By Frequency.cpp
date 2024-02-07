class Solution {
public:
    typedef pair<char,int> p;
    // Comparator for Priority Queue
    struct lambda{
        bool operator()(p p1, p p2){
            return p1.second < p2.second;
        }
    };

    string frequencySort(string s) {
        priority_queue<p, vector<p>, lambda> pq;
        // Storing Frequency of characters in map
        unordered_map<char,int> mp;
        for(char ch: s)
            mp[ch]++;
        // Filling Priority Queue in sorted fashion
        for(auto it: mp)
            pq.push({it.first,it.second});

        // Generating Result 
        string result = "";
        while(!pq.empty()){
            p temp = pq.top();
            pq.pop();

            result += string(temp.second,temp.first);
        }
        return result;
    }
};
