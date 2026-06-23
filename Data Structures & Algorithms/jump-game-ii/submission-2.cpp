class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 0;

        int cnt = 1;
        int maxi = nums[0];   // current reachable boundary

        if(maxi >= n - 1) return cnt;

        for(int i = 1; i < n; ) {
            int newmaxi = maxi;
            int maxind = i;

            for(int j = i; j <= maxi && j < n; j++) {
                if(j + nums[j] > newmaxi) {
                    newmaxi = j + nums[j];
                    maxind = j;
                }
            }

            cnt++;

            if(newmaxi >= n - 1)
                return cnt;

            maxi = newmaxi;
            i = maxind + 1;
        }

        return cnt;
    }
};