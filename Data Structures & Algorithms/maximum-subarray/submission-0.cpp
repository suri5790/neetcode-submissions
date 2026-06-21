class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res=INT_MIN,cnt=0;
        for(int i=0;i<nums.size();i++){
            cnt+=nums[i];  res=max(cnt,res);
            if(cnt<0){
                cnt=0;
            }
          
        }
        return res;
    }
};
