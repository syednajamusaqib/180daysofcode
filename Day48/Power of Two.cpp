class Solution {
public:
    bool isPowerOfTwo(int n) {
        int count = 0;
        if(n<=0) return false;
        // Any number which is power of two has only one set bit(1)
        while(n){
            if(n&1) count++;
            n = n >> 1;
        }
        if(count==1) return true; // if count is 1 number is power of two
        else return false;
    }
};
