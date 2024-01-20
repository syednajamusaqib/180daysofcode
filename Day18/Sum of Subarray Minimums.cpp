class Solution {
public:
    vector<int> getNSL(vector<int>& arr,int n){
        vector<int> ans(n);
        stack<int> st;

        for(int i = 0; i < n; i++){
            if(st.empty()){
                ans[i] = -1;
            }else{
                while(!st.empty() && arr[st.top()] > arr[i]){
                    st.pop();
                }
                ans[i] = st.empty() ? -1 : st.top();
            }
            st.push(i);
        }
        return ans;
    }

    vector<int> getNSR(vector<int>& arr,int n){
        vector<int> ans(n);
        stack<int> st;

        for(int i = n - 1; i >= 0; i--){
            if(st.empty()){
                ans[i] = n;
            }else{
                while(!st.empty() && arr[st.top()] >= arr[i]){
                    st.pop();
                }
                ans[i] = st.empty() ? n : st.top();
            }
            st.push(i);
        }
        return ans;
    }


    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        int M = 1e9+7;
        vector<int> NSL = getNSL(arr,n);
        vector<int> NSR = getNSR(arr,n);
        int result = 0;
        for(int i = 0; i < n; i++){
            long long ls = i - NSL[i];
            long long rs = NSR[i] - i;

            long long sum = ls * rs;

            long long total = arr[i] * sum;

            result = (result + total) % M; 
        }

        return result;
    }
};
