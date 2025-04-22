class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        // Queue to perform BFS: stores (person, time) pairs
        queue<pair<int, int>> q;

        // Initially, person 0 and firstPerson know the secret at time 0
        q.push({0, 0});
        q.push({firstPerson, 0});

        // Build an adjacency list for all meetings
        // Each person maps to a list of (neighbor, meetingTime)
        unordered_map<int, vector<pair<int, int>>> mp;
        for (auto meeting : meetings) {
            int from = meeting[0];
            int to = meeting[1];
            int time = meeting[2];
            mp[from].push_back({to, time});
            mp[to].push_back({from, time});
        }

        // `visited[i]` indicates if person i knows the secret
        vector<bool> visited(n, false);

        // `whenknows[i]` keeps the earliest time person i learns the secret
        vector<int> whenknows(n, 1000);  // 1000 is an arbitrary large time (acts as "infinity")

        visited[0] = true;
        visited[firstPerson] = true;
        whenknows[0] = 0;
        whenknows[firstPerson] = 0;

        // Perform BFS to spread the secret to others
        while (!q.empty()) {
            auto top = q.front();
            q.pop();

            int node = top.first;
            int time = top.second;

            // Traverse all people this node has meetings with
            for (auto a : mp[node]) {
                int node2 = a.first;
                int time2 = a.second;

                // Spread the secret only if the meeting time is >= when this person learned it
                if (time2 >= time) {
                    // If the person hasn't been visited or can learn it earlier
                    if (!visited[node2] || whenknows[node2] > time2) {
                        visited[node2] = true;
                        q.push({node2, time2});
                        whenknows[node2] = time2;
                    }
                }
            }
        }

        // Collect all people who know the secret
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (visited[i]) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};
