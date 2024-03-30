class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int i = 0;
        int j = 0;
        int n = nums.size();
        int ans = 0;
        unordered_map<int, int> mp;

        // Count of subarrays with at most k distinct elements
        int countAtMostK = 0;

        while (j < n) {
            // Expand the window until we have at most k distinct elements
            mp[nums[j]]++;

            // Shrink the window until we have exactly k distinct elements
            while (mp.size() > k) {
                mp[nums[i]]--;
                if (mp[nums[i]] == 0) {
                    mp.erase(nums[i]);
                }
                i++;
                countAtMostK = 0; // Reset countAtMostK as the window changes
            }

            // Count the number of subarrays with at most k distinct elements
            while (mp.size() == k && mp[nums[i]] > 1) {
                mp[nums[i]]--;
                i++;
                countAtMostK++;
            }

            // If the window has exactly k distinct elements
            if (mp.size() == k) {
                ans += countAtMostK + 1;
            }

            j++;
        }

        return ans;
    }
};
