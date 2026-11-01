class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int maxi = nums[0];
        
        // 1. Forward Pass
        int cur = 1;
        for(int i = 0; i < n; i++) {
            cur *= nums[i];
            maxi = max(maxi, cur);
            if (nums[i] == 0) cur = 1; // Reset AFTER updating maxi
        }
        
        // 2. Backward Pass
        cur = 1;
        for(int i = n - 1; i >= 0; i--) {
            cur *= nums[i];
            maxi = max(maxi, cur);
            if (nums[i] == 0) cur = 1; // Reset AFTER updating maxi
        }
        
        return maxi;
    }
};
