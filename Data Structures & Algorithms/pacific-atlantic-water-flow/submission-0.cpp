class Solution {
public:
int m,n;
    int diri[4]={0,0,1,-1};
    int dirj[4]={1,-1,0,0};
    void dfs(int i,int j,vector<vector<bool>>& vis,vector<vector<int>>& h){
        if(vis[i][j])return ;
        vis[i][j]=true;
  
       for(int d=0;d<4;d++){
            int ni=i+diri[d],nj=j+dirj[d];
            if(ni>=0 && ni<m && nj>=0 && nj<n && !vis[ni][nj] && h[ni][nj]>=h[i][j]){
             
                dfs(ni,nj,vis,h);
            }
       }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& h) {
    m=h.size();n=h[0].size();
        vector<vector<bool>>vis1(m,vector<bool>(n,false));
        for(int i=0;i<n;i++){
            dfs(0,i,vis1,h);
        }
        for(int i=1;i<m;i++){
            dfs(i,0,vis1,h);
        }
         vector<vector<bool>>vis2(m,vector<bool>(n,false));
         for(int i=0;i<m;i++){
            dfs(i,n-1,vis2,h);
         }
         for(int i=0;i<n-1;i++){
            dfs(m-1,i,vis2,h);
         }
         vector<vector<int>>res;
         for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(vis1[i][j] && vis2[i][j]){
                    res.push_back({i,j});
                }
            }
         }
         return res;
    }
};
