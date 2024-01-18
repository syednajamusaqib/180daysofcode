class Solution {
public:
    int climbStairs(int n) {
        int first = 0;
        int second = 1;
        int next = first + second;

        for(int i = 0; i < n; i++){
            next = first + second;
            first = second;
            second = next;
        }
        return second;
    }
};
