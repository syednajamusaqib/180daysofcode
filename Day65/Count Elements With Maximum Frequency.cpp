class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> freqMap;  
        int maxFreq = 0;  

        for (int num : nums) {
            freqMap[num]++;
            maxFreq = max(maxFreq, freqMap[num]); 
        }

        int totalCount = 0;  
        for (auto& pair : freqMap) {
            if (pair.second == maxFreq) {
                totalCount += maxFreq;
            }
        }
        return totalCount;
    }
};
