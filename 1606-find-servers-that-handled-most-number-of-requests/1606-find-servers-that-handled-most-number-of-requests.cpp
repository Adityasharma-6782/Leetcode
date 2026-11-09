
class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival,
                               vector<int>& load) {

        set<int> available;

        for (int i = 0; i < k; i++) {
            available.insert(i);
        }

        // {finish time, server ID}
        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > busy;

        vector<int> count(k, 0);

        for (int i = 0; i < arrival.size(); i++) {

            // Release servers whose requests are completed
            while (!busy.empty() &&
                   busy.top().first <= arrival[i]) {

                int server = busy.top().second;
                busy.pop();

                available.insert(server);
            }

            // All servers are busy
            if (available.empty()) {
                continue;
            }

            // Preferred server
            int target = i % k;

            // Find first available server >= target
            auto it = available.lower_bound(target);

            // Wrap around if necessary
            if (it == available.end()) {
                it = available.begin();
            }

            int server = *it;

            // Assign request
            available.erase(it);

            count[server]++;

            int finishTime = arrival[i] + load[i];

            busy.push({finishTime, server});
        }

        // Find maximum number of handled requests
        int maxCount = *max_element(count.begin(), count.end());

        vector<int> result;

        for (int i = 0; i < k; i++) {
            if (count[i] == maxCount) {
                result.push_back(i);
            }
        }

        return result;
    }
};
