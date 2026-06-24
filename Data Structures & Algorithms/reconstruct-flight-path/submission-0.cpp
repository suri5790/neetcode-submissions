class Solution {
public:
    unordered_map<string, vector<string>> adj;
    vector<string> ans;

    void dfs(const string& node) {
        auto& vec = adj[node];
        while (!vec.empty()) {
            string next = vec.back();
            vec.pop_back();
            dfs(next);
        }
        ans.push_back(node);
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for (auto& t : tickets) {
            adj[t[0]].push_back(t[1]);
        }

        // Sort in reverse so we can use pop_back() to get smallest lexical airport
        for (auto& [node, vec] : adj) {
            sort(vec.rbegin(), vec.rend());
        }

        dfs("JFK");
        reverse(ans.begin(), ans.end());
        return ans;
    }
};