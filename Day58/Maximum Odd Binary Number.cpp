class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int n = s.size();
        string ans = string(n,'0');
        int count_1 = count(s.begin(),s.end(),'1');
        int i = 0;

        while(count_1 > 1){
            ans[i] = '1';
            i++;
            count_1--;
        }
        ans[n-1] = '1';
        return ans;
    }
};
