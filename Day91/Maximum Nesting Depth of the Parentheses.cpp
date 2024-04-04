// Using Stack O(N) Space                                        
class Solution {
public:
    int maxDepth(string s) {
        stack<char> st;
        int ans = 0;
        
        for(auto ch: s){
            if(ch == '(')
                st.push(ch);
            else if(ch == ')')
                st.pop();
            ans = max(ans, (int)st.size());
        }
        return ans;
    }
};

// Constant Space

class Solution {
public:
    int maxDepth(string s) {
        int ans = 0;
        int count = 0;

        for(int i = 0; i < s.size(); i++){
            if(s[i] == '('){
                count++;
                ans = max(ans,count);
            }else if(s[i] == ')'){
                count--;
            }
        }
        return ans;
    }
};
