class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k <= 1) return 0;
        int ans = 0;
        int i = 0;
        int j = 0;
        int n = nums.size();
        int product = 1;
        while(j < n){
            // Calculations
            product *= nums[j];
            // Slide Window
            while(product >= k){
                // Remove Calculations of i
                product /= nums[i];
                // Slide Window
                i++;
            }
            ans += j - i + 1;
            j++;
        }
        return ans;
    }
};
