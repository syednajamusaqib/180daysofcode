
class Solution {
private:
    int dp[50000];
    int f(int idx, vector<vector<int>> &jobs) {
        //base cases
        if (idx >= jobs.size())  return 0;
        if (dp[idx] != -1)  return dp[idx];

        int notTake = f(idx + 1, jobs);
        vector<int> v = {jobs[idx][1], 0, 0};
        int nextIdx = lower_bound(jobs.begin(), jobs.end(), v) - jobs.begin();
        int take = jobs[idx][2] + f(nextIdx, jobs);
        return dp[idx] = max(take, notTake);
    }
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int>> jobs;
        for (int i = 0; i < profit.size(); ++i) jobs.push_back({startTime[i], endTime[i], profit[i]});
        sort(jobs.begin(), jobs.end());

        memset(dp, -1, sizeof(dp));
        return f(0, jobs);
    }
};
