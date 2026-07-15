#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        int n = s.length();
        vector<vector<string>> result;
        vector<string> currentPath;
        
        // Step 1: Initialize the DP table with false
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        
        // Step 2: Populate the DP table using Center Expansion
        for (int i = 0; i < n; i++) {
            // Odd length palindromes (centered at character i)
            expandFromCenter(s, i, i, dp);
            
            // Even length palindromes (centered between i and i+1)
            expandFromCenter(s, i, i + 1, dp);
        }
        
        // Step 3: Backtrack to find all partitions
        backtrack(0, s, dp, currentPath, result);
        
        return result;
    }

private:
    void expandFromCenter(const string& s, int left, int right, vector<vector<bool>>& dp) {
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            dp[left][right] = true;
            left--;
            right++;
        }
    }

    void backtrack(int start, const string& s, const vector<vector<bool>>& dp,
                   vector<string>& currentPath, vector<vector<string>>& result) {
        if (start == s.length()) {
            result.push_back(currentPath);
            return;
        }
        
        for (int end = start; end < s.length(); end++) {
            if (dp[start][end]) {
                currentPath.push_back(s.substr(start, end - start + 1));
                backtrack(end + 1, s, dp, currentPath, result);
                currentPath.pop_back(); // Backtrack
            }
        }
    }
};