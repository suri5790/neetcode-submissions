class Solution {
public:
    int n;
    void f(vector<int>& nums,vector<vector<int>>&res,vector<int>&v,vector<bool>&vis,int i){
        if(v.size()==nums.size()){
            res.push_back(v);
            return ;
        }
        for(int in=0;in<nums.size();in++){
            if(vis[in%n]==false){
                vis[in%n]=true;
                v.push_back(nums[in%n]);
                f(nums,res,v,vis,(in+1)%n);
                v.pop_back();
                vis[in%n]=false;
            }
        }
        return ;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>res;
        vector<int>v;
        n=nums.size();
        vector<bool>vis(nums.size(),false);
        f(nums,res,v,vis,0);
        return res;
    }
};