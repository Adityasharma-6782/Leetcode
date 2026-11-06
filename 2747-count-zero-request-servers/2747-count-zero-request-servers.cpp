
class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs,
                             int x, vector<int>& queries) {

        // Sort logs by request time
        sort(logs.begin(), logs.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] < b[1];
             });

        int m = queries.size();

        vector<pair<int, int>> sortedQueries;

        for (int i = 0; i < m; i++) {
            sortedQueries.push_back({queries[i], i});
        }

        sort(sortedQueries.begin(), sortedQueries.end());

        vector<int> freq(n + 1, 0);
        vector<int> ans(m);

        int left = 0, right = 0;
        int active = 0;

        for (auto [q, idx] : sortedQueries) {

            int start = q - x;

            // Include logs up to query time
            while (right < logs.size() && logs[right][1] <= q) {

                int id = logs[right][0];

                if (freq[id] == 0)
                    active++;

                freq[id]++;
                right++;
            }

            // Remove logs before the starting time
            while (left < right && logs[left][1] < start) {

                int id = logs[left][0];

                freq[id]--;

                if (freq[id] == 0)
                    active--;

                left++;
            }

            ans[idx] = n - active;
        }

        return ans;
    }
};
