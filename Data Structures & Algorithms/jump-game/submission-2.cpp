class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxi=0;if(nums.size()==1)return true;if(nums[0]==0)return false;
        for(int i=0;i<nums.size();i++){
               if(maxi<i)return false;
            maxi=max(maxi,i+nums[i]);
         
            if(maxi==nums.size()-1)return true;
        }
        return maxi>=nums.size()-1;
    }
};
