class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>v(n,0);
        v[0]=1;
        for(int i=1;i<n;i++){
            int maxi=0,curi=nums[i];
            for(int j=0;j<i;j++){
                if(curi>nums[j]){
                    maxi=max(maxi,v[j]);
                }
            }
            v[i]=maxi+1;
        }
        return *max_element(v.begin(),v.end());
    }
};
