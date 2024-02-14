class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        int pos = 0; // First positive element index
        int neg = 1; // First Negative element index
        for(int i=0;i<n;i++){
            if(nums[i]>0){ // If positive element is found
                ans[pos] = nums[i]; // Moving that element to its pos index
                pos+=2; // Incrementing pos by two because next positive element will be two indexes ahead of previous
            }
            else{
                ans[neg] = nums[i];
                neg+=2;
            }
        }
        return ans;
    }
};
