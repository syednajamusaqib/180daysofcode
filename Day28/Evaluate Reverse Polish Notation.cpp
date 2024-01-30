class Solution {
public:

    int solve(int a, int b, string oper){
        int result;
        if(oper == "+")
            result = (a + b);
        if(oper == "-")
            result = (a - b);
        if(oper == "*")
            result = ((long)a * (long)b);
        if(oper == "/")
            result = (a / b);
        
        return result;
    }

    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(string token: tokens){
            if(token == "+" || token == "-" || token == "*" || token == "/"){
                int opr1 = st.top();
                st.pop();

                int opr2 = st.top();
                st.pop();

                int ans = solve(opr2,opr1,token);

                st.push(ans);
            }else{
                st.push(stoi(token));
            }
        }
        return st.top();
    }
};
