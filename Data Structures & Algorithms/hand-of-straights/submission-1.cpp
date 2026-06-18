class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if (n % groupSize != 0) return false;

        unordered_map<int, int> mp;
        for (int num : hand) mp[num]++;

        for (int num : hand) {
            // 1. Skip numbers we have already used in previous groups
            if (mp[num] == 0) continue;

            // 2. Find the absolute start of this consecutive sequence
            int cur = num;
            while (mp[cur - 1] > 0) {
                cur--;
            }

            // 3. Since we are at the start of a sequence, we MUST be able to form a group
            for (int i = cur; i <= cur + groupSize - 1; i++) {
                if (mp[i] > 0) {
                    mp[i]--;
                } else {
                    return false; // Missing a consecutive number
                }
            }
        }
        
        return true;
    }
};