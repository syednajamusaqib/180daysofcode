// Function to find the largest divisible subset from a given set of integers
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        // Sorting the input array in ascending order
        sort(nums.begin(), nums.end());
        int n = nums.size();

        // Initialize vectors to keep track of subset sizes and previous elements
        // subsetSize[i] stores the size of the largest subset that ends with nums[i]
        // prevIndex[i] stores the index of the previous element in the largest subset ending with nums[i]
        vector<int> subsetSize(n, 1); 
        vector<int> prevIndex(n, -1);  

        int maxIndex = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                // Check if nums[i] is divisible by nums[j]
                if (nums[i] % nums[j] == 0 && subsetSize[i] < subsetSize[j] + 1) {
                    // Update subset size and previous element index
                    subsetSize[i] = subsetSize[j] + 1;
                    prevIndex[i] = j;
                }
            }
            // Update index of maximum size subset found so far
            if (subsetSize[i] > subsetSize[maxIndex]) {
                maxIndex = i;
            }
        }

        // Reconstructing the largest divisible subset using previous element indices
        vector<int> result;
        for (int i = maxIndex; i != -1; i = prevIndex[i]) {
            result.insert(result.begin(), nums[i]);
        }

        // Return the largest divisible subset
        return result;
    }
};
