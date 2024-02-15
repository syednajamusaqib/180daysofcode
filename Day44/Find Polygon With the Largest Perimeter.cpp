class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(begin(nums),end(nums));
        typedef long long ll;
        ll prefix = nums[0] + nums[1];
        ll result = 0;
        for(int i = 2; i < nums.size(); i++){
            if(prefix > nums[i])
                result = max(result, prefix + nums[i]);
            
            prefix += nums[i];
        }

        return (result == 0) ? -1 : result;

    }
};
