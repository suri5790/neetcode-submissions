class Solution {
public:

    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>sub;
 for(int i=0;i<n;i++){
    auto it=lower_bound(sub.begin(),sub.end(),nums[i]);
    if(it==sub.end()){
        sub.push_back(nums[i]);
    }
    else {
        *it=nums[i];
    }
 }
        return sub.size();
        
    }
};