
class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n = bank.size();
        int prevRowDevices = 0;
        int ans = 0;

        for(int i = 0; i < n; i++){
            int currRowDevices = 0;

            for(char ch: bank[i]){
                if(ch == '1') currRowDevices++;
            }

            ans += prevRowDevices * currRowDevices;
            if(currRowDevices != 0){
                prevRowDevices = currRowDevices;
            }
        }
        return ans;
    }
};
