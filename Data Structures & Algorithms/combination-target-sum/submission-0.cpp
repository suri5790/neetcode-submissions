class Solution {
public:
     void f(int tar,vector<vector<int>>&res,vector<int>& can,vector<int>&v,int i,int sum){
        if(sum>tar)return;
        if(i>=can.size()){if(sum==tar)res.push_back(v);return;}
        if(sum==tar){
            res.push_back(v);
            return ;
        }
        if(sum>tar)return ;
        v.push_back(can[i]);
        f(tar,res,can,v,i,sum+can[i]);
        v.pop_back();
        f(tar,res,can,v,i+1,sum);
        return ;

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
         vector<vector<int>>res;
        sort(candidates.begin(),candidates.end());
        vector<int>v;
        f(target,res,candidates,v,0,0);
        return res;
    }
};
