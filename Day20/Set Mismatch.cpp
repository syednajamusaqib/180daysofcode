class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<int> check(n+1,0);

        int missing = 0;
        int duplicate = 0;

        for(auto num: nums){
            check[num]++;
        }

        for(int i = 1; i < check.size(); i++){
            if(check[i] == 2) duplicate = i;
            if(check[i] == 0) missing = i;
        }

        return {duplicate,missing};
    }
};
