class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp; // map to store freq of each element
        int ans = 0; // variable to store result

        for(int i = 0; i < n; i++){ // Updating map values
            mp[nums[i]]++;
        }
        
        // Iterting over map and looking for min number of operations
        for(auto it: mp){
            int freq = it.second; // freq of current element stored in map
            if(freq == 1) return -1; // if freq is 1 we will simply return -1
            else{
                ans += ceil(double(freq) / 3); // ceil will give min number of oper
            }
        }
        return ans;
    }
};
