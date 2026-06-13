class Solution {
public:
    vector<vector<int>>res;
    void f(vector<int>& nums,vector<int>& v,int i){
   
        if(i>=nums.size()){
            res.push_back(v);
            return ;
        } 
       
        v.push_back(nums[i]);
        f(nums,v,i+1);
        v.pop_back();
        f(nums,v,i+1);
        return ;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
      vector<int>v;
     
      f(nums,v,0);
      return res;
    }
};
