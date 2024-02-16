class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int> mp;

        for(int x: arr) mp[x]++;

        vector<int> temp;

        for(auto it: mp){
            temp.push_back(it.second);
        }


        sort(begin(temp),end(temp));
        int removed = 0;
        for(int i = 0; i < temp.size();i++){
            removed += temp[i];
            if(removed > k)
                return temp.size() - i;
        }
        return 0;
    }
};
