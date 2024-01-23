/* ----- https://leetcode.com/problems/maximum-profit-in-job-scheduling ----- */

#include <iostream>
#include <vector>

using namespace std;

class job {
   public:
    int start_time;
    int end_time;
    int profit;

    job(int start, int end, int profit) : start_time(start), end_time(end), profit(profit){};

    friend ostream& operator<<(ostream& os, const job& job) {
        os << "[" << job.start_time << " - " << job.end_time << " : " << job.profit << "]";
        return os;
    }
};

class Solution {
   public:
    int jobScheduling(vector<int>& start_time, vector<int>& end_time, vector<int>& profit) {
        int n = start_time.size();
        vector<job> jobs;
        jobs.reserve(n);
        for (int i = 0; i < n; i++) {
            jobs.push_back(job(start_time[i], end_time[i], profit[i]));
        }

        // sort jobs by end time, because we would like to do a binary search on end_time
        // during dp
        sort(jobs.begin(), jobs.end(), [](const job& a, const job& b) {
            if (a.end_time == b.end_time) {
                return a.start_time < b.start_time;
            }
            return a.end_time < b.end_time;
        });

        // for (auto each : jobs) {
        //     cout << each << ", ";
        // }
        // std::cout << "\n";

        // dp[i] denotes the maximum profit one can obtain using all the intervals till ith
        vector<int> dp(n, 0);

        dp[0] = jobs[0].profit;
        for (int i = 1; i < n; i++) {
            // i won't use this interval
            dp[i] = dp[i - 1];

            // i will use this interval
            // then i need to know what is the latest_inteval before this
            // that does not overlap with this interval
            int latest_possible_interval = upper_bound(jobs, i - 1, jobs[i].start_time);
            int profit_till_latest_possible_interval =
                latest_possible_interval == -1 ? 0 : dp[latest_possible_interval];

            // max of whether i use this or don't use this
            dp[i] = max(dp[i], profit_till_latest_possible_interval + jobs[i].profit);
        }

        return dp[n - 1];
    }

    // Find the job that is the latest job that till h whose end time < start time
    int upper_bound(vector<job>& jobs, int h, int start_time) {
        int l = 0;
        while (l <= h) {
            int mid = l + (h - l) / 2;
            if (jobs[mid].end_time <= start_time) {
                l = mid + 1;
            } else {
                h = mid - 1;
            }
        }
        return l - 1;
    }
};

int main() {
    Solution s;
    vector<int> start_time = {1, 1, 1};
    vector<int> end_time = {2, 3, 4};
    vector<int> profit = {5, 6, 4};
    cout << s.jobScheduling(start_time, end_time, profit);
}