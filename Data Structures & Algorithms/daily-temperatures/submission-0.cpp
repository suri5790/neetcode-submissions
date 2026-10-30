class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temps) {
        using namespace std;
        
        int n = temps.size();
        vector<int> results(n, 0); // Initialize with 0
        stack<int> stack;          // Stores indices of future warmer days

        // Traverse from right to left
        for (int i = n - 1; i >= 0; i--) {
            // Pop elements that are colder than or equal to the current day
            while (!stack.empty() && temps[stack.top()] <= temps[i]) {
                stack.pop();
            }
            
            // If stack is not empty, the top element is the next warmer day
            if (!stack.empty()) {
                results[i] = stack.top() - i;
            }
            
            // Push current index as a future candidate
            stack.push(i);
        }
        
        return results;
    }
};
