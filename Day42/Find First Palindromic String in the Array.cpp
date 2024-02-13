class Solution {
public:
    bool isPal(string s){
        int n = s.size();
        int start = 0;
        int end = n - 1;

        while(start < end){
            if(s[start] != s[end])
                return 0;
            start++;
            end--;
        }
        return 1;
    }
    string firstPalindrome(vector<string>& words) {
        int n = words.size();
        string ans = "";
        for(int i = 0; i < n; i++){
            if(isPal(words[i])){
                ans = words[i];
                break;

            }
        }
        return ans;
    }
};
