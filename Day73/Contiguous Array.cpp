class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int zero = 0;
        int one  = 0;
        int ans = 0;
        int n = nums.size();
        unordered_map<int, int> mp;
        mp[0] = -1; 
        int j = 0;
        while(j < n){
            if(nums[j] == 0) zero++;
            else if(nums[j] == 1) one++;
            int diff = one - zero;
            
            if(mp.find(diff) != mp.end()) {
                ans = max(ans, j - mp[diff]);
            } else { 
                mp[diff] = j;
            }
            j++;
        }
        return ans;
    }
};
