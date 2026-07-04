class Solution {
public:
    string foreignDictionary(vector<string>& words) {

        vector<unordered_set<int>> adj(26);
        vector<int> indegree(26, 0);
        vector<bool> present(26, false);

        // Mark all characters that appear
        for (auto &word : words) {
            for (char c : word)
                present[c - 'a'] = true;
        }

        // Build graph
        for (int i = 1; i < words.size(); i++) {

            string &s = words[i - 1];
            string &t = words[i];

            int len = min(s.size(), t.size());
            bool found = false;

            for (int j = 0; j < len; j++) {

                if (s[j] != t[j]) {

                    int u = s[j] - 'a';
                    int v = t[j] - 'a';

                    if (adj[u].insert(v).second) {
                        indegree[v]++;
                    }

                    found = true;
                    break;
                }
            }

            // Invalid prefix case
            if (!found && s.size() > t.size())
                return "";
        }

        queue<int> q;

        int totalChars = 0;

        for (int i = 0; i < 26; i++) {
            if (present[i]) {
                totalChars++;

                if (indegree[i] == 0)
                    q.push(i);
            }
        }

        string ans;

        while (!q.empty()) {

            int u = q.front();
            q.pop();

            ans += char(u + 'a');

            for (int v : adj[u]) {

                indegree[v]--;

                if (indegree[v] == 0)
                    q.push(v);
            }
        }

        // Cycle exists
        if (ans.size() != totalChars)
            return "";

        return ans;
    }
};