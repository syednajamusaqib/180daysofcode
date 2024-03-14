class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        unordered_map<int, int> mp;
        mp[0] = 1;
        int i = 0;
        int sum = 0;
        int count = 0;
        while(i < n){
            sum += nums[i];
            count += mp[sum - goal];
            mp[sum]++;
            i++;
        }
        return count;
    }
};
