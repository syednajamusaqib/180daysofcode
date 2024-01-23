class Solution {
public:
    unordered_map<string,int> mp;
    bool hasDuplicate(string& arr, string& temp){
        vector<int> mp(26,0);

        for(auto ch: arr){
            if(mp[ch-'a'] > 0) return true;
            mp[ch-'a']++;
        }

        for(auto ch: temp){
            if(mp[ch-'a'] > 0) return true;
        }

        return false;
    }

    int solve(vector<string>& arr, string temp,int i, int n){
        // Base Case
        if(i >= n) return temp.size();

        int take = 0; // If we can take present string
        int skip = 0; // If we can skip present string

        if(mp.find(temp) != mp.end()){
            return mp[temp];
        }
        if(hasDuplicate(arr[i],temp)){
            // If there are duplicates in both strings we can just skip
            skip = solve(arr,temp,i+1,n);
        }else{
            // Either we can skip or we can take present string
            skip = solve(arr,temp,i+1,n);
            // If we take string then we must concat temp with string
            take = solve(arr,temp+arr[i],i+1,n);
        }

        return mp[temp] = max(take,skip);
    }
    int maxLength(vector<string>& arr) {
        string temp = "";
        mp.clear();
        int i = 0;
        int n = arr.size();
        return solve(arr,temp,i,n);
    }
};
