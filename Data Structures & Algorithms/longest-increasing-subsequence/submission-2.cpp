class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>v;v.push_back(nums[0]);
        for(int i=1;i<nums.size();i++){
            auto it=lower_bound(v.begin(),v.end(),nums[i]);
            if(it!=v.end()){
                 *it=nums[i];
            }
           else v.push_back(nums[i]);
        }
        return v.size();
    }
};
