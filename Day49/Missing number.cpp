class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int x=0;
        for(auto ele :nums){
            x = x ^ ele;
        }
        for(int i = 0;i <= nums.size();i++){
            x = x ^ i;
        }
        return x;
    }
};
