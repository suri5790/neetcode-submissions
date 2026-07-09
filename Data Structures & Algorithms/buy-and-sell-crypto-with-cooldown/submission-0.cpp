class Solution {
public:


     int fun(int i,int b,vector<vector<int>>&v,int n,vector<int>&p){
            
            if(i>=n)return 0;
            if(v[i][b]!=-1)return v[i][b];
            int x,y;
            if(b==0){
                 x=(-p[i])+fun(i+1,1,v,n,p);
                 y=fun(i+1,0,v,n,p);
            }
            else {
                 x=(p[i])+fun(i+2,0,v,n,p);
                 y=fun(i+1,1,v,n,p);
            }

            return v[i][b]=max(x,y);
        }
    int maxProfit(vector<int>& p) {

   int n=p.size();
       vector<vector<int>>v(n + 1,  vector<int>(2, -1));
        int res=fun(0,0,v,n,p);
        return res;
    }
};