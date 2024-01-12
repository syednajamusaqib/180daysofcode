class Solution {
public:
    bool isVowel(char ch){
        if(ch == 'a' || ch == 'A' || ch == 'e' || ch == 'E' || ch == 'i' ||
           ch == 'I' || ch == 'o' || ch == 'O' || ch == 'u' || ch == 'U'){
            return true;
        }
        return false;
    }
    bool halvesAreAlike(string s) {
        int n = s.size();
        int half = n / 2;
        int count1 = 0, count2 = 0;
        for(int i = 0; i < half; i++){
            if(isVowel(s[i])){
                count1++;
            }
        }
        for(int i = half; i < n; i++){
            if(isVowel(s[i])){
                count2++;
            }
        }
        return (count1 == count2);
    }
};
